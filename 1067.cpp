#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int maxn = 1e5+10;
int Sort[maxn];
set<int> is;
int main()
{
	int N, i, num, s, cnt = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &s);
		Sort[s] = i;
		if(s != i && i != 0)
			is.insert(i);
	}
	s = Sort[0];
	while(1){
		if(Sort[0] != 0){
			int pos = Sort[s];
			Sort[0] = pos;
			Sort[s] = s;
			is.erase(s);
			s = pos;
			cnt++;
		}
		else{
			if(!is.empty()){
				i = *(is.begin());
				s = Sort[i];
				Sort[0] = s;
				Sort[i] = 0;
				cnt++;
			}
			else
				break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
