#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 1e4+10;
vector<int> v[maxn];
set<int> S;
int N, ans = 0, c = 1;
int cnt[maxn], vis[maxn];
void dfs(int s, int d)
{
	cnt[s] = d;
	vis[s] = 1;	
	ans = max(ans, d);
	for(int i = 0; i < v[s].size(); i++)
		if(!vis[v[s][i]])
			dfs(v[s][i], d + 1);
}
int main()
{
	scanf("%d", &N);
	int x,y;
	for(int i = 1; i < N; i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int s = 1, i;
	while(1){
		dfs(s, 0);
		for(i = 1; i <= N; i++){
			if(vis[i] == 0){
				c++;
				s = i;
				break;
			}
		}
		if(i == N + 1)
			break;
	}
	if(c >= 2){
		printf("Error: %d components\n", c);
		return 0;
	}
	ans = 0, s = 1;
	memset(cnt, 0, sizeof(cnt));
	for(int j = 1; j <= 2; j++){
		memset(vis, 0, sizeof(vis));
		dfs(s, 0);
		for(i = 1; i <= N; i++){
			if(cnt[i] == ans){
				s = i;
				S.insert(i);
			}
		}
		ans = 0;
	}
	for(set<int>::iterator itr = S.begin(); itr != S.end(); itr++)
		cout<<*itr<<endl;
	return 0;
}
