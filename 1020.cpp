#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 35;
int post[maxn], in[maxn];
map<int, int> m;
int N, node;
void dfs(int root, int start, int end, int index)
{
	if(start > end)
		return;
	int i = start;
	while(i < end && in[i] != post[root])
		i++;
	m[index] = post[root];
//	printf("%d ", post[root]);
	dfs(root - (end - i + 1), start, i - 1, 2 * index + 1);
	dfs(root - 1, i + 1, end, 2 * index + 2);
}
int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", post + i);
	//int root = post[N - 1], l, end, start;
	for(int i = 0; i < N; i++){
		scanf("%d", in + i);
	}
//	memset(level, -1, sizeof(level));
	dfs(N - 1, 0, N - 1, 0);
	for(map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++){
		if(itr != m.begin())
			printf(" ");
		printf("%d", itr->second);
	}
	return 0;
}
