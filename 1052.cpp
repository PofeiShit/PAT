#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
struct node
{
	int Addr;
	int Key;
}List[maxn];
int Node[maxn];
int Value[maxn];
bool comp(struct node A, struct node B)
{
	return A.Key < B.Key;
}
int main()
{
	int N, s, Addr, Key, Next;
	scanf("%d%d", &N, &s);
	for(int i = 0; i < N; i++){
		scanf("%d%d%d", &Addr, &Key, &Next);
		Node[Addr] = Next;
		Value[Addr] = Key;
	}
	if(s == -1)
		printf("0 -1");
	else{
		int j = 0;
		while(s != -1){
			List[j].Addr = s;
			List[j].Key = Value[s];
			s = Node[s];
			j++;
		}
		sort(List, List + j, comp);
		printf("%d %05d\n", j, List[0].Addr);
		for(int i = 0; i < j - 1; i++)
			printf("%05d %d %05d\n", List[i].Addr, List[i].Key, List[i+1].Addr);
		printf("%05d %d -1", List[j-1].Addr, List[j-1].Key);
	}
	return 0;
}	
