#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)
#define PARENT(i) (i / 2)
const int maxn = 110;
int n;
int is[maxn], sorted[maxn], hs[maxn];
bool isInsertionSort(int A[], int N)
{
	int j;
	bool flag = false;
	for(int i = 2; i <= N; i++){
		sort(A, A + i);
		if(flag)
			break;
		for(j = 0; j < N; j++){
			if(A[j] != sorted[j])
				break;
		}
		if(j == N)
			flag = true;
	}
	return flag;
}
void swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void maxHeap(int A[], int i, int heapsize)
{
	int l = LEFT(i), r = RIGHT(i), largest = -1;
	if(l <= heapsize && A[l] > A[i]) 
		largest = l;
	else
		largest = i;
	if(r <= heapsize && A[r] > A[largest])
		largest = r;
	if(largest != i){
		swap(A[i], A[largest]);
		maxHeap(A, largest, heapsize);
	}
}
void buildMaxHeap(int A[], int heapsize)
{
	for(int i = heapsize / 2; i >= 1; i--)
		maxHeap(A, i, heapsize);
}
void HeapSort(int A[], int n)
{
	int heapsize = n, j;
	buildMaxHeap(A, heapsize);
	for(int i = n; i >= 2; i--){
		swap(A[1], A[i]);
		heapsize--;
		maxHeap(A, 1, heapsize);
		for(j = 1; j <= n; j++){
			if(A[j] != sorted[j - 1])
				break;
		}
		if(j == n + 1){
			swap(A[1], A[i - 1]);
			heapsize--;
			maxHeap(A, 1, heapsize);
			break;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", is + i);
		hs[i + 1] = is[i];
	}
	for(int i = 0; i < n; i++)
		scanf("%d", sorted + i);
	if(isInsertionSort(is, n)){
		printf("Insertion Sort\n");
		for(int i = 0; i < n; i++){
			if(i)
				printf(" ");
			printf("%d", is[i]);
		}
	}
	else{
		printf("Heap Sort\n");
		HeapSort(hs, n);
		for(int i = 0; i < n; i++){
			if(i)
				printf(" ");
			printf("%d", hs[i + 1]);
		}
	}
	return 0;
}
