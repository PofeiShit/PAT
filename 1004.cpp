#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100 
int Level[MAX];
int Node[MAX];
int NonL[MAX];
int main()
{
	int i, N, M, k, Maxlev = 0, root, son, flag = 0, level = 0;
	memset(Node, -1, sizeof(Node));	
	memset(Level, 0, sizeof(Level));	
	memset(NonL, 0, sizeof(NonL));
	cin>>N>>M;
	if(N == 1)
	{	
		cout<<1<<endl;
		return 0;
	}	
	while(M--)	
	{
		cin>>root>>k;
		NonL[root] = 1;	
		while(k--)
		{
			cin>>son;
			Node[son] = root;
		}	
	}	
	root = 01;
	i = 2;
	while(1)
	{
		if(i > N)
		{
			Node[root] = -1;	
			if(NonL[root] == 0)	
				Level[level] ++;	
			Maxlev = Maxlev < level ? level : Maxlev;	
			level = 0;	
			i = 2;
			root = 01;		
			flag ++;	
		}
		if( flag == N - 1)
			break;	
		if(Node[i] == root)
		{
			root = i;
			i = 2;	
			level ++;	
		}
		else
			i ++;	
	}
	for(i = 0; i < Maxlev; i ++)
		cout<<Level[i]<<' ';
	cout<<Level[Maxlev];
	return 0;
}
