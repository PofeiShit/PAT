#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <map>
using namespace std;
#define inf 0x7fffffff
#define maxn 510
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int Cmax,N,Sp,M;
int edge[maxn][maxn], vis[maxn], C[maxn], dis[maxn], ans[maxn];
const int Start = 0;
bool dfs(int x)
{
	if(x == Start){
		printf("%d->", Start);
		return true;
	}
	for(int i = 0; i < N+1; i++)
	{
		if(edge[i][x] != -1 && dis[x] == dis[i] + edge[i][x] && ans[x] == ans[i] + C[i] - Cmax / 2){
			if(dfs(i))
			{
				printf("%d", x);
				if(x != Sp)
					printf("->");
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int x,y,z;
	cin>>Cmax>>N>>Sp>>M;
	for(int i = 1; i <= N; i++)
		scanf("%d", &C[i]); 
	memset(edge, -1, sizeof(edge));
	memset(dis, -1, sizeof(dis));
	for(int i = 0; i < M; i++){
		scanf("%d%d%d", &x, &y, &z);
		edge[x][y] = edge[y][x] = z;
	}
	dis[Start] = 0;
	ans[Start] = 0;
	while(1){
		int now = -1;
		for(int i = 0; i < N+1; i++){
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
		for(int i = 0; i < N+1; i++){
			if(edge[now][i] != -1){
				if(dis[i] == -1 || dis[i] > dis[now] + edge[now][i]){
					dis[i] = dis[now] + edge[now][i];
					ans[i] = ans[now] + C[now] - Cmax / 2;//中间路过的节点小于一半
				}
				else if(dis[i] == dis[now] + edge[now][i]){
					if(ans[i] >= 0 && ans[now] + C[now] - Cmax / 2 >= 0)
						ans[i] = min(ans[i], ans[now] + C[now] - Cmax / 2);//带回去的最少
					else 
						ans[i] = max(ans[i], ans[now] + C[now] -  Cmax / 2);//带来的最多
				}
			}
		}
	}
	if(ans[Sp] >= 0){
		printf("%d ", 0);
		dfs(Sp);
		if(C[Sp] == 0)
			printf(" %d", ans[Sp]);
		else 
			printf(" %d", ans[Sp] + Cmax);
	}
	else{
		printf("%d ", -1 * ans[Sp]);
		dfs(Sp);
		if(C[Sp] == 0)
			printf(" %d", 0);
		else 
			printf(" %d", Cmax / 2);
	}
	return 0;
}
