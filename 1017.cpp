#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e4 + 10;
int N, K;
#define inf 0x7fffff 
#define OPEN_TIME  28800//8 * 3600
#define CLOSE_TIME 61200//17 * 3600
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
struct T
{
	int HH;
	int MM;
	int SS;
	int P;
}Time[maxn];
bool comp(struct T A, struct T B)
{
	if(A.HH < B.HH)
		return true;
	else if(A.HH == B.HH)
	{
		if(A.MM < B.MM)
			return true;
		else if(A.MM == B.MM)
			return A.SS < B.SS;
	}
	return false;
}
int findmin(int *Comp)
{
	int idx = -1;
	int M = inf;
	for(int i = 0; i < K; i++)
	{
		if(*(Comp + i) < M)
		{
			idx = i;
			M = *(Comp + i);
		}
	}
	return idx;
}
int main()
{
	cin>>N>>K;
	double WaitTime = 0;
	double cnt = 0;
	int *completeTime = new int[K];
	for(int i = 0; i < N; i++)
		scanf("%d:%d:%d %d", &Time[i].HH, &Time[i].MM, &Time[i].SS, &Time[i].P);
	sort(Time, Time + N, comp);
	memset(completeTime, inf, sizeof(completeTime));
	for(int i = 0; i < N; i++)
	{
		int Tmp = Time[i].HH * 3600 + Time[i].MM * 60 + Time[i].SS;
		if(i < K && Tmp <= CLOSE_TIME)
		{
			if(Tmp < OPEN_TIME)
				WaitTime += (OPEN_TIME - Tmp);	
			*(completeTime + i) = max(Tmp, OPEN_TIME) + min(Time[i].P, 60) * 60; 				
			cnt++;
			continue;
		}
		int idx = findmin(completeTime);
		int cTime = *(completeTime + idx);
		if(Tmp <= CLOSE_TIME)
		{
//			if(cTime > CLOSE_TIME)//几个人的完成时间都超过5点，4点50进门的人的等待时间是10分钟还是10分钟1妙
//				WaitTime += CLOSE_TIME - Tmp;
			//5点还是可以服务完最后一波人
			//这个代码竟然就Ac了，还有一个常识就是3个窗口的服务完成时间都过了5点，然后有个人到达的时间是4点50，应该等到5点就结束，而不是等到所有窗口结束服务。真是不合理的设计测试用例。
			if(cTime >= Tmp)//到达时间小于在服务时间内
			{
				WaitTime += cTime - Tmp;
				*(completeTime + idx) += min(Time[i].P, 60) * 60;
			}
			else
				*(completeTime + idx) = Tmp + min(Time[i].P , 60) * 60;
			cnt++;
		}
	}
	if(cnt != 0)
		printf("%.1lf\n", WaitTime / (cnt * 60));
	delete[] completeTime;
#if 0
	for(int i = 0; i < N; i++)
		printf("%d:%d:%d %d\n", Time[i].HH, Time[i].MM, Time[i].SS, Time[i].P);
#endif	
	return 0;
}
