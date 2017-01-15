#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int n;
vector<int> pre, in, pt;
stack<int> p;
void post(int root, int start, int end)
{
	if(start > end)
		return;
	int l = start;
	while(l < end && in[l] != pre[root])
		l++;
	post(root + 1, start, l - 1);
	post(root + (l - start + 1), l + 1, end);
	pt.push_back(pre[root]);
}
int main()
{
	string is;
	int x;
	scanf("%d", &n);
	for(int i = 0; i < 2 * n; i++){
		cin>>is;
		if(is == "Push"){
			cin>>x;
			pre.push_back(x);	
			p.push(x);
		}
		else if(is == "Pop"){
			in.push_back(p.top());
			p.pop();
		}
	}
	post(0, 0, n - 1);
	printf("%d", pt[0]);
	for(int i = 1; i < pt.size(); i++)
		printf(" %d", pt[i]);
	return 0;
}
