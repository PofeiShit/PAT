#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 4e4 + 5; 
const int maxm = 110;
int q[maxm], ans[maxn]; 
vector<int> m[maxm];
struct stu
{
	int id;
	int Ge;
	int Gi;
	vector<int> c;
}Stu[maxn];
bool cmp(const int& A, const int& B)
{
	return Stu[A].Ge + Stu[A].Gi == Stu[B].Ge + Stu[B].Gi ? Stu[A].Ge > Stu[B].Ge : Stu[A].Ge + Stu[A].Gi > Stu[B].Ge + Stu[B].Gi;
}
bool equ(const int& a, const int& b)
{
	return Stu[a].Ge + Stu[a].Gi == Stu[b].Ge + Stu[b].Gi && Stu[a].Gi == Stu[b].Gi;
}
int main()
{
	int n,M,k,sch;
	scanf("%d%d%d", &n, &M, &k);
	for(int i = 0; i < M; i++)
		scanf("%d", q + i);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &Stu[i].Ge, &Stu[i].Gi);
		for(int j = 0; j < k; j++){
			scanf("%d", &sch);
			Stu[i].c.push_back(sch);
		}
		ans[i] = i;
	}	
	sort(ans, ans + n, cmp);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int x = Stu[ans[i]].c[j];
			if(m[x].size() < q[x] || equ(m[x][m[x].size() - 1], ans[i])){
				m[x].push_back(ans[i]);
				break;
			}
		}
	}
	for(int i = 0; i < M; i++){
		sort(m[i].begin(), m[i].end());
		if(m[i].empty())
			printf("\n");
		else{
			for(int j = 0; j < m[i].size(); j++){
				if(j)
					printf(" ");
				printf("%d", m[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
