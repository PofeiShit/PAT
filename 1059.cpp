#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int, int> Prime;
void countPrime(long long N)
{
	if(N == 2){
		Prime[N]++;
		return;
	}
	if(N % 2 == 0){
		Prime[2]++;
		countPrime(N/2);
	}
	else{
		int i;
		for(i = 3; i * i <= N; i+=2){
			if(N % i == 0){
				Prime[i]++;
				countPrime(N / i);
				break;
			}
		}
		if(i * i > N)
			Prime[N]++;
	}
	return;
}
int main()
{
	long long N;
	scanf("%lld", &N);
	countPrime(N);
	printf("%lld=", N);
	for(map<int, int>::iterator itr = Prime.begin(); itr != Prime.end(); ){
		if(itr->second == 1)
			printf("%d", itr->first);
		else
			printf("%d^%d", itr->first, itr->second);
		itr++;
		if(itr != Prime.end())
			printf("*");
	}
	return 0;
}
