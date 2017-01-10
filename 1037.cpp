#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int NC, NP;
int NumC[maxn], NumP[maxn]; 
bool comp(int a, int b)
{
	if(a < 0 && b < 0)
		return a > b;
	return a < b;
}
int main()
{
	scanf("%d", &NC);
	for(int i = 0; i < NC; i++)
		scanf("%d", &NumC[i]);
	scanf("%d", &NP);
	for(int i = 0; i < NP; i++)
		scanf("%d", &NumP[i]);
	sort(NumC, NumC + NC, comp);
	sort(NumP, NumP + NP, comp);
	int i = NC - 1, j = NP - 1, max = 0;
	while(1)
	{
		if(NumC[i] < 0)
		{
			if(NumP[j] < 0)
			{
				max += NumC[i] * NumP[j];
				i--;
			}
			j--;
		}
		else if(NumC[i] > 0)
		{
			if(NumP[j] > 0)
			{
				max += NumC[i] * NumP[j];
				j--;
			}
			i--;
		}
		else
			i--;
		if(i < 0 || j < 0)
			break;
	}
	cout<<max<<endl;
#if 0
	for(int i = 0; i < NC; i++)
		printf("%d", NumC[i]);
	for(int i = 0; i < NP; i++)
		printf("%d", NumP[i]);
#endif
	return 0;
}
