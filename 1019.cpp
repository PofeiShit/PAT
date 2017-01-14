#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <stack>
using namespace std;
stack<string> ak;
int N,b,mirrorN;
int vk[100];
int main()
{

	cin>>N>>b;
	int n = N;
	int i = 0;
	string rem;
	stringstream ss;
	if(N == 0)
	{
		cout<<"Yes"<<endl<<0;
		return 0;
	}
	while(n != 0)
	{
		int tmp = n % b; 
		vk[i] = tmp;
		ss<<tmp;
		rem = ss.str();
		ak.push(rem);
		n /= b;
		ss.str("");
		i++;
	}
	for(int j = 0; j < i; j++)
		mirrorN += vk[j] * pow(b, i - j - 1);
	if(mirrorN == N)
		cout<<"Yes"<<endl;
	else  
		cout<<"No"<<endl;
	while(1)
	{
		cout<<ak.top();
		ak.pop();
		if(!ak.empty())
			cout<<' ';
		else
			break;
	}
	return 0;
}
