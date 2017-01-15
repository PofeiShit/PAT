#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
int a[maxn], b[maxn];
int n;
void mergeSort()
{
	int k;
	bool flag = false;
	for(int i = 2; i <= n; i *= 2){
		for(int j = 0; j < n; j += i){
			if(j + i > n)
				sort(a + j, a + n);
			else
				sort(a + j, a + j + i);
		}
		if(flag)
			return;
		for(k = 0; k < n; k++)
			if(a[k] != b[k])
				break;
		if(k == n)
			flag = true;
	}	
}
int main()
{
	int flag = 1, idx = -1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	for(int i = 0; i < n; i++)
		scanf("%d", b + i);
	for(int i = 0; i < n; i++){
		if(b[i] > b[i + 1]){
			idx = i;
			break;
		}
	}
	for(int i = idx + 1; i < n; i++)
		if(a[i] != b[i])
			flag = 0;
	if(flag){
		printf("Insertion Sort\n");
		sort(a, a + idx + 2);
		for(int i = 0; i < n; i++){
			if(i)
				printf(" ");
			printf("%d", a[i]);
		}
	}
	else{
		printf("Merge Sort\n");
		mergeSort();
		for(int i = 0; i < n; i++){
			if(i)
				printf(" ");
			printf("%d", a[i]);
		}
	}
	return 0;
}
