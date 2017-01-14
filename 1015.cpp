#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
using namespace std;
int N;
int D;
int quo;
int rem;
int sum = 0;
int Num;
int Bit[1000];
bool Isprime(int n)
{
	int i;	
	if(n < 2)
		return false;
	if(n % 2 == 0 && n != 2)
		return false;
	for(i = 3; i * i <= n; i += 2)
		if(n % i == 0)
			return false;
	return true;
}
int main()
{
	int i, temp;
	list<string> ans;
	list<string>::iterator aiter;	
	while(1)
	{
		cin>>N; 	
		if(N < 0)
			break;
		else
		{
			temp = N;	
			cin>>D;	
			i = 0;
			quo = N / D;
			rem = N % D;
			Bit[i] = rem;	
			while(quo != 0)
			{
				N = quo;
				quo = N / D;
				rem = N % D;
				i ++;
				Bit[i] = rem;
			}
			Num = i;	
			sum = 0;
			for(i = 0; i <= Num; i ++)	
				sum += Bit[i] * pow(D, Num - i);
			if(Isprime(sum) && Isprime(temp))
				ans.push_back("Yes");
			else
				ans.push_back("No");
		}
	}
	for(aiter = ans.begin(); aiter != ans.end(); ++aiter)
		cout<<*aiter<<endl;
	return 0;
}
