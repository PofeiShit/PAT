#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int Num[maxn];
int main()
{
	int N, n1, s1, s2;
	s1 = s2 = 0;
	scanf("%d", &N);
	n1 = N / 2;
	for(int i = 0; i < N; i++)
		scanf("%d", Num + i);		
	sort(Num, Num + N);
	for(int i = 0; i < n1; i++){
		s1 += Num[N - 1 - i];
		s2 += Num[i];
	}
	if(n1 * 2 == N)
		printf("0 %d", s1 - s2);
	else
		printf("1 %d", s1 + Num[n1] - s2);
	return 0;
}
