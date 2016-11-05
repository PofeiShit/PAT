#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 405;
int p[manx];
int n, k, p;
int main()
{
	scanf("%d%d%d", &n, &k, &p);
	for(int i = 1; ; i++){
		if(pow(i, p) > n)
			break;
		else 
			p[i] = pow(i, p);
	}
	
}
