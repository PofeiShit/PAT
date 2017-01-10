#include <iostream>
#include <cstdio>
#include <algorithm>
double map[510][510];
using namespace std;
struct info
{
	double price;
	int dis;
	bool operator<(const info &a) const
	{
		return dis < a.dis;
	}
}P[510];
#if 0
bool comp(struct info A, struct info B)
{
	return A.dis < B.dis;
}
#endif
int main()
{
	int Cmax, D, N, Max;
	double  cost = 0, Davg;
	cin>>Cmax>>D>>Davg>>N;
	Max = Cmax * N;
	for(int i = 0; i < N; i++)
		scanf("%lf%d", &P[i].price, &P[i].dis);
	sort(P, P + N);
	memset(map, -1, sizeof(map));
	for(int i = 0; i < N; i++)
	{
		double p = P[i].price;
		int d = P[i].dis;	
		for(int j = 0; j < N; j++)
		{
			 if(i != j && d + Max >= P[j].dis)
			 {
				map[i][j] = map[j][i] = p	
			 }
				

		}

	}
	return 0;
}
