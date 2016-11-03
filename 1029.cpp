#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<long long int> V;
int main()
{
	long long int num;
	int N, sum = 0;
	for(int i = 0; i < 2; i++)
	{
		cin>>N;
		sum += N;
		for(int j = 0; j < N; j++)
		{
			scanf("%lld", &num);
			V.push_back(num);
		}
	}
	sort(V.begin(), V.end());
	printf("%lld", V.at((sum - 1)/2));
}
