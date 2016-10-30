#include <iostream>
#include <cstring>
using namespace std;
int main()
{
#if 0
	long long N;
	cin>>N;
	int cnt = 0;
	for(int i = 1; i <= N; i++)
	{
		int tmp = i;
		while(tmp != 0)
		{
			if(tmp % 10 == 1)
				cnt++;
			tmp /= 10; 
		}
	}
#endif
	int N, rem, right = 0;
	cin>>N;
	int cnt = 0, pos = 1;
	while(N)
	{
		rem = N % 10;	
		N /= 10;
		if(rem == 0)	
			cnt += N * pos;
		else if(rem == 1)
			cnt += N * pos + right + 1;
		else
			cnt += (N + 1) * pos;
		right += rem * pos;
		pos *= 10;
	}
	cout<<cnt<<endl;
	return 0;
}
