#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int, int> Color;
int main()
{
	int M, N, c;
	scanf("%d%d", &M, &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d", &c);
			int tmp = Color[c];
			tmp++;
			Color[c] = tmp;
		}
	}
	int max = -1;
	for(map<int, int>::iterator itr = Color.begin(); itr != Color.end(); itr++){
		if(itr->second > max){
			max = itr->second;
			c = itr->first;
		}
	}
	printf("%d", c);
	return 0;
}
