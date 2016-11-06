#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 10010;
int p[maxn];
int vis[maxn];
bool isPrime(int x)
{
	if(x == 2)
		return true;
	else if(x % 2 == 0)
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
	int n = 0, id = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &id);
		p[id] = i;
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &id);
		if(p[id] != 0 && vis[id] != 1){
			if(p[id] == 1)
				printf("%04d: Mystery Award\n", id);
			else if(isPrime(p[id]))
				printf("%04d: Minion\n", id);
			else
				printf("%04d: Chocolate\n", id);
			vis[id] = 1;
		}
		else if(p[id] == 0)
			printf("%04d: Are you kidding?\n", id);
		else if(vis[id] == 1)
			printf("%04d: Checked\n", id);
	}
	return 0;
}
