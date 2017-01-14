#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define inf 65536
int win[11][21];
int Time[21];
int N;
int M;
int K;
int Q;
int cus[1100];
int End[1100];
int ask[1100];
int start[1100];
int findmin(int t[], int Num)
{
	int i, min = inf, idx = 0;
	for(i = 1; i <= Num; i++)
	{
		if(min > t[i])
		{
			min = t[i];
			idx = i;	
		}
	}
	return idx;
}
int main()
{
	int idx, quo, rem, i, j, q, k = 1;	
	cin>>N >>M >>K >>Q;
	memset(Time, inf, sizeof(int));

	for(i = 1; i <= K; i++)
	{
		scanf("%d", &cus[i]);
		if(i <= N & i <= K)
		{
			start[i] = 0;	
			Time[i] = cus[i];
			win[1][i] = i;
			k = i;	
		}
	}
	for(i = 1; i <= Q; i++)
		scanf("%d", &ask[i]);
	k ++;
	for(i = 2; i <= M; i++)
	{
		for(j = 1; j <= N; j++)
		{
			if(k <= K)
			{
				win[i][j] = k;//是按照队伍长度来初始化的
				k ++;
			}		
		}
	}
	while(1)	
	{
		i = 2;	
		idx = findmin(Time, N);		
		if(M > 1)//窗口能容纳几个人的情况
		{
			if(win[2][idx] != 0)//还有下一个客户
			{
				End[win[1][idx]] = Time[idx];//上个客户的终止时间	
				win[1][idx] = win[2][idx];	
				start[win[1][idx]] = Time[idx];//下个客户的起始时间 
				Time[idx] += cus[win[1][idx]];//该客户的终止时间
			}
			else
			{
				End[win[1][idx]] = Time[idx];
				Time[idx] = inf;	
			}
		}	
			else
			{
				End[win[1][idx]] = Time[idx];		
				Time[idx] = inf;	
			}	
			
		while(i < M)
		{
			win[i][idx] = win[i + 1][idx];
			i ++;
		}
		if(idx == 0)
			break;
		if(k > K)	
		{
			win[M][idx] = 0;	
		}	
		else	
		{
			win[M][idx] = k;
			k ++;
		}	
	}	
	for(i = 1; i <= Q; i++)
	{
		if(start[ask[i]] < 540)
		{
			quo = End[ask[i]] / 60;
			rem = End[ask[i]] % 60;
			quo += 8;
			if(quo < 10)
				printf("0%d:", quo);
			else
				printf("%d:", quo);
			if(rem < 10)
				printf("0%d\n", rem);
			else
				printf("%d\n", rem);
		}
		else
			printf("Sorry\n");
	}
	return 0;
}
