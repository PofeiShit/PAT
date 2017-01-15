#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct stu
{
	string name;
	string id;
	int score;
	bool operator < (const stu& A) const
	{
		return score > A.score;
	}
};
int main()
{
	int n, grade1, grade2;
	scanf("%d", &n);
	stu *Stu = new struct stu [n];
	for(int i = 0; i < n; i++){
		cin>>(Stu + i)->name;
		cin>>(Stu + i)->id;
		scanf("%d", &((Stu + i)->score));
	}
	scanf("%d%d", &grade1, &grade2);
	sort(Stu, Stu + n);
	if(Stu->score < grade1 || (Stu + n - 1)->score > grade2)
		printf("NONE");
	else{
		for(int i = 0; i < n; i++){
			if((Stu + i)->score <= grade2 && (Stu + i)->score >= grade1)
				cout << (Stu + i)->name << " " << (Stu + i)->id << endl;
		}
	}
	delete []Stu;
	return 0;
}
