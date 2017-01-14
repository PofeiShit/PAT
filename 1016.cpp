#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int Rate[24];
const int maxn = 1010;
int N;
struct record 
{
	string name;
	int MM;
	int dd;
	int hh;
	int mm;
	string st;	
}Record[maxn];
bool comp(struct record A, struct record B)
{
	if(A.name < B.name)
		return true;
	else if(A.name == B.name)
	{
		if(A.MM < B.MM)
			return true;
		else if(A.MM == B.MM)
		{
			if(A.dd < B.dd)
				return true;
			else if(A.dd == B.dd)
			{
				if(A.hh < B.hh)
					return true;
				else if(A.hh == B.hh)
					return A.mm < B.mm;
			}
		}

	}
	return false;
}
int main()
{
	int i, MM, dd, hh, mm, time = 0;
	double dollar = 0.0, money = 0.0;
	string tmp;
	bool on = false, different = true;
	for(i = 0; i < 24; i++)
		scanf("%d", &Rate[i]);
	scanf("%d", &N);
	for(i = 0; i < N; i ++){
		cin>>Record[i].name;
		scanf("%d:%d:%d:%d", &Record[i].MM, &Record[i].dd, &Record[i].hh, &Record[i].mm);
		cin>>Record[i].st;
	}
	sort(Record, Record + N, comp);
#if 0
	cout<<endl;
	for(i = 0; i < N; i++){
		cout<<Record[i].name<<' ';
		printf("%d:%d:%d:%d ", Record[i].MM, Record[i].dd, Record[i].hh, Record[i].mm);
		cout<<Record[i].st<<endl;;
	}
#endif
	int start = 0, end;
	for(int k = 0; k < N; k++)
	{
		while(k < N - 1 && Record[k + 1].name == Record[k].name)	
			k++;
		end = k;
		for(i = start; i <= end; i++){
			if(Record[i].st == "on-line"){
				tmp = Record[i].name;		
//				cout<<start<<'\t'<<end<<'\t'<<endl;
				MM = Record[i].MM;
				dd = Record[i].dd;
				hh = Record[i].hh;
				mm = Record[i].mm;
//				cout<<MM<<'\t'<<dd<<'\t'<<hh<<'\t'<<mm<<endl;
				on = true;
			}
			if(on && Record[i].st == "off-line"){
				if(Record[i].name == tmp){
					time = 0;
					if(different){
						different = false;
						cout<<tmp;
						printf(" %02d\n", MM); 
					}
					time = (Record[i].dd * 24 * 60 + Record[i].hh * 60 + Record[i].mm) - (dd * 24 * 60 + hh * 60 + mm);
					printf("%02d:%02d:%02d %02d:%02d:%02d %d ", dd, hh, mm, Record[i].dd, Record[i].hh, Record[i].mm, time);
					int h = Record[i].hh - hh;
					int d = Record[i].dd - dd;
					if(h < 0){
						h += 24;
						d --;
					}
					for(int j = 0; j < d; j++){
						for(int index = 0; index < 24; index++)
							money += Rate[index] * 60;
					}
					for(int j = 0; j <= h; j++){
						if(j + hh > 23)
							money += Rate[j + hh - 24] * 60;
						else
							money += Rate[j + hh] * 60;
					}
					money -= Rate[hh] * mm;
					money -= Rate[Record[i].hh] * (60 - Record[i].mm);
					dollar += money;
					printf("$%.2lf\n", money / 100);
					money = 0.0;
				}
				on = false;
			}
		}
		if(different == false)
		{
		printf("Total amount: $%.2lf\n", dollar / 100);
		dollar = 0.0;
		different = true;
		}
		start = k + 1;
	}
	return 0;
}
