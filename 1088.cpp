#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long Type;
Type a, b, c, d;
Type GCD(Type x, Type y)
{
	if(x > y)
		swap(x, y);
	Type r = x % y;
	while(r){
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}
void print(Type fenZi, Type fenMu)
{
	int flag = 1;
	if(fenZi < 0){
		printf("(-");
		fenZi *= -1;
		flag = -1;
	}
	if(fenZi == 0)
		printf("0");
	else{
		Type com = GCD(fenZi, fenMu);
		fenZi /= com;
		fenMu /= com;
		if(fenZi < fenMu)
			printf("%lld/%lld", fenZi, fenMu);
		else{
			Type quo = fenZi / fenMu;
			Type rem = fenZi % fenMu;
			if(rem == 0)
				printf("%lld", quo);
			else
				printf("%lld %lld/%lld", quo, rem, fenMu);
		}
	}
	if(flag == -1)
		printf(")");
}
void add()
{
	print(a, b);
	printf(" + ");
	print(c, d);
	printf(" = ");
	print(a * d + (c * b), b * d);
}
void Minus()
{
	print(a, b);
	printf(" - ");
	print(c, d);
	printf(" = ");
	print(a * d - (c * b), b * d);
}
void product()
{
	print(a, b);
	printf(" * ");
	print(c, d);
	printf(" = ");
	print(a * c, b * d);
}
void divide()
{
	print(a, b);
	printf(" / ");
	print(c, d);
	printf(" = ");
	if(c == 0)
		printf("Inf");
	else {
		if(c < 0){
			c = -c;
			d = -d;
		}
		print(a * d, b * c);
	}
}
int main()
{
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	add();
	printf("\n");
	Minus();
	printf("\n");
	product();
	printf("\n");
	divide();
	return 0;
}
