#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int Coin[maxn];
int main()
{
	int N, M;
	cin>>N>>M;
	for(int i = 0; i < N; i++)
		scanf("%d", Coin + i);
	sort(Coin, Coin + N);
	int left, right;
	for(left = 0, right = N - 1; left < right;){
		int tmp = Coin[left] + Coin[right];
		if(tmp == M)
			break;
		else if(tmp > M)
			right--;
		else 
			left++;
	}
	if(left >= right)
		printf("No Solution\n");
	else
		printf("%d %d\n", Coin[left], Coin[right]);
	return 0;
}
