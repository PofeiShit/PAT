#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int Number;
int main()
{
	char name[15], gender[3], ID[15], male[15], female[15], mId[15], fId[15];
	int grade, m = 101, f = -1;
	cin>>Number;
	for(int i = 0; i < Number; i++)
	{
		scanf("%s%s%s%d", name, gender, ID, &grade);
		if(gender[0] == 'M')
		{
			if(grade < m)
			{
				m = grade;
				memset(male, '0', sizeof(male));
				strcpy(male, name);
				memset(mId, '0', sizeof(mId));
				strcpy(mId, ID);
			}
		}
		else 
		{
			if(grade > f)
			{
				f = grade;
				memset(female, '0', sizeof(female));
				strcpy(female, name);
				memset(fId, '0', sizeof(fId));
				strcpy(fId, ID);
			}
		}
	}
	if(f == -1)
	{
		printf("Absent\n");
		printf("%s %s\n", male, mId);
		printf("NA");
	}
	else if(m == 101)
		printf("%s %s\nAbsent\nNA", female, fId);
	else
		printf("%s %s\n%s %s\n%d", female, fId, male, mId, f-m);
	return 0;
}
