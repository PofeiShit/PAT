#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
const int maxn = 405;
int p[maxn];
int n, k, pw, pos, idx;
vector<vector<int> > ans;
vector<int> tmp;
void dfs(int x, int s)
{
	for(int i = x; i >= 1; i--){
		if(s + p[i] < n){
			if(tmp.size() > k)
				return;
			else{
				tmp.push_back(i);
				dfs(i, s + p[i]);
				tmp.pop_back();
			}
		}
		else if(s + p[i] == n){
			tmp.push_back(i);
			if(tmp.size() == k)
				ans.push_back(tmp);
			tmp.pop_back();
		}
	}
}
bool cmp(vector<int> v1, vector<int> v2)
{
	if(accumulate(v1.begin(), v1.end(), 0) != accumulate(v2.begin(), v2.end(), 0))
		return accumulate(v1.begin(), v1.end(), 0) > accumulate(v2.begin(), v2.end(), 0);
	else 
		return v1 > v2;
}
int main()
{
	int i;
	scanf("%d%d%d", &n, &k, &pw);
	for(i = 1; ;i++){
		if(pow(i, pw) > n)
			break;
		else 
			p[i] = pow(i, pw);
	}
	pos = i - 1;
	int sum = 0, max = -1;
	dfs(pos, 0);
	if(ans.empty()){
		printf("Impossible\n");
		return 0;
	} 
	sort(ans.begin(), ans.end(), cmp);
	printf("%d = ", n);
	for(int i = 0; i < ans[0].size(); i++){
		if(i)
			printf(" + ");
		printf("%d^%d", ans[0][i], pw);
	}
	return 0;
}
