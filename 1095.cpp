#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 1e4+10;
struct car
{
	string plate;
	int t;
	int state;
}NewCar[maxn], Car[maxn];
map<string, int> m;
bool cmp(struct car A, struct car B)
{
	if(A.plate < B.plate)
		return true;
	else if(A.plate == B.plate)
		return A.t < B.t;
	return false;
}
bool comp(struct car A, struct car B)
{
	return A.t < B.t;
}
int main()
{
	int n, k, j = 0, hh, mm, ss, st, time = 0, max = 0;
	string state= "*", plate = "*";
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		cin>>plate;
		Car[i].plate = plate;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		Car[i].t = hh * 3600 + mm * 60 + ss;
		cin >> state;
		Car[i].state = (state == "in" ? 1 : 0);
	}
	sort(Car, Car + n, cmp);
	for(int i = 0; i < n; ){
		if(Car[i].plate == Car[i + 1].plate){
			if(Car[i].state == 1 && Car[i + 1].state == 0){
				NewCar[j++] = Car[i];
				NewCar[j++] = Car[i + 1];
				string temp = Car[i].plate;
				m[temp] += Car[i + 1].t - Car[i].t;
				i += 2;
			}else
				i++;
		}
		else
			i++;
	}
	int cnt = 0;
	sort(NewCar, NewCar + j, comp);
	int itr = 0;
	for(int i = 0; i < k; i++){
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int sum = hh * 3600 + mm * 60 + ss;
		for(; itr < j; itr++){
			if(sum >= NewCar[itr].t){
				cnt++;
				if(NewCar[itr].state == 0)
					cnt -= 2;
			}
			else
				break;
		}
		printf("%d\n", cnt);
	}
	map<string, int>::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		if(it->second > max)
			max = it->second;
	}
	int flag = 1;
	for(it = m.begin(); it != m.end(); it++){
		if(it->second == max)
			cout<<it->first<<" ";
	}
	printf("%02d:%02d:%02d", max / 3600, max % 3600 / 60, max % 36000 % 60);
	return 0;
}
