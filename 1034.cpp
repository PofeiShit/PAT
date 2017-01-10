#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int Number, Threthold;
map<string, int> TotalNum;
map<string, int> Weight;
vector<string> Answer;
int Time[1010];
int Count[1010];
int main()
{
	string Name1, Name2, head;
	int T, Group = 1, tmp, cnt = 0, max = -1;
	scanf("%d%d", &Number, &Threthold);	
	map<string, int>::iterator itr1;
	map<string, int>::iterator itr2;
	for(int i = 0; i < Number; i++)
	{
		cin>>Name1>>Name2>>T;	
		itr1 = TotalNum.find(Name1);
		itr2 = TotalNum.find(Name2);
		if(itr1 == TotalNum.end() && itr2 == TotalNum.end()){
			TotalNum[Name1] = Group;
			TotalNum[Name2] = Group;
			Weight[Name1] = T;
			Weight[Name2] = T;
			Time[Group] = T;
			Count[Group] += 2;
			Group ++;
		}
		else if(itr1 == TotalNum.end()){
			tmp = TotalNum[Name2];
			TotalNum[Name1] = tmp;
			Time[tmp] += T;
			Count[tmp]++;
			Weight[Name1] = T;
			Weight[Name2] += T;
		}
		else if(itr2 == TotalNum.end()){
			tmp = TotalNum[Name1];
			TotalNum[Name2] = tmp;
			Time[tmp] += T;
			Count[tmp]++;
			Weight[Name2] = T;
			Weight[Name1] += T;
		}
		else{
			Weight[Name1] += T;
			Weight[Name2] += T;
			tmp = TotalNum[Name1];
			int idx = TotalNum[Name2];
			if(tmp != idx)
			{
				max = tmp > idx ? tmp : idx;
				tmp = tmp < idx ? tmp : idx;
				for(itr1 = TotalNum.begin(); itr1 != TotalNum.end(); itr1++)
				{
					if(itr1->second == max)
					{
						Name1 = itr1->first;
						TotalNum[Name1] = tmp;
						Time[tmp] += Weight[Name1];
						Count[tmp]++;
						Count[max]--;
					}
				}
			}
			else
			Time[tmp] += T; 
		}
	}
#if 0
	for(itr1 = TotalNum.begin(); itr1 != TotalNum.end(); itr1++)
		cout<<itr1->first<<' '<<itr1->second<<endl;
	for(itr1 = Weight.begin(); itr1 != Weight.end(); itr1++)
		cout<<itr1->first<<' '<<itr1->second<<endl;
#endif
	for(int i = 1; i < Group; i++)
	{
		max = -1;
		if(Time[i] > Threthold && Count[i] > 2)
		{//团伙的总时间>阈值且团伙的人数大于2
			cnt++;//团伙个数
			for(itr1 = TotalNum.begin(); itr1 != TotalNum.end(); ++itr1)
			{
				T = itr1->second;//团伙标号
				if(T == i)
				{
					Name1 = itr1->first;
					tmp = Weight[Name1];//求头头
					if(tmp > max)
					{
						head = Name1;
						max = tmp;
					}
				}
			}
			Answer.push_back(head);			
		}	
	}
	sort(Answer.begin(), Answer.end());
	cout<<cnt<<endl;
	if(cnt != 0)	
	{
		for(int i = 0; i < cnt; i++)
			cout<<Answer[i]<<' '<<Count[TotalNum[Answer[i]]]<<endl;
	}
	return 0;
}
