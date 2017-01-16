#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string s1, s2;
int main()
{
	cin>>s1;
	unsigned long int cnt = 0, len = 0, sz = s1.length();
	char ch;
	cin.get();
	while((scanf("%c", &ch) == 1) && ch != '\n'){
		len++;
		int pos = s1.find(ch, 0);
		if(pos != string::npos){
			cnt++;
			s1.erase(s1.begin() + pos);
		}
	}
	if(cnt == len)
		printf("Yes %lu", sz - len);
	else
		printf("No %lu", len - cnt);
	return 0;
}
