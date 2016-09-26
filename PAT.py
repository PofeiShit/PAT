__author__ = 'ZKJ'
# -*- coding:utf-8 -*-
import urllib
import urllib2
import re

class Tool:
#	removeImg = re.compile('<img.*?>')
#	removeAddr = re.compile('<a.*?>|</a>')
	replaceLess = re.compile('&lt|&lt;')
	replaceGreat = re.compile('&gt|&gt;')
	replacePow = re.compile('<sup>')
	replaceDot = re.compile('<li>')
	removeTag = re.compile('<.*?>')
	def replace(self, x):
#		x = re.sub(self.removeImg, "", x)
#		x = re.sub(self.removeAddr, "", x)
		x = re.sub(self.replaceLess, u"小于", x)#特么"<"没用，用中文代替好了
		x = re.sub(self.replaceGreat, ">", x)
		x = re.sub(self.replacePow, "^", x)
		x = re.sub(self.replaceDot, ".", x)
		x = re.sub(self.removeTag, "", x)
		return x.strip()
class PAT:
	
	def __init__(self, baseUrl, level):
		self.baseURL = baseUrl
		self.Level = '/pat-'+level+'-practise'
		self.level = level
		self.tool = Tool()
		self.file = None;
	
	def getPage(self, questionNum):
		try:
			if questionNum is 0:
				url = self.baseURL + self.Level
			else:
				url = self.baseURL + self.Level + '/' + str(questionNum)
			request = urllib2.Request(url)
			response = urllib2.urlopen(request)
			pageCode = response.read().decode('utf-8')
			return pageCode
		except urllib2.URLError, e:
			if hasattr(e, "reason"):
				print u"连接PAT失败，错误原因", e.reason
				return None

	def getQuizNum(self):
		page = self.getPage(0)
#print page
		pattern = re.compile('<tr>.*?<td><a href="/contests/.*?>(.*?)</a></td>.*?</tr>', re.S)
		items = re.findall(pattern, page)
#print items[last -1]
		if items:
			return items[len(items) - 1]
		else:
			return None

	def getTitle(self, page):
		pattern = re.compile('<div id="body.*?>.*?<h1>(.*?)</h1>', re.S)
		result = re.search(pattern, page)
		if result:
#print result.group(1)
			return result.group(1).strip()
		else:
			return None

	def getContent(self, page):
		pattern = re.compile("<div id='problemContent'>(.*?)</div>",re.S)
#		result = re.search(pattern, page)
#if result:
#			print result.group(1)
#			return result.group(1).strip()
#		else:
#			return None
		items = re.findall(pattern, page)			
		contents = []
		for item in items:
			content = "\n"+self.tool.replace(item)+"\n"
			contents.append(content.encode('utf-8'))
		return contents
		
	def setFileTitle(self, title):
		if self.level is not 'a':
			self.file = open("B" + title + ".txt","w+")
		else:
			self.file = open("A" + title + ".txt", "w+")

	def writeData(self, contents):
		for item in contents:
			self.file.write(item)
		
	def start(self):
		pageNum = self.getQuizNum()
		title = self.getTitle(self.getPage(0))
		if pageNum == None:
			print "URL已失效，请重试"
			return 
		try:
			print title,"共有"+str(int(pageNum) - 1000)+"题"
			for i in range(1001, int(pageNum) + 1):
				print "正在写入题"+str(i)
				page = self.getPage(i)			
				title = self.getTitle(page)
				self.setFileTitle(title)
				contents = self.getContent(page)
				self.writeData(contents)
				
		except IOError, e:
			print "写入异常,原因"+e.message
		finally:
			print "写入任务完成"
#	print item

baseURL = 'http://www.patest.cn/contests'
level = raw_input("PAT Advanced level Or Basic level:[a/b]\n")
pat = PAT(baseURL, level)
#pat.getTitle(pat.getPage(1001))
#pat.getContent()
pat.start()
