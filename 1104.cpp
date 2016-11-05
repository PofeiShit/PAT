#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 10;
double sum = 0;
int main()
{
	double N, tmp = 1;
	double n;
	scanf("%lf", &N);
	for(int i = 0; i < N; i++){
		scanf("%lf", &n);
		tmp = (N - i) * (i + 1);
		sum += n * tmp;
	}
	printf("%.2lf", sum);
	return 0;
}
