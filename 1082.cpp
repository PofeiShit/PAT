#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <stack>
using namespace std;
const char *Num[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
vector<string> s[3];
vector<string> st;
void get(int N, int gaoWei, int i)
{
	int qian = N / 1000;
	int bai = N % 1000 / 100;
	int shi = N % 1000 % 100 / 10;
	int ge = N % 1000 % 100 % 10;
	if(qian != 0){
		s[i].push_back(*(Num + qian));
		s[i].push_back("Qian");
		if(bai != 0){
			s[i].push_back(*(Num + bai));
			s[i].push_back("Bai");
			if(shi != 0){
				s[i].push_back(*(Num + shi));
				s[i].push_back("Shi");
				if(ge != 0)
					s[i].push_back(*(Num + ge));
			}
			else{
				if(ge != 0){
					s[i].push_back("ling");
					s[i].push_back(*(Num + ge));
				}
			}
		}
		else {
			if(shi != 0){
				s[i].push_back("ling");
				s[i].push_back(*(Num + shi));
				s[i].push_back("Shi");
				if(ge != 0)
					s[i].push_back(*(Num + ge));
			}
			else{
				if(ge != 0){
					s[i].push_back("ling");
					s[i].push_back(*(Num + ge));
				}	
			}

		}
	}
	else{
		if(gaoWei == 1)
			s[i].push_back("ling");
		if(bai != 0){
			s[i].push_back(*(Num + bai));
			s[i].push_back("Bai");
			if(shi != 0){
				s[i].push_back(*(Num + shi));
				s[i].push_back("Shi");
				if(ge != 0)
					s[i].push_back(*(Num + ge));
			}
			else{
				if(ge != 0){
					s[i].push_back("ling");
					s[i].push_back(*(Num + ge));
				}
			}
		}
		else{
			if(shi != 0){
				s[i].push_back(*(Num + shi));
				s[i].push_back("Shi");
			}
			else{
				if(ge != 0)
					s[i].push_back(*(Num + ge));
				else
					s[i].pop_back();
			}
		}
	}
}
int main()
{
	char sym;
	string is, tmp;
	vector<string> ans;
	cin>>is;
	if(is[0] == '-'){
		sym = '-';
		is.erase(is.begin());
	}
	int len = is.length(), n, i = 0, j, pos;
	if(is == "0")
		cout<<"ling";
	else{
		if(len <= 4){
			tmp = is;
			n = atoi(tmp.c_str());
			get(n, 0, i);
			is.clear();
		}
		else if(len > 4 && len <= 8){
			tmp.assign(is.end() - 4, is.end());
			s[i].push_back("Wan");
			n = atoi(tmp.c_str());
			get(n, 1, i);
			i++;
			is.erase(is.end() - 4, is.end());
		}
		else if(len > 8){
			tmp.assign(is.end() - 4, is.end());
			is.erase(is.end() - 4, is.end());
			string tmp1;
			tmp1.assign(is.end() - 4, is.end());
			if(tmp1 != "0000")
				s[i].push_back("Wan");
			n = atoi(tmp.c_str());
			get(n, 1, i);
			i++;

			tmp.assign(is.end() - 4, is.end());
			s[i].push_back("Yi");	
			n = atoi(tmp.c_str());
			get(n, 1, i);
			i++;
			is.erase(is.end() - 4, is.end());
		}
		//	cout<<is<<endl;
		if(!is.empty()){
			n = atoi(is.c_str());
			get(n, 0, i);
		}
		if(sym == '-')
			printf("Fu ");
		for(j = i; j >= 0; j--){
			ans = s[j];
			if(!ans.empty()){
				for(pos = 0; pos < ans.size(); pos++)
					st.push_back(ans[pos]);
			}
		}
		for(j = 0; j < st.size() -1; j++)
			cout<<st[j]<<' ';	
		cout<<st[j];
	}
	return 0;
}
