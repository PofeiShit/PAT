#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
deque<int> d1, d2;
int main()
{
	int np, ng, tmp;
	scanf("%d%d", &np, &ng);
	int *p = new int[np];
	int *t = new int[np];
	int r = np / ng;
	r = (np % ng == 0 ? r : r + 1);
	r += 1;
	for(int i = 0; i < np; i++)
		scanf("%d", p + i);
	for(int i = 0; i < np; i++){
		scanf("%d", &tmp);
		d1.push_back(tmp);
	}
	int end = 0, start = 0, j = 0;
	while(d1.size() != 1){
		for(int k = 0; k < r - 1; k++){//总共几组
			while(end - start < ng - 1 && end < d1.size() - 1)//确定每一组的起始和末尾
				end++;
			for(j = start; j <= end; j++){
				if(j == start)
					tmp = d1[j];
				else {
					if(p[tmp] < p[d1[j]]){
						t[tmp] = r;
						tmp = d1[j];
					} else 
						t[d1[j]] = r;
				}
			}
			start = j;
			end = j;
			d2.push_back(tmp);
		}
		d1.clear();
		d1 = d2;
		d2.clear();
		r = d1.size() / ng;
		r = (d1.size() % ng == 0 ? r : r + 1);
		r ++;
		start = 0;
		end = 0;
	}
	t[d1[0]] = 1;
	for(int i = 0; i < np; i++){
		if(i)
			printf(" ");
		printf("%d", t[i]);
	}
	return 0;
}
