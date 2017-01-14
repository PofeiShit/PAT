#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int N, M, tmp[4], i, j, k, score, idx = 0, rank = 1;
	double **p;
	char course;
	string *s1, *s2;
	scanf("%d %d", &N, &M);	
	p = new double *[N];
	s1 = new string [N];
	s2 = new string [M];
	for(i = 0; i < N; i ++)
	{
		p[i] = new double [4];
	}
	cin.get();
	i = N;	
	while(i)
	{
		cin>>s1[N - i] >>p[N - i][0] >>p[N - i][1] >>p[N - i][2];	
		p[N - i][3] = (p[N - i][0] + p[N - i][1] + p[N - i][2]) / 3;
		i --;
	}
	i = M;
	while(i)
	{
		cin>>s2[M - i];	
		i--;	
	}
	for(i = 0; i < M; i++)
	{
		j = 0;	
		while(1)
		{
			if((s2[i].compare(s1[j])) == 0)
			{//找得到对应的学号
				for(k = 0; k < 4; k ++)			
				{//C,M,E,A
					idx = 0;//学号
					rank = 1;
					while(idx < N)
					{
						score = p[idx][k];
						if(score > p[j][k])//p[j][k]表示目前学号
							rank++;
						idx++;	
					}		
					tmp[k] = rank;		
				}
				rank = tmp[3];
				course = 'A';	
				if(tmp[0] < rank)
				{
					rank = tmp[0];
					course = 'C';	
				}	
				if(tmp[1] < rank)
				{
					rank = tmp[1];
					course = 'M';	
				}	
				if(tmp[2] < rank)
				{
					rank = tmp[2];
					course = 'E';	
				}
				printf("%d %c\n",  rank, course);
				break;		
			}
			else
			{
				j++;
				if(j == N)
				{
					printf("N/A\n");	
					break;	
				}	
			}

		}

	}
	return 0;
}
