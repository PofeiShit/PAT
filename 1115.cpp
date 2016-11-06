#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
typedef struct tree *Tree;
vector<int>  ans(1010);
int maxdepth = -1;
struct tree
{
	int x;
	Tree left;
	Tree right;
};
Tree Insert(Tree NewTree, int Key)
{
	if(NewTree == NULL){
		NewTree = new struct tree;
		if(NewTree == NULL)
			printf("Out of memory!!!");
		else{
		NewTree->x = Key;
		NewTree->left = NULL;
		NewTree->right = NULL;
		}
	}
	else if(NewTree->x < Key)
		NewTree->right = Insert(NewTree->right, Key);
	else if(NewTree->x >= Key)
		NewTree->left = Insert(NewTree->left, Key);
	return NewTree;
}
void DFS(Tree t, int depth)
{
	if(t == NULL){
		maxdepth = max(depth, maxdepth);
		return ;
	}
	ans[depth]++;
	DFS(t->left, depth + 1);
	DFS(t->right, depth + 1);
}
int main()
{
	Tree T = NULL;
	int N, node, i, j;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &node);
		T = Insert(T, node); 
	}
	int root = T->x, cnt;
	DFS(T, 0);
	printf("%d + %d = %d\n", ans[maxdepth - 1], ans[maxdepth - 2], ans[maxdepth - 1] + ans[maxdepth - 2]);
	return 0;
}
