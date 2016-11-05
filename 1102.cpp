#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
vector<int> ans;
const int maxn = 1024;
int Tree[maxn];
char Node[11][2];
bool vis[11];
int level = 0;
void inOrder(int pos)
{
	if(Tree[2 * pos + 1] != -1)
		inOrder(2 * pos + 1);
	ans.push_back(Tree[pos]);	
	if(Tree[2 * pos + 2] != -1)
		inOrder(2 * pos + 2);
	return ;
}
void print()
{
	int j;
	for(j = 0; j < ans.size() - 1; j++)
		printf("%d ", ans[j]);
	printf("%d\n", ans[j]);
	ans.clear();
}
void build(char r, int pos)
{
	int left, right, root = r - '0';
	level++;
	if(Node[root][0] != '-'){
		left = Node[root][0];
		build(left, 2 * pos + 1); 
		Tree[2 * pos + 1] = left - '0';
	}
	if(Node[root][1] != '-'){
		right = Node[root][1];
		build(right, 2 * pos + 2);
		Tree[2 * pos + 2] = right - '0';
	}
	return ;
}
int main()
{
	int N, root;
	char left, right;
	scanf("%d", &N);
	memset(Tree, -1, sizeof(Tree));
	for(int i = 0; i < N; i++){
		cin>>left>>right;
		Node[i][0] = right;
		Node[i][1] = left;
		if(left != '-')
			vis[left - '0'] = 1;
		if(right != '-')
			vis[right - '0'] = 1;
	}
	for(int i = 0; i < N; i++){
		if(vis[i] != 1){
			root = i;
			break;
		}
	}
	Tree[0] = root;	
	build(root + '0', 0);
	for(int i = 0; i < pow(2, level) - 1; i++){
		if(Tree[i] != -1)
			ans.push_back(Tree[i]);
	}
	print();
	inOrder(0);
	print();	
	return 0;
}
