#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
const int maxn = 1e4+10;
int bird[maxn];
vector<int> father, isRoot; 
int find(int x)
{
	int a = x;
	while(x != father[x])
		x = father[x];
	while(a != father[a]){
		int z = a;
		father[a] = x;
		a = father[z];
	}
	return x;
}
void Union(int a, int b)
{
	int faA = find(a);
	int faB = find(b);
	if(faA != faB)
		father[faA] = faB;
}
int main()
{
	int n, k, bi, m = 0;
	scanf("%d", &n);
	father.resize(n + 1);
	isRoot.resize(n + 1);
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= n; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &bi);
			m = max(m, bi);
			if(bird[bi] == 0)
				bird[bi] = i;
			Union(i, find(bird[bi]));
		}
	}
	for(int i = 1; i <= n; i++)
		isRoot[find(i)]++;
	int cnt = 0, b1, b2;
	for(int i = 1; i <= n; i++){
		if(isRoot[i] != 0)
			cnt++;
	}
	printf("%d %d\n", cnt, m);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &b1, &b2);
		if(find(bird[b1]) == find(bird[b2]))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
