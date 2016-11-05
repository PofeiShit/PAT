#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 0x7fffffff;
bool comp(int a, int b)
{
	return a > b;
}
int main()
{
	int N, m, n, tmp = maxn;
	scanf("%d", &N);
	int *Num = new int[N];
	for(int i = 0; i < N; i ++)
		scanf("%d", Num + i);
	sort(Num, Num + N, comp);
	for(int i = 1; i * i <= N; i++){
		if(N % i == 0){
			if(N / i - i < tmp){
				tmp = N / i - i;
				m = N / i;
				n = i;
			}
		}
	}
	int circle = n / 2, k = 0;
	int **Matrix = new int *[m];
	for(int i = 0; i < m; i++)
		Matrix[i] = new int[n];
	
	for(int i = 0; i < circle; i++){
		for(int j = i; j < n - i; j++)
			Matrix[i][j] = Num[k++];
		for(int j = i + 1; j < m - i; j++)
			Matrix[j][n - i - 1] = Num[k++];
		for(int j = n - i - 2; j >= i; j--)
			Matrix[m - i - 1][j] = Num[k++];
		for(int j = m - i - 2; j > i; j--)
			Matrix[j][i] = Num[k++];
	}
	for(int i = circle; i < m - circle; i++)
		Matrix[i][circle] = Num[k++];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(j != n - 1)
				printf("%d ", Matrix[i][j]);
			else
				printf("%d\n", Matrix[i][j]);
		}
	}
	for(int i = 0; i != n; i++)
		delete[] Matrix[i];
	delete[] Matrix;
	delete[] Num;
	return 0;
}
