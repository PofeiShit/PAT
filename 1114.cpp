#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
const int maxn = 1e5;
vector<int> fam[maxn];
map<int, set<int> > ans;
set<int> tmp;
set<int> Id;
int M[maxn], Area[maxn], vis[maxn];
struct f
{
	int id;
	int m;
	double avg_sets;
	double avg_area;
}fmy[maxn];
bool comp(struct f A, struct f B)
{
	if(A.avg_area > B.avg_area)
		return true;
	else if(A.avg_area == B.avg_area)
		return A.id < B.id;
	return false;
}
void dfs(int x)
{
	if(vis[x]) 
		return;
	vis[x] = 1;
	tmp.insert(x);
	for(int i = 0; i < fam[x].size(); i++){
			dfs(fam[x][i]);
	}
}
int main()
{
	int n, id, k, f, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d", &id, &f, &m, &k);
		Id.insert(id);
		if(f != -1){
			fam[f].push_back(id);
			fam[id].push_back(f);
			Id.insert(f);
		}
		if(m != -1){
			fam[m].push_back(id);
			fam[id].push_back(m);
			Id.insert(m);
		}
		for(int j = 0; j < k; j++){
			int son;
			scanf("%d", &son);
			fam[id].push_back(son);
			fam[son].push_back(id);
			Id.insert(son);
		}
		scanf("%d%d", &M[id], &Area[id]);
	}
	int idx = 0;
	double tot = 0, sum = 0;
	for(set<int>::iterator itr = Id.begin(); itr != Id.end() ; itr++){
		id = *itr;
		if(!vis[id]){
			dfs(id);
			ans[idx] = tmp;
			tmp.clear();
			idx++;
		}
	}
	printf("%d\n", idx);
	for(int i = 0; i < idx; i++){
			tmp = ans[i];
			int cnt = tmp.size();
			fmy[i].id = *tmp.begin();
			fmy[i].m = cnt;
			for(set<int>::iterator itr = tmp.begin(); itr != tmp.end(); itr++){
				int id = *itr;
				if(M[id] != 0){
					tot += M[id];
					sum += Area[id];
				}
			}
			fmy[i].avg_sets = tot / cnt;
			fmy[i].avg_area = sum / cnt;
			tot = 0;
			sum = 0;
	}
	sort(fmy, fmy + idx, comp);
	for(int i = 0; i < idx; i++)
		printf("%04d %d %.3lf %.3lf\n", fmy[i].id, fmy[i].m, fmy[i].avg_sets, fmy[i].avg_area);
	return 0;
}
