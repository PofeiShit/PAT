#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
const int maxn = 1e3+10;
int vis[maxn];
vector<int> h[maxn];
vector<int> p[maxn];
vector<int> ans;
int dfs(int x)
{
	if(vis[x]) return 0;
	vis[x] = 1;
	int t = 1;
	for(int i = 0; i < p[x].size(); i++){
		for(int j = 0; j < h[p[x][i]].size(); j++){
			t += dfs(h[p[x][i]][j]);
		}
	}
	return t;
}
int main()
{
	int N, ki, hi;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d:", &ki);
		for(int j = 0; j < ki; j++){
			scanf("%d", &hi);
			h[hi].push_back(i);
			p[i].push_back(hi);
		}
	}
	for(int i = 1; i <= N; i++){
		if(!vis[i])
			ans.push_back(dfs(i));
	}
	sort(ans.begin(), ans.end(), greater<int>() );
	printf("%lu\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		if(i)
			printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
