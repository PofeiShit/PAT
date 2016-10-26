#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1010;
double f[maxn];
double b[maxn];
double p[maxn];
int main()
{
	double t, n, d, s = 0.0;
	scanf("%lf%lf", &n, &d);
	for(int i = 0; i < n; i++)
		scanf("%lf", f + i);
	for(int i = 0; i < n; i++){
		scanf("%lf", p + i);
		b[i] = p[i] / f[i];
	}
	int idx;
	while(d > 0){
		t = 0.0;
		for(int i = 0; i < n; i++){
			if(b[i] > t){
				t = b[i];
				idx = i;
			}
		}
		if(idx == -1)
			break;
		if(f[idx] <= d){
			s += p[idx];
			d -= f[idx];
		} else {
			s += d * b[idx];
			d = 0;
		}
		b[idx] = -1;
		idx = -1;
	}
	printf("%.2lf", s);
	return 0;
}
