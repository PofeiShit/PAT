#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e3+10;
int t[maxn], bt[maxn];
int n, tot;
queue<int> q;
void dfs(int x)
{
	if(x >= n) return ;
	dfs(2 * x + 1);
	bt[x] = t[tot++];
	dfs(2 * x + 2);	
}
void bfs(int x)
{
	while(1){
		if(2 * x + 1 < n)
			q.push(bt[2 * x + 1]);
		if(2 * x + 2 < n)
			q.push(bt[2 * x + 2]);
		int k = q.front();
		printf("%d", k);
		q.pop();
		if(q.empty())
			break;
		else
			printf(" ");
		x++;
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", t + i);
	sort(t, t + n);
	dfs(0);
	q.push(bt[0]);
	bfs(0);
	return 0;
}
