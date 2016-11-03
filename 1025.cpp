#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct person
{
	char ID[15];
	int score;
	int location;
	int localRank;
	int finalRank;
}Person[30010];
bool comp(struct person A, struct person B)
{
	if(A.score > B.score)
		return true;
	else if(A.score == B.score)
	{
		if(strcmp(A.ID, B.ID) < 0)
			return true;
	}
	return false;
}
int main()
{
	int N,K, pos = 0, rank = 1;
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		cin>>K;
		for(int j = pos; j < pos + K; j++)
		{
			scanf("%s%d", Person[j].ID, &Person[j].score);
			Person[j].location = i+1;
		}
		sort(Person + pos, Person + pos + K, comp);
		Person[pos].localRank = rank; 
		for(int j = pos + 1; j < pos + K; j++)
		{
			if(Person[j].score == Person[j - 1].score)
			{
				Person[j].localRank = Person[j - 1].localRank;
				rank++;
				continue;
			}
			rank ++;
			Person[j].localRank = rank;
		}
		pos += K; 
		rank = 1;
	}
	sort(Person, Person + pos, comp);
	Person[0].finalRank = rank;
	for(int j = 1; j < pos; j++)
	{
		if(Person[j].score == Person[j - 1].score)
		{
			Person[j].finalRank = Person[j - 1].finalRank;
			rank++;
			continue;
		}
		rank++;
		Person[j].finalRank = rank;
	}
	cout<<pos<<endl;
	for(int j = 0; j < pos; j++)
		printf("%s %d %d %d\n", Person[j].ID, Person[j].finalRank, Person[j].location, Person[j].localRank);
	return 0;
}
