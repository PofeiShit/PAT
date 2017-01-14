#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
#define LL long long
#define max(a, b) ((a) > (b) ? (a) : (b))
long long int radix;
int tag;
string N1, N2;
LL int value(string In, int len, LL int rad)
{
	LL int Value = 0;
	LL int d = 1;
	for(int i = len - 1; i >= 0; i--)	
	{
		int num = 0;
		if(In[i] >= '0' && In[i] <= '9')
			num = In[i] - '0';
		else 
			num = In[i] - 'a' + 10;			
		Value += num * d;
		d *= rad;
	}
	return Value;
}
LL int BinarySearch(string In, LL int X)
{
	LL int High = X, Low  = -1, Mid, v;
	for(int i = 0; i < In.length(); i++)
	{
		if(In[i] >= '0' && In[i] <= '9')
			Low = max(Low, In[i] - '0');
		else 
			Low = max(Low, In[i] - 'a' + 10);
	}
	++Low;
	High = max(High, Low);
	while(Low <= High)
	{
		Mid = (Low + High) / 2;
		v = value(In, In.length(), Mid);	
		if(v < X)
			Low = Mid + 1;
		else if(v > X)
			High = Mid - 1;
		else
			return Mid;
	}
	return -1;
}
int main()
{
	LL int left = -1;
	LL int right = -1;
	LL int idx;	
	cin>>N1>>N2>>tag>>radix;	
	if(tag == 1)
		left = value(N1, N1.length(), radix);	
	else
		right = value(N2, N2.length(), radix);
	if(N1.compare(N2) == 0)
	{
		if(N1 == "1")
			printf("2\n");
		else
			printf("%lld", radix);
	}
	else
	{
		if(left == -1)
		{
			idx = BinarySearch(N1, right);
			if(idx != -1) 
				printf("%lld", idx);
			else
				printf("Impossible");
		}
		else if(right == -1)
		{
			idx = BinarySearch(N2, left);
			if(idx != -1)
				printf("%lld", idx);
			else
				printf("Impossible");
		}	
	}
	return 0;
}
