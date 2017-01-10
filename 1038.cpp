#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct number
{
	string is;
	int cnt;
}Num[10010];
bool cmp(struct number A, struct number B)
{
	return A.is < B.is;
}
int main()
{
	int N, i = 0, len;
	cin>>N;
	string tmp, s1;
	for(i = 0; i < N; i++)
	{
		cin>>tmp;
		Num[i].cnt = tmp.length();
		Num[i].is = tmp;
		for(int j = 0; j < 8/tmp.length(); j++)
			Num[i].is.append(tmp);	
		Num[i].is.erase(Num[i].is.begin() + 8, Num[i].is.end());
		tmp.clear();
	}
	sort(Num, Num + N, cmp);
	for(i = 0; i < N; i++)
	{
		tmp = Num[i].is;
		len = Num[i].cnt;
		s1.append(Num[i].is.begin(), Num[i].is.begin() + len);		
	}
	int pos = s1.find_first_not_of('0', 0);
	if(pos == string::npos)
	{
		if(atoi(s1.c_str()) == 0)
			cout<<0<<endl;
		else
			cout<<s1<<endl;
	}
	else
	{
		s1.erase(s1.begin(), s1.begin() + pos);
		cout<<s1<<endl;
	}
	return 0;
}
