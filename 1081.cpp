#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long GCD(long long a, long long b)
{
	if(a < b)
		swap(a, b);
	long long r = a % b;
	while(r){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int main()
{
	int n;
	long long num = 0, den = 1, a, b;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld/%lld", &a, &b);
		num = num * b + a * den;
		den = den * b;
	}
	if(num == 0){
		printf("0");	
		return 0;
	}
	else if(num < 0){
		printf("-");
		num *= -1;
	}
	long long com = GCD(num, den);
	num /= com;
	den /= com;
	if(num < den)
		printf("%lld/%lld", num, den);
	else{ 
		if(num % den == 0)
			printf("%lld", num / den);
		else
			printf("%lld %lld/%lld", num/den, num % den, den);
	}
	return 0;
}
