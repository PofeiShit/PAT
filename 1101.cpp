#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
int Ori[maxn];
int Sort[maxn];
vector<int> ans;
int main()
{
	int N, tmp, max = -1;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &tmp);
		Ori[i] = tmp;
		Sort[i] = tmp;
	}
	sort(Sort, Sort + N);
	int cnt = 0;
	for(int i = 0; i < N; i++){
		tmp = Ori[i];
		max = max > tmp ? max : tmp;
		if(tmp == Sort[i] && max == tmp){
			cnt++;
			ans.push_back(tmp);
		}
	}
	if(cnt == 0)
		printf("0\n\n");
	else{
		printf("%d\n", cnt);
		int i;
		for(i = 0; i < ans.size() - 1; i++)
			printf("%d ", ans[i]);
		printf("%d", ans[i]);
	}
	return 0;
}
