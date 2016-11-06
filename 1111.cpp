#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 510;
int edge[maxn][maxn], Vis[maxn], Dis[maxn], Time[maxn][maxn], Min[maxn];
int N, M, s, t, cnt;
vector<int> Path[2];
void Dij()
{
	while(1){
		int now = -1;
		for(int i = 0; i < N; i++){
			if(!Vis[i] && Dis[i] != -1){
				if(now == -1)
					now = i;
				else
					now = Dis[now] < Dis[i] ? now : i; 
			}
		}
		if(now == -1)
			break;
		Vis[now] = 1;
		for(int i = 0; i < N; i++){
			if(edge[now][i]){
				if(Dis[i] == -1 || Dis[i] > Dis[now] + edge[now][i]){
					Dis[i] = Dis[now] + edge[now][i];
					Min[i] = Min[now] + Time[now][i];
				}
				else if(Dis[i] == Dis[now] + edge[now][i]){
					if(Min[i] > Min[now] + Time[now][i])
						Min[i] = Min[now] + Time[now][i];
				}
			}
		}
	}
}
void DijT()
{
	while(1){
		int now = -1;
		for(int i = 0; i < N; i++){
			if(!Vis[i] && Dis[i] != -1){
				if(now == -1)
					now = i;
				else
					now = Dis[now] < Dis[i] ? now : i; 
			}
		}
		if(now == -1)
			break;
		Vis[now] = 1;
		for(int i = 0; i < N; i++){
			if(Time[now][i]){
				if(Dis[i] == -1 || Dis[i] > Dis[now] + Time[now][i]){
					Dis[i] = Dis[now] + Time[now][i];
					Min[i] = Min[now] + 1;
				}
				else if(Dis[i] == Dis[now] + Time[now][i]){
					if(Min[i] > Min[now] + 1)
						Min[i] = Min[now] + 1;
				}
			}
		}
	}
}
void dfs(int T)
{
	if(T == s)
		return ;
	for(int  i = 0; i < N; i++){
		if(edge[i][T]){
			if(Dis[T] == Dis[i] + edge[i][T] && Min[T] == Min[i] + Time[i][T]){
				dfs(i);
				Path[cnt].push_back(i);
			}
		}
	}
	return ;
}
void Dfs(int T)
{
	if(T == s)
		return ;
	for(int  i = 0; i < N; i++){
		if(Time[i][T]){
			if(Dis[T] == Dis[i] + Time[i][T] && Min[T] == Min[i] + 1){
				Dfs(i);
				Path[cnt].push_back(i);
			}
		}
	}
	return ;
}
int main()
{
	int v1, v2, w, l, t;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d%d%d%d%d",&v1, &v2, &w, &l, &t);
		if(w == 0){
			edge[v1][v2] = edge[v2][v1] = l;
			Time[v1][v2] = Time[v2][v1] = t;
		}
		else{
			edge[v1][v2] = l;
			Time[v1][v2] = t;
		}
	}
	scanf("%d%d", &s, &t);
	memset(Dis, -1, sizeof(Dis));
	Dis[s] = 0;
	Dij();
	dfs(t);
	int D = Dis[t];
	memset(Dis, -1, sizeof(Dis));
	memset(Vis, 0, sizeof(Vis));
	memset(Min, 0, sizeof(Min));
	cnt++;
	Dis[s] = 0;
	DijT();
	Dfs(t);
	bool flag = true;
	for(int i = 0; i < Path[0].size(); i++){
		if(Path[0][i] != Path[1][i]){
			flag = false;
			break;
		}
	}
	if(flag){
		printf("Distance = %d; ", D);
		printf("Time = %d:", Dis[t]);
		for(int i = 0; i < Path[1].size(); i++)
			printf(" %d ->", Path[1][i]);
		printf(" %d", t);
	}
	else{
		printf("Distance = %d:", D);
		for(int i = 0; i < Path[0].size(); i++)
			printf(" %d ->", Path[0][i]);
		printf(" %d\n", t);
		printf("Time = %d:", Dis[t]);
		for(int i = 0; i < Path[1].size(); i++)
			printf(" %d ->", Path[1][i]);
		printf(" %d", t);
	}
	return 0;
}	
