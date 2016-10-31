#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, d, ans;
int c[maxn], idx[maxn], dp[maxn];
map<int, int> mp;
int main()
{
	scanf("%d%d", &n, &m);
	mp[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &ans);
		c[i] = c[i - 1] + ans;
		mp[c[i]] = i;
	}
	bool flag = false;;
	for(int i = m; i < m + 100; i++){
		for(map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++){
			if(mp.find(itr->first + i) != mp.end()){
				printf("%d-%d\n", itr->second + 1, mp[itr->first + i]);
				flag = true;	
			}
		}
		if(flag)
			break;
	}
	return 0;
}
