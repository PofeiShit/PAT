#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 2e5+10;
set<int> Name[maxn]; 
int get(char *s)
{
	return (s[0] - 'A') * 6760 + (s[1] - 'A') * 260 + (s[2] - 'A') * 10 + (s[3] - '0');
}
int main()
{
	int N, K, C, Ni;
	char s[5];
	cin>>N>>K;
	for(int i = 0; i < K; i++){
		scanf("%d%d", &C, &Ni);
		for(int j = 0; j < Ni; j++){
			scanf("%s", s);
			int m = get(s);
			Name[m].insert(C);
		}
	}
	for(int i = 0; i < N; i++){
		scanf("%s", s);
		int m = get(s);
		printf("%s ", s);
		if(Name[m].size()){
			printf("%lu", Name[m].size());
			for(set<int>::iterator itr = Name[m].begin(); itr != Name[m].end(); itr++)
				printf(" %d", *itr);
			printf("\n");
		}	
		else
			printf("0\n");
	}
	return 0;
}
