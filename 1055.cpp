#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10; 
struct fobes
{
	string name;
	int age;
	int worth;
}F[maxn];
bool cmp(const fobes& A, const fobes& B)
{
	if(A.worth > B.worth)
		return true;
	else if(A.worth == B.worth){
		if(A.age < B.age)
			return true;
		else if(A.age == B.age){
			return A.name < B.name;
		}
	}
	return false;
}
int main()
{
	int n, k, m, min, max, cnt = 0;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		cin >> F[i].name;
		scanf("%d%d", &F[i].age, &F[i].worth);
	}
	sort(F, F + n, cmp);
	for(int i = 1; i <= k; i++){
		scanf("%d%d%d", &m, &min, &max);
		printf("Case #%d:\n", i);
		for(int i = 0; i < n; i++){
			if(cnt < m){
				if(min <= F[i].age && F[i].age <= max){
					cout << F[i].name;
					printf(" %d %d\n", F[i].age, F[i].worth);
					cnt++;
				} 
			} else 
				break;
		}
		if(cnt == 0)
			printf("None");
		cnt = 0;
	}
	return 0;
}
