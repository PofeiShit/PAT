#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
int Node[maxn];
int D[maxn];
struct node
{
	int Addr;
	int Data;
	//	int Next;
}List[maxn];
int main()
{
	int i, addr, N, data, K, start, next;
	scanf("%d%d%d", &start, &N, &K);
	for(i = 0; i < N; i++){
		scanf("%d%d%d", &addr, &data, &next);
		Node[addr] = next;
		D[addr] = data;
	}
	for(i = 0; start != -1; i++){
		List[i].Addr = start;
		List[i].Data = D[start];
		//		List[i].Next = Node[start];
		start = Node[start];
	}
	N = i;
	for(i = 1; ; i++){
		if(i * K <= N)
			reverse(List + (i - 1) * K, List + i * K);
		else 
			break;
	}
	for(int j = 0; j < N - 1; j++)
		printf("%05d %d %05d\n", List[j].Addr, List[j].Data, List[j+1].Addr);
	printf("%05d %d -1\n", List[N-1].Addr, List[N-1].Data);
	return 0;
}
