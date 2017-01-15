#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int n, p;
int s[maxn];
int main()
{
	int i, j, cnt = 0;
	scanf("%d%d", &n, &p);
	for(i = 0; i < n; i++)
		scanf("%d", s + i);
	sort(s, s + n);
	for(i = 0, j = 0; i < n, j < n; ){
		long long int tmp = s[i] * p;
		if(tmp >= s[j])
			j++;
		else{
			if(j - i > cnt)
				cnt = j - i;
			i++;	
		}
		if(j == n){
			if(j - i > cnt)
				cnt = j -i;
		}
	}
	printf("%d", cnt);
	return 0;
}
