#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 510
#define min(a, b) ((a) < (b) ? (a) : (b))
int edge[maxn][maxn], cost[maxn][maxn], vis[maxn], dis[maxn], ans[maxn];
int N,M,S,D;
bool dfs(int x)
{
	if(x == S){
		printf("%d ", S);
		return true;
	}
	for(int i = 0; i < N; i++){
		if(edge[i][x] && dis[x] == dis[i] + edge[i][x] && ans[x] == ans[i] + cost[i][x]){
			if(dfs(i)){
				printf("%d ", x);
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int x,y,z,v;
	cin>>N>>M>>S>>D;
	memset(edge, -1, sizeof(edge));
	memset(dis, -1, sizeof(dis));
	for(int i = 0; i < M; i++){
		scanf("%d%d%d%d", &x, &y, &z, &v);
		edge[x][y] = edge[y][x] = z;
		cost[x][y] = cost[y][x] = v;	
	}
	dis[S] = 0;	
	ans[S] = 0;
	while(1){
		int now = -1;
		for(int i = 0; i < N; i++){
			if(vis[i] == 0 && dis[i] != -1){
				if(now == -1)
					now = i;
				else
					now = dis[now] < dis[i] ? now : i;
			}	
		}
		if(now == -1)
			break;
		vis[now] = -1;
		for(int j = 0; j < N; j++){
			if(edge[j][now] != -1){
				if(dis[j] == -1 || dis[j] > dis[now] + edge[now][j]){
					dis[j] = dis[now] + edge[now][j]; 
					ans[j] = ans[now] + cost[now][j];
				}
				else if(dis[j] == dis[now] + edge[now][j])
					ans[j] = min(ans[j], ans[now] + cost[now][j]);
			}
		}
	}
	dfs(D);
	printf("%d %d", dis[D], ans[D]);
	return 0;
}
