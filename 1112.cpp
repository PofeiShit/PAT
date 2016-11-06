#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
using namespace std;
const int maxn = 1000;
map<char, vector<int> > m; 
set<int> ans;
int main()
{
	int k, pos = 0;
	cin>>k;
	cin.get();
	string is, sis;
	char n;
	while((n=getchar()) != '\n'){
		m[n].push_back(pos);
		pos++;
		is.append(1, n);
	}
	sis = is;
	for(map<char, vector<int> >::iterator itr = m.begin(); itr != m.end(); itr++){
		vector<int> v = itr->second;
		bool flag = true;
		int len = 0;
		int c = v[0];
		for(int i = 0; i < v.size(); i++){
			if(c == v[i]){
				len++;	
				c++;
			}
			else{
				c = v[i];
				if(len % k != 0){
					flag = false;
					break;
				}
				i--;
				len = 0;
			}
		}
		if(len % k != 0)
			flag = false;
		if(flag){
			//ans.append(1, itr->first);
			ans.insert(v[0]);
			int pos = 0;
			while(1){
				pos = is.find(itr->first, pos);
				if(pos != -1){
					is.erase(pos, k);
					is.insert(is.begin() + pos, 1, itr->first);
					pos++;
				}
				else
					break;
			}
		}
	}
	for(set<int>::iterator itr = ans.begin(); itr != ans.end(); itr++)
		cout<<sis[*itr];
	cout<<endl<<is<<endl;
	return 0;
}
