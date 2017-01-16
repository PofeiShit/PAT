#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
vector<int> s[maxn];
int n, root, cnt;
double p, r, sum;
void dfs(double tmp, int idx)
{
	if(tmp > sum){
		cnt = 1;
		sum = tmp;
	}
	else if(tmp == sum)
		cnt++;
	if(s[idx].empty())
		return;
	for(int i = 0; i < s[idx].size(); i++)
		dfs(tmp * (1.0 + r / 100.0), s[idx][i]);
}
int main()
{
	int j;
	scanf("%d%lf%lf", &n, &p, &r);	
	for(int i = 0; i < n; i++){
		scanf("%d", &j);
		if(j == -1)
			root = i;
		else
			s[j].push_back(i);

	}
	dfs(p, root);
	printf("%.2lf %d", sum, cnt);
	return 0;
}
