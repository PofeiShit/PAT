#include <iostream>
#include <cstring>
#include <set>
using namespace std;
set<int> t;
int main()
{
	string s;
	cin>>s;
	int n1, n2, n3, k, N;
	N = s.length();
	for(n2 = 3; n2 <= N; n2++)
	{
		for(k = 0; k <= n2; k++)
		{
			n1 = n3 = k;
			if(n1 + n3 + n2 - 2 == N)
				t.insert(k);
		}
	}
	n1 = n3 = *(t.end());
	n2 = N + 2- n1 - n3;
	for(int i = 0; i < n1 - 1; i++){
		for(int j = 0; j < n2; j++){
			if(j == 0)
				cout<<s[j + i];
			else if(j == n2 - 1)
				cout<<s[N - i - 1];
			else
				cout<<' ';
		}
		cout<<endl;
	}
	for(int i = 0; i < n2; i++)
		cout<<s[n1 - 1 + i];
	return 0;
}
