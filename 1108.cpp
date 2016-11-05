#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char a[50], b[50];
int main()
{
	int N;
	double sum = 0.0, p, q, cnt = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", a);
		sscanf(a, "%lf", &p);
		sprintf(b, "%.2lf", p);//数字转字符串
		int flag = 0;
		for(int j = 0; j < strlen(a); j++){
			if(a[j] != b[j]){
				flag = 1;
				break;
			}
		}
		if(flag || p < -1000 || p > 1000)
			printf("ERROR: %s is not a legal number\n", a);
		else{
			cnt++;
			sum += p;
		}
	}
	if(cnt)
		printf("The average of %.0lf number%s is %.2lf\n", cnt, cnt > 1 ? "s" : "", sum / cnt); 
	else
		printf("The average of 0 numbers is Undefined\n");

	return 0;
}
