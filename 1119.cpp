#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 35;
int n, unique = 1;
int pre[maxn], post[maxn];
vector<int> ans;
int findPre(int root, int prel, int prer)
{
	for(int i = prel; i <= prer; i++){
		if(pre[i] == root)
			return i;
	}
	return -1;
}
void setIn(int prel, int prer, int postl, int postr)
{
	if(prel == prer){
		ans.push_back(pre[prel]);		
		return ;
	}
	if(pre[prel] == post[postr]){
		int x = findPre(post[postr - 1], prel + 1, prer);
		if(x - prel > 1){
			setIn(prel + 1, x - 1, postl, postl + x - prel - 2);
			ans.push_back(post[postr]);
			setIn(x, prer, postl + x - prel - 1, postr - 1);

		} else {
			unique = 0;
			ans.push_back(post[postr]);
			setIn(x, prer, postl + x - prel - 1, postr - 1);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", pre + i);
	for(int i = 0; i < n; i++)
		scanf("%d", post + i);
	setIn(0, n - 1, 0, n -1);
	if(unique)
		printf("Yes\n");
	else 
		printf("No\n");
	for(int i = 0; i < ans.size(); i++){
		if(i)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
