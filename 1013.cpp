#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, m, k, x, y, z, cnt;
vector<int> v[maxn];
int vis[maxn];
void dfs(int x)
{
	vis[x] = 1;
	for(int i = 0; i < v[x].size(); i++)
		if(!vis[v[x][i]])
			dfs(v[x][i]);
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 0; i < k; i++){
		scanf("%d", &z);
		vis[z] = 1;	
		for(int j = 1; j <= n; j++){
			if(!vis[j]){
				dfs(j);
				cnt++;
			}
		}
		memset(vis, 0, sizeof(vis));
		printf("%d\n", cnt - 1);
		cnt = 0;
	}
	return 0;
}
