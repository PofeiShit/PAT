#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char change(int r)
{
	if(r < 10)
		return (r + '0');
	else
		return (r - 10 + 'A');
}
string Convert(int C)
{
	int rem;
	string s;
	while(C){
		rem = C % 13;
		s.insert(s.begin(), change(rem));
		C /= 13;
	}
	if(s.length() == 1)
		s.insert(s.begin(), '0');
	return s;
}
int main()
{
	int R,G,B;
	string sR, sG, sB;
	cin>>R>>G>>B;
	if(R == 0)
		sR = "00";
	else
		sR = Convert(R);
	if(G == 0)
		sG = "00";
	else
		sG = Convert(G);
	if(B == 0)
		sB = "00";
	else
		sB = Convert(B);
	cout<<'#'<<sR<<sG<<sB;
	return 0;
}
