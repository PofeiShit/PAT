#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct person
{
	int ID;
	char name[10];
	int grade;
}Person[100010];
bool compID(struct person A, struct person B)
{
	return A.ID < B.ID;
}
bool compName(struct person A, struct person B)
{
	if(strcmp(A.name, B.name) < 0)
		return true;
	else if(strcmp(A.name, B.name) == 0){
		return A.ID < B.ID;
	}
	return false;
}
bool compGrade(struct person A, struct person B)
{
	if(A.grade < B.grade)
		return true;
	else  if(A.grade == B.grade){
		return A.ID < B.ID;	
	}
	return false;
}
int main()
{
	int N,C;
	cin>>N>>C;
	for(int i = 0; i < N; i++)
		scanf("%d%s%d", &Person[i].ID, Person[i].name, &Person[i].grade);
	if(C == 1)
		sort(Person, Person + N, compID);
	else if(C == 2)
		sort(Person, Person + N, compName);
	else
		sort(Person, Person + N, compGrade);
	for(int i = 0; i < N; i++)
		printf("%06d %s %d\n", Person[i].ID, Person[i].name, Person[i].grade);
	return 0;
}
