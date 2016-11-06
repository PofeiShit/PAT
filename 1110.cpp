#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 25;
int Vis[maxn];
int Tree[maxn];
int Son[maxn][2];
bool flag = true;
int N;
void buildTree(int root, int pos)
{
	if(flag){
		int left = 0, right = 1;
		if(Son[root][left] != -1){
			if(pos < N){
				buildTree(Son[root][left], 2 * pos + 1);
				Tree[2 * pos + 1] = Son[root][left];
			}
			else{
				flag = false;
				return ;
			}
		}
		if(Son[root][right] != -1){
			if(pos < N){
				buildTree(Son[root][right], 2 * pos + 2);
				Tree[2 * pos + 2] = Son[root][right];
			}
			else{
				flag = false;
				return ;
			}
		}
	}
	return ;
}
void getSon(string c, int i, int s)
{
	if(c[0] == '-')
		Son[i][s] = -1;
	else{
		int tmp = atoi(c.c_str());
		Son[i][s] =  tmp;
		Vis[tmp] = 1;
	}
}
int main()
{
	int root, j;
	string l, r;
	scanf("%d", &N);
	for(j = 0; j < N; j++){
		cin>>l>>r;
		getSon(l, j, 0);
		getSon(r, j, 1);
	}
	memset(Tree, -1, sizeof(Tree));
	for(int i = 0; i < N; i++){
		if(Vis[i] == 0){
			root = i;
			break;
		}
	}
	Tree[0] = root;
	buildTree(root, 0);
	for(int i = 0; i < N; i++){
		if(Tree[i] == -1){
			flag = false;
			break;
		}
	}
	if(flag)
		printf("YES %d", Tree[N - 1]);
	else
		printf("NO %d", root);
	return 0;
}
