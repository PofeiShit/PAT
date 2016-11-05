#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
char t1[][5] = {"tret", "jan", "feb", "mar",
	"apr", "may", "jun", "jly",
	"aug", "sep", "oct", "nov", "dec",};
char t2[][5] = {"tam", "hel", "maa", "huh", "tou", "kes",
	"hei", "elo", "syy", "lok", "mer", "jou",};
void printM(string is)
{
	int a = atoi(is.c_str());
	int rem = a % 13;	
	if(a == 0)
		printf("%s\n", t1[a]);
	else{
		a /= 13;
		if(a != 0 && rem != 0)
			printf("%s %s\n", t2[a - 1], t1[rem]);
		else if(a == 0 && rem != 0)
			printf("%s\n", t1[rem]);
		else if(a != 0 && rem == 0)
			printf("%s\n", t2[a - 1]);
	}	
}
void printE(string s)
{
	string tmp;
	int gao = 0;
	int di = 0;
	tmp.assign(s.begin(), s.begin() + 3);	
	for(int i = 0; i < 12; i++){
		if(tmp.compare(t2[i]) == 0)
			gao += (i + 1) * 13;		
	}
	if(gao == 0){
		for(int i = 0; i < 13; i++)
			if(tmp.compare(t1[i]) == 0)
				di += i;
		printf("%d\n", di);
	}
	else{
		if(s.length() > 4){
			s.erase(s.begin(), s.begin() + 4);
			for(int i = 0; i < 13; i++)
				if(s.compare(t1[i]) == 0)
					di += i;
		}
		printf("%d\n", gao + di);
	}
}
int main()
{
	int n, num;
	string is;
	scanf("%d", &n);
	cin.get();
	while(n--){
		getline(cin, is);
		if(is[0] >= '0' && is[0] <= '9')
			printM(is);
		else
			printE(is);
		is.clear();
	}
	return 0;
}

