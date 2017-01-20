#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 205;
int N, M, K, n;
int graph[maxn][maxn], vis[maxn]; 
int main()
{
	int x, y;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d%d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	scanf("%d", &K);
	int start, tmp, j;
	for(int i = 0; i < K; i++){
		scanf("%d", &x);
		memset(vis, 0, sizeof(vis));
		for(j = 0; j < x; j++){
			scanf("%d", &y);
			if(j){
				if(graph[tmp][y] == 1 && vis[y] == 0){
					vis[y] = 1;
					tmp = y;
				}else
					break;
			} else { 
				tmp = start = y; 
				vis[start] = 1;
			}
		}
		for(j = j + 1; j < x; j++)
			scanf("%d", &y);
		if(y != start || graph[tmp][y] != 1)
			printf("NO\n");
		else {
			for(x = 1; x <= N; x++){
				if(vis[x] == 0){
					printf("NO\n");
					break;
				}
			}
			if(x == N + 1)
				printf("YES\n");
		}
	}
	return 0;
}
