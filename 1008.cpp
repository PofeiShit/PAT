#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	int i, j, k, N, max1 = -1, max2 = -1;
	float a[1001], b[1001], c[2002], aN, bN;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	cin>>k;
		while(k --)
		{
			scanf("%d %f", &N, &aN);
			a[N] = aN;
			max1 = max1 > N ? max1:N;	
		}
		cin>>k;
		while(k --)
		{
			scanf("%d %f", &N, &aN);
			b[N] = aN;
			max2 = max2 > N ? max2:N;	
		}
	k = 0;	
	for(i = 0; i <= max1; i++)
	{
		for(j = 0; j <= max2; j++)
		{
			c[i + j] += a[i] * b[j];	
		}	
	}
	for(i = 0; i <= (max1 + max2); i++)
		if(c[i] != 0)
			k ++;
	cout<<k;
	for(i = (max1 + max2); i >= 0; i--)
	{
		if(c[i] != 0)
			printf(" %d %.1f", i, c[i]);
	}
	return 0;
}
