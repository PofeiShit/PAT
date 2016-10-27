#include <iostream>
#include <deque>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
deque<int> d1, d2;
int main()
{
	int n, p, sz;
	string is;
	scanf("%d", &n);
	char ch[11];
	for(int i = 0; i < n; i++){
		scanf("%s", ch);
		if(strcmp(ch, "PeekMedian") == 0){
			if(d1.empty())
				printf("Invalid\n");
			else{
				sz = d1.size();
				sort(d2.begin(), d2.end());
				if(sz % 2 == 0)
					printf("%d\n", d2[sz / 2 - 1]);
				else 
					printf("%d\n", d2[(sz + 1) / 2 - 1]);
			}
		}
		else if(strcmp(ch,"Pop") == 0){
			if(d1.empty())
				printf("Invalid\n");
			else {
				printf("%d\n", d1.front()); 
				d1.pop_front();
				d2.clear();
				d2 = d1;
			}
		}
		else if(strcmp(ch, "Push") == 0){
			scanf("%d", &p);
			d1.push_front(p);
			d2.push_front(p);
		}	
	}
	return 0;
}
