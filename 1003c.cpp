#include<cstdio>  
#include<queue>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const int maxn = 5e2 + 10;  
int ans, n, m, s, t, v[maxn], dis[maxn], map[maxn][maxn], x, y, z, vis[maxn];  
long long cnt[maxn];  

void dfs(int x, int y, int z)  
{  
	ans = max(ans, z);  
	if (x == y || dis[x] == -1) return;  
	for (int i = 0; i<n; i++)  
	{  
		if (map[x][i] != -1 && dis[x] == dis[i] + map[x][i])  
		{  
			dfs(i, y, z + v[i]);  
		}  
	}  
	dis[x] = -1;  
}  

int main()  
{  
	scanf("%d%d%d%d", &n, &m, &s, &t);  
	for (int i = 0; i<n; i++) scanf("%d", &v[i]);  
	memset(map, -1, sizeof(map));  
	memset(dis, -1, sizeof(dis));  
	while (m--)  
	{  
		scanf("%d%d%d", &x, &y, &z);  
		map[x][y] = map[y][x] = z;  
	}  
	dis[s] = 0;  cnt[s] = 1;  
	while (true)  
	{  
		int now = -1;  
		for (int i = 0; i<n; i++)  
			if (!vis[i] && dis[i] != -1)  
			{  
				if (now == -1) now = i; else now = dis[now]<dis[i] ? now : i;  
			}  
		if (now == -1) break;  
		vis[now] = 1;  
		for (int i = 0; i<n; i++)  
		{  
			if (map[now][i] != -1)  
			{  
				if (dis[i] == -1 || dis[i]>dis[now] + map[now][i]) { dis[i] = dis[now] + map[now][i]; cnt[i] = cnt[now]; }  
				else if (dis[i] == dis[now] + map[now][i]) cnt[i] += cnt[now];  
			}  
		}  
	}  
	dfs(t, s, v[t]);  
	printf("%lld %d\n", cnt[t], ans);  
	return 0;  
} 
//4 5 0 2
//1 2 1 5
//0 2 3
//0 1 1
//1 2 2
//1 3 1
//3 2 1
//3 6

