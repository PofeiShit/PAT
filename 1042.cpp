#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char Cards[55][4];
char Copy[55][4];
int change[55];
int main()
{
	int K, s;
	string is, os;
	cin>>K;
	for(int i = 1; i < 55; i++)
		scanf("%d", &change[i]);
	for(int i = 0; i < 4; i++){
		for(int j = 1; j <= 13; j++){
			if(i == 0)
				Cards[i * 13 + j][0] = 'S';
			if(i == 1)
				Cards[i * 13 + j][0] = 'H';
			if(i == 2)
				Cards[i * 13 + j][0] = 'C';
			if(i == 3)
				Cards[i * 13 + j][0] = 'D';
			if(j < 10)
				Cards[i * 13 + j][1] = j + '0';
			else{
				Cards[i * 13 + j][1] = j / 10 + '0';
				Cards[i * 13 + j][2] = j % 10 + '0';
				
			}
		}
	}
	Cards[53][0] = 'J';
	Cards[53][1] = '1';
	Cards[54][0] = 'J';
	Cards[54][1] = '2';
	int tmp;
	for(int i = 0; i < K; i++)
	{
		for(int j = 1; j <= 54; j++){
			tmp = change[j];
			strcpy(Copy[tmp], Cards[j]);
		}
		for(int j = 1; j <= 54; j++)
			strcpy(Cards[j], Copy[j]);
	}
	for(int i = 1; i < 54; i++)
		printf("%s ", Cards[i]);
	printf("%s", Cards[54]);
	return 0;
}
