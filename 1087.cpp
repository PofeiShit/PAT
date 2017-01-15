#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn = 205;
stack<int> p;
int c[20000], h[maxn], map[maxn][maxn], vis[maxn], dis[maxn], cnt[maxn], route[maxn], ci[maxn], back[maxn];
int n, k, s, t;
char city[4], city1[4];
int change(char *s)
{
	return (s[0] - 'A') * 676 + (s[1] - 'A') * 26 + (s[2] - 'A');
}
void print(int x)
{
	printf("%c%c%c", x / 676 + 'A', x % 676 / 26 + 'A', x % 676 % 26 + 'A');
}
void dfs(int x)
{
	p.push(x);
	if(x == c[s])
		return;
	else{
		for(int i = 0; i < n; i++){
			if(map[i][x] && dis[x] == dis[i] + map[i][x] && cnt[x] == cnt[i] + h[x] && ci[x] == ci[i] + 1)
				dfs(i);
		}
	}
}
int main()
{
	int tmp, tmp1, cost;
	scanf("%d%d%s", &n, &k, city);	
	s = change(city);
	t = change("ROM");
	for(int i = 0; i < n - 1; i++){
		scanf("%s%d", city, h + i);
		c[change(city)] = i;
		back[i] = change(city);
	}
	c[s] = n - 1;
	back[n - 1] = s;
	for(int i = 0; i < k; i++){
		scanf("%s%s%d", city, city1, &cost);
		tmp = c[change(city)];
		tmp1 = c[change(city1)];
		map[tmp][tmp1] = cost;
		map[tmp1][tmp] = cost;
	}
	memset(dis, -1, sizeof(dis));
	dis[c[s]] = 0;
	h[c[s]] = 0;
	route[c[s]] = 1;
	while(1){
		int now = -1;
		for(int i = 0; i < n; i++){		
			if(!vis[i] && dis[i] != -1){
				if(now == -1)
					now = i;
				else
					now = dis[now] < dis[i] ? now : i;
			}
		}
		if(now == -1)
			break;
		vis[now] = 1;
		for(int i = 0; i < n; i++){
			if(map[now][i]){
				if(dis[i] == -1 || map[now][i] + dis[now] < dis[i]){
					dis[i] = map[now][i] + dis[now];
					cnt[i] = cnt[now] + h[i];
					route[i] = route[now];
					ci[i] = ci[now] + 1;
				}
				else if(map[now][i] + dis[now] == dis[i]){
					route[i] += route[now];
					if(cnt[i] < cnt[now] + h[i]){
						cnt[i] = cnt[now] + h[i];
						ci[i]  = ci[now] + 1;
					}
					else if(cnt[i] == cnt[now] + h[i])
						ci[i] = min(ci[i], ci[now] + 1);
				}
			}
		}
	}
	int avg = cnt[c[t]] / ci[c[t]];
	printf("%d %d %d %d\n", route[c[t]], dis[c[t]], cnt[c[t]], avg);
	dfs(c[t]);
	while(!p.empty()){
		print(back[p.top()]);
		p.pop();
		if(!p.empty())
			printf("->");
	}
	return 0;
}
