#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 110;
int level[maxn];
int n, m;
vector<int> v[maxn];
void dfs(int x, int l)
{
	if(v[x].empty())
		return ;
	else{
		for(int i = 0; i < v[x].size(); i++){
			dfs(v[x][i], l + 1);
			level[l]++;
		}
	}
}
int main()
{
	int id, idx, k;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &idx);
			v[id].push_back(idx);
		}
	}
	dfs(1, 1);
	level[0] = 1;
	int max = -1, l = -1;
	for(int i = 0; i < 10; i++){
//		if(level[i] == 0)
//			break;
//		else{
			if(level[i] > max){
				max = level[i];
				l = i;
			}
//		}
	}
	printf("%d %d", max, l + 1);
	return 0;
}
