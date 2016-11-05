#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>
using namespace std;
const int maxn = 1e5 + 10;
int vis[maxn], cnt;
double price = INT_MAX, p, r, rate;
vector<int> edge[maxn];
void dfs(int root, double z)
{
	vis[root] = 1;
	if(!edge[root].empty()){
		for(int i = 0; i < edge[root].size(); i++){
			if(vis[edge[root][i]] != 1)
				dfs(edge[root][i], z * (1 + rate));
		}
	}
	else{
		if(z < price){
			price = z;
			cnt = 1;
		}
		else if(z == price)
			cnt++;
	}
	return ;
}
int main()
{
	int N, Ki, Id;
	scanf("%d%lf%lf", &N, &p, &r);	
	rate = r / 100.0;
	for(int i = 0; i < N; i++){
		scanf("%d", &Ki);
		for(int j = 0; j < Ki; j++){
			scanf("%d", &Id);
			edge[i].push_back(Id);
		}
	}
	dfs(0, p);
	printf("%.4lf %d", price, cnt);
	return 0;
}
