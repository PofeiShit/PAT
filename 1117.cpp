#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 1e5+10;
int p[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", p + i);
	sort(p, p + n, greater<int>());
	int cnt = 1;
	while(p[cnt - 1] > cnt)
		cnt++;
	printf("%d", cnt - 1);
	return 0;
}
