#include <sstream>
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int M, i = 0, IDmin, IDmax, k = 0, min = 0x7fffffff, max = 0, HH, MM, SS;
	string sTmp;
	scanf("%d", &M);	
	cin.get();
	string *s = new string[3 * M];	
	for(i = 0; i < M; i++)
	{
		k = 0;	
		getline(cin, sTmp);	
		istringstream istr(sTmp);
		while(!istr.eof())
		{
			istr>>sTmp;
			*(s + 3 * i + k) = sTmp;		
			k ++;	
		}
	}
	for(i = 0; i < M; i ++)
	{
		sTmp = *(s + 3 * i + 1);
		HH = (sTmp[0] - 48) * 10 + (sTmp[1] - 48);
		MM = (sTmp[3] - 48) * 10 + (sTmp[4] - 48);
		SS = (sTmp[6] - 48) * 10 + (sTmp[7] - 48);
		k = HH * 3600 + MM * 60 + SS;
		if( k < min )
		{		
			IDmin = i;
			min = k;
		}
		sTmp = *(s + 3 * i + 2);
		HH = (sTmp[0] - 48) * 10 + (sTmp[1] - 48);
		MM = (sTmp[3] - 48) * 10 + (sTmp[4] - 48);
		SS = (sTmp[6] - 48) * 10 + (sTmp[7] - 48);
		k = HH * 3600 + MM * 60 + SS;
		if( k > max )
		{		
			IDmax = i;
			max = k;
		}
	}
	cout<<*(s + 3 * IDmin)<<' '<<*(s + 3 * IDmax)<<endl;
	return 0;
}
