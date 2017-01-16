#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 10;
int s, n;
int node[maxn], data[maxn], vis[10010];
vector<int> L1, L2;
int main()
{
	int i, addr, key, next;
	scanf("%d%d", &s, &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &addr, &key, &next);
		data[addr] = key;
		node[addr] = next;
	}
	while(1){
		int tmp = abs(data[s]);
		if(vis[tmp] == 0)
			L1.push_back(s);
		else
			L2.push_back(s);
		vis[tmp] = 1;
		s = node[s];	
		if(s == -1)
			break;
	}
	for(i = 0; i < L1.size() - 1; i++)
		printf("%05d %d %05d\n", L1[i], data[L1[i]], L1[i+1]);
	printf("%05d %d -1\n", L1[i], data[L1[i]]);
	if(!L2.empty()){
		for(i = 0; i < L2.size() - 1; i++)
			printf("%05d %d %05d\n", L2[i], data[L2[i]], L2[i+1]);
		printf("%05d %d -1\n", L2[i], data[L2[i]]);
	}
	return 0;
}
