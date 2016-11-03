#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct person
{
	int ID;
	string Title;
	string Author;
	string Keywords;
	string Publisher;
	int Year;
}Person[10010];
bool comp(struct person A, struct person B)
{
	return A.ID < B.ID;
}
int main()
{
	int N, M;
	string s,tmp;
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		cin>>Person[i].ID;
		getchar();	
		getline(cin, Person[i].Title, '\n');
		getline(cin, Person[i].Author,'\n');
		getline(cin, Person[i].Keywords, '\n');
		getline(cin, Person[i].Publisher, '\n');
		cin>>Person[i].Year;
	}
	sort(Person, Person + N, comp);
	cin>>M;
	cin.get();
	int flag = 0;
	for(int i = 0; i < M; i++)
	{
		getline(cin, s, '\n');
		cout<<s<<endl;	
		int idx = s[0] - '0';	
		tmp = s.assign(s.begin() + 3, s.end());
		switch(idx)
		{
			case 1:
				for(int j = 0; j < N; j++)
				{
					if(Person[j].Title == tmp){
						printf("%07d\n", Person[j].ID);
						flag = 1;
					}
				}
				if(!flag)	
					printf("Not Found\n");
				break;
			case 2:
				for(int j = 0; j < N; j++)
				{
					if(Person[j].Author == tmp){
						printf("%07d\n", Person[j].ID);
						flag = 1;
					}
				}
				if(!flag)
					printf("Not Found\n");
				break;
			case 3:
				for(int j = 0; j < N; j++)
				{
					int pos = Person[j].Keywords.find(tmp);
					if(pos != string::npos)				
					{
						printf("%07d\n", Person[j].ID);
						flag = 1;
					}
				}
				if(!flag)
					printf("Not Found\n");
				break;
			case 4:
				for(int j = 0; j < N; j++)
				{
					if(Person[j].Publisher == tmp){
						printf("%07d\n", Person[j].ID);
						flag = 1;
					}
				}
				if(!flag)
					printf("Not Found\n");
				break;
			case 5:
				for(int j = 0; j < N; j++)
				{
					if(Person[j].Year == atoi(tmp.c_str())){
						printf("%07d\n", Person[j].ID);
						flag = 1;
					}
				}
				if(!flag)
					printf("Not Found\n");
				break;
			default: break;
		}
		flag = 0;
		s.clear();
	}
	return 0;
}
