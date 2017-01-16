#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int a = 1e9+7;
string is;
int main()
{
	cin>>is;	
	int flagP = 0, flagA = 0; 
	long long int cntP = 0, cntPA = 0, cntPAT = 0, precnt = 0;

	for(int i = 0; i < is.length(); i++){	
		if(is[i] == 'P'){
			flagP = 1;
			cntP++;
		}
		if(flagP && is[i] == 'A'){
			flagA = 1;
			cntPA += cntP;
		}
		if(flagP && flagA && is[i] == 'T'){
			cntPAT += cntPA;
		}
	}
	printf("%d", cntPAT % a);
	return 0;
}
