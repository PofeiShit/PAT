#include <iostream>
#include <cstdio>
using namespace std;
int Node[100010];
int vis[100010];
int main()
{
	int i = 0, j = 0, N, addr1, addr2, addr, next;
	char data;
	int List1[100010];
	int List2[100010];
	cin>>addr1>>addr2>>N;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &addr);
		cin>>data;
		scanf("%d", &next);
		Node[addr] = next;
	}
	while(1)
	{
		if(addr1 != -1)
		{
			List1[i] = addr1;
			vis[addr1]++;
			addr1 = Node[addr1];
			i++;
		}
		if(addr2 != -1)
		{
			List2[j] = addr2;
			vis[addr2]++;
			addr2 = Node[addr2];
			j++;
		}
		if(addr1 == -1 && addr2 == -1)
			break;
	}
	for(i = 0; i <= j; i++)
	{
		if(vis[List2[i]] == 2)
		{
			printf("%05d", List2[i]);
			break;
		}
	}
	if(i > j)
		printf("-1");
	return 0;
}
