#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n, tot;
int node[maxn], tree[maxn][2], bst[maxn];
map<int, int> level;
void dfs(int root, int idx)
{
	if(root == -1)
		return ;
	int left = tree[root][0], right = tree[root][1];
	dfs(left, 2 * idx + 1);
	level[idx] = node[tot++];
	dfs(right, 2 * idx + 2);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d%d", &tree[i][0], &tree[i][1]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &node[i]);
	sort(node, node + n);
	dfs(0, 0);
	map<int, int>::iterator itr;
	for(itr = level.begin(); itr != level.end(); ++itr){
		if(itr != level.begin())
			printf(" ");
		printf("%d", itr->second);
	}
	return 0;
}
