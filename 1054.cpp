#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
const int maxn = 110;
vector<int> v[maxn];
vector<int> ans;
vector<vector<int> > mp;
int w[maxn];
int s;
void dfs(int root, int sum, int w1)
{
	ans.push_back(w1);
	if(v[root].empty()) {
		if(sum == s)
			mp.push_back(ans);
		return;
	}
	for(int i = 0; i < v[root].size(); i++){
		dfs(v[root][i], sum + w[v[root][i]],  w[v[root][i]]);
		ans.pop_back();
	}
}
int main()
{
	int n, k, m, id, idk;
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < n; i++)
		scanf("%d", w + i);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &idk);
			v[id].push_back(idk);
		}
	}
	dfs(0, w[0], w[0]);
	sort(mp.begin(), mp.end());
	for(vector<vector<int> >::reverse_iterator itr = mp.rbegin(); itr != mp.rend(); itr++){
		vector<int> tmp = *itr;
		for(int j = 0; j < tmp.size(); j++){
			printf("%d", tmp[j]); 
			if(j != tmp.size() - 1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
