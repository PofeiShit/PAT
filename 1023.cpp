#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int N[25];
int cnt[10];
int Dcnt[10];
stack<int> s;
int main()
{
	char n;
	int tmp, i = 0, JinWei = 0, JieGuo;
	while((scanf("%c", &n) == 1) && n != '\n'){
		N[i] = n - '0';
		i++;
		tmp = cnt[n - '0'];
		tmp++;
		cnt[n - '0'] = tmp;
	}
	for(--i; i >= 0; --i){
		JieGuo = (N[i] * 2 + JinWei) % 10;
		s.push(JieGuo);
		tmp = Dcnt[JieGuo];	
		tmp++;
		Dcnt[JieGuo] = tmp;
		JinWei = (N[i] * 2 + JinWei) / 10;
	}
	if(JinWei == 1)
		s.push(JinWei);
	bool flag = 1;
	for(i = 0; i < 10; i++)
		if(cnt[i] != Dcnt[i])
			flag = 0;
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	return 0;
}
