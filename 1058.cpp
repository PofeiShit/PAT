#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int K1, S1, G1, K2, S2, G2;
	scanf("%d.%d.%d %d.%d.%d", &G1, &S1, &K1, &G2, &S2, &K2);
	int k = K1 + K2;
	int s = S1 + S2;
	int g = G1 + G2;
	if(k >= 29){
		k = k -29;
		s++;
	}
	if(s >= 17){
		s = s - 17;
		g++;
	}
	printf("%d.%d.%d", g, s, k);
	return 0;
}
