#include <iostream>
#include <cstring>
using namespace std;
int Number;
struct accout
{
	string account;
	string password;
}Acc[1010];
int main()
{
	int cnt = 0;
	bool change = 0;
	string a, p;
	cin>>Number;
	for(int i = 0; i < Number; i++)
	{
		cin>>a>>p;
		for(int j = 0; j < p.length(); j++)
		{
			switch(p[j])
			{
				case '1':
					p.replace(j, 1, 1, '@');
					change = 1;
					break;
				case '0':
					p.replace(j, 1, 1, '%');
					change = 1;
					break;
				case 'l':
					p.replace(j, 1, 1, 'L');
					change = 1;
					break;
				case 'O':
					p.replace(j, 1, 1, 'o');
					change = 1;
					break;
				default:
					break;
			}
		}
		if(change == 1)
		{
			Acc[cnt].account = a;
			Acc[cnt].password = p;
			cnt++;
			change = 0;
		}
	}
	if(cnt == 0)
	{
		if(Number == 1)
			cout<<"There is 1 account and no account is modified"<<endl;
		else
			cout<<"There are "<<Number<<" accounts and no account is modified"<<endl;
	}
	else
	{
		cout<<cnt<<endl;
		for(int i = 0; i < cnt; i++)
			cout<<Acc[i].account<<' '<<Acc[i].password<<endl;
	}
	return 0;
}
