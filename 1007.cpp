#include<iostream>
using namespace std;
int main()
{
	int k, flag = 0, idxf, idxl = -1, ThisSum = 0, MaxSum = 0;
	cin>>k;
	idxf = k;	
	int *seq = new int[k];
	for(int i = 0; i < k; i++)	
	{
		cin>>*(seq + i);	
	}
	for(int i = 0; i < k; i++)
	{
		ThisSum += *(seq + i);
		if(ThisSum > MaxSum)
		{
			MaxSum = ThisSum;	
			idxl = i;
		}
		if(ThisSum < 0)
		{
			flag ++;	
			ThisSum = 0;
		}	
	}
	if(flag == k)
	{
		idxl = k - 1;
		idxf = 0;
		MaxSum = 0;
	}
	int i = 0;	
	if(idxf == k && idxl == -1)
	{
		while(1)
		{
			if(*(seq + i) == 0)
			{
				idxf = i;
				idxl = i;
				cout<<MaxSum<<' '<<*(seq + idxf)<<' '<<*(seq + idxl)<<endl;
				return 0;	
			}
			else
				i ++;
		}
	}
	flag = 0;
	for(k = idxl; k >= 0; k --)
	{
		flag += *(seq + k);
		if(flag == MaxSum)
			idxf = k;
	}
	cout<<MaxSum<<' '<<*(seq + idxf)<<' '<<*(seq + idxl)<<endl;
}
