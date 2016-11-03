#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
string N;
int K;
bool isPNumber(string ch)
{
	int left, right;
	int len = ch.length();
	for(left = 0, right = len - 1; left <= right; left++, right--)
		if(ch[left] != ch[right])
			return false;
	return true;
}
string add(string A, string B)
{
	int JinWei = 0, tmp, len;
	char JieGuo;
	len = A.length();
	string s;
	for(int i = len - 1; i >= 0; i--)
	{
		JieGuo = ((A[i] - '0') + (B[i] - '0') + JinWei) % 10 + '0';
		s.insert(s.begin(), JieGuo);
		JinWei = ((A[i] - '0') + (B[i] - '0') + JinWei) / 10;
	}
	if(JinWei == 1)
		s.insert(s.begin(), '1');
	return s;	
}
int main()
{
	string left, right;
	cin>>N>>K;
	for(int i = 0; ; i++){
		if(isPNumber(N))
		{
			cout<<N<<endl<<i;
			return 0;
		}
		else
		{
			if(i == K)
			{
				cout<<N<<endl<<i;
				return 0;
			}
		}
		left = N;		
		reverse(N.begin(), N.end());
		right = N;
		N.clear();
		N = add(left, right);
	}
}
