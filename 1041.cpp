#include <iostream>
#include <cstdio>
using namespace std;
int V[10010], Data[100010];
int main()
{
	int N, tmp;
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		V[tmp]++;
		Data[i] = tmp;
	}
	int i;
	for(i = 0; i < N; i++)
	{
		tmp = Data[i];
		if(V[tmp] == 1)
		{
			cout<<tmp<<endl;
			break;
		}
	}
	if(i == N)
		cout<<"None"<<endl;
	return 0;
}
