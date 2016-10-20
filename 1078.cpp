#include <iostream>
#include <cstdio>
using namespace std;
const int msize = 1e4;
int vis[msize];
int m, n;
bool isPrime(int x)
{
	if(x == 2)
		return true;
	else if(x % 2 == 0 || x == 1)
		return false;
	else{
		for(int i = 3; i * i <= x; i+=2) 
			if(x % i == 0)
				return false;
	}
	return true;
}
int main()
{
	int d;
	scanf("%d%d", &m, &n);
	if(!isPrime(m)){
		for(int i = m; ;i++){
			if(isPrime(i)){
				m = i;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &d);
		if(!vis[d % m]){
			printf("%d", d % m);
			vis[d % m] = 1;
		}
		else{
			int step;
			for(step = 1; step < m; step++){
				if(!vis[(d + step * step) % m]){
					printf("%d", (d + step * step) % m);
					vis[(d + step * step) % m] = 1;
					break;
				}
			}
			if(step == m)
				printf("-"); 
		}
		if(i != n - 1)
			printf(" ");
	}
	return 0;
}
