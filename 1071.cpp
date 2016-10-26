#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cctype>
using namespace std;
int main()
{
	char ch;
	string tmp;
	map<string, int> mp;
	while((scanf("%c", &ch) == 1) && ch != '\n'){
		if(isalnum(ch)){
			ch = tolower(ch);
			tmp += ch;
		} else {
			if(tmp.length())
				mp[tmp]++;
			tmp = "";
		}
	}
//	cout << tmp << endl;
	mp[tmp]++;
	int maxn = -1;
	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
		if(it->second > maxn){
			maxn = it->second;
			tmp = it->first;
		}
	}
	cout << tmp << " " << maxn; 
	return 0;
}
