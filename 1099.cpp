#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 110;
int tree[maxn][2];
int node[maxn];
map<int, int> m;
vector<int> v;
queue<int> Q;
void dfs(int x)
{
	if(tree[x][0] != -1) 
		dfs(tree[x][0]);
	v.push_back(x);
	if(tree[x][1] != -1)
		dfs(tree[x][1]);
	return;
}
void bfs(int x)
{
	int root;
	while(true){
		if(tree[x][0] != -1)
			Q.push(tree[x][0]);
		if(tree[x][1] != -1)
			Q.push(tree[x][1]);
		root = Q.front();
		printf("%d", m[root]);
		Q.pop();
		if(Q.empty())
			break;
		else{
			printf(" ");
			x = Q.front();
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &tree[i][0], &tree[i][1]);
	for(int i = 0; i < n; i++)
		scanf("%d", &node[i]);
	sort(node, node + n);
	dfs(0);
	for(int i = 0; i < n; i++)
		m[v[i]] = node[i];
	Q.push(0);
	bfs(0);
	return 0;
}
