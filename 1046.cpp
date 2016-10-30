#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, s, t, ans, sum, tmp;
int dis[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &tmp);
		dis[i] = tmp + dis[i - 1];
		sum += tmp;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &s, &t);
		if(s > t)
			swap(s, t);
		ans = dis[t - 1] - dis[s - 1];
		ans = min(ans, sum - ans);
		printf("%d\n", ans);
	}
	return 0;
}
