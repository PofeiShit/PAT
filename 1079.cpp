#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> vec[maxn];
double f[maxn];
int n, k, id;
double ans, p, r;
void dfs(int x, double s)
{
	if(vec[x].empty()){
		ans += s * f[x];
		return;
	}
	for(int i = 0; i < vec[x].size(); i++){
		dfs(vec[x][i], s * (1.0 + r / 100.0));
	}
}
int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k == 0)
			scanf("%lf", f + i);
		else{
			for(int j = 0; j < k; j++){
				scanf("%d", &id);
				vec[i].push_back(id);
			}
		}
	}
	dfs(0, p);
	printf("%.1lf", ans);
	return 0;
}
