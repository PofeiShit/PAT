#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 2510;
vector<int> Course[maxn];
int get(char *s)
{
	return (s[0] - 'A') * 6760 + (s[1] - 'A') * 260 + (s[2] - 'A') * 10 + (s[3] - '0');
}
void print(int m)
{
	printf("%c%c%c%d\n", m / 6760 + 'A', m % 6760 / 260 + 'A', m % 6760 % 260 / 10 + 'A', m % 6760 % 260 % 10);
}
int main()
{
	int N, K, C, Ci;
	char s[5];
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++){
		scanf("%s%d", s, &C);
		int m = get(s);
		for(int j = 0; j < C; j++){
			scanf("%d", &Ci);
			Course[Ci].push_back(m); 
		}
	}
#if 0
set<char*> Name;
map<int, set<char*> > Course;
int main()
{
	int N, K, C, Ci;
	char s[40010][5];
	string name;
	cin>>N>>K;
	for(int i = 0; i < N; i++){
		scanf("%s %d", s[i], &C);
		for(int j = 0; j < C; j++){
			scanf("%d", &Ci);
			Name = Course[Ci];
		//	name = s;
			Name.insert(s[i]);
			Course[Ci] = Name;
			Name.clear();
		}
	}
#endif
	for(int i = 1; i <= K; i++){
		printf("%d %lu\n", i, Course[i].size());
		sort(Course[i].begin(), Course[i].end());
		for(int j = 0; j < Course[i].size(); j++)
			print(Course[i][j]);
	}
	return 0;
}

