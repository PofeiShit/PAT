#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100000;
int dp[maxn];
int main()
{
	int n, cnt = 0, mr, r;
	scanf("%d", &n);
	dp[2] = 1;
	dp[3] = 1;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			dp[n] = max(dp[i], dp[n / i]); 
		}
	}
	return 0;
}
