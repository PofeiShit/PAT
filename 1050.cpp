#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
set<int> s2;
int get(char ch)
{
	return ch - 0;	
}
int main()
{
	string s1;
	char ch;
	getline(cin, s1);
	while((scanf("%c", &ch) == 1) && ch != '\n'){
		int m = get(ch);
		s2.insert(m);
	}
	for(int i = 0; i < s1.length(); i++){
		int m = get(s1[i]);
		set<int>::iterator pos = s2.find(m);
		if(pos == s2.end())
			printf("%c", s1[i]);
	}
	return 0;
}
