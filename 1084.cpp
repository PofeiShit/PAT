#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int vis[256];
int main()
{
	string k1, k2;
	cin>>k1>>k2;
	for(int i = 0; i < k1.length(); i++){
		if(k1[i] >= '0' && k1[i] <= '9' || k1[i] == '_'){
			if(k2.find(k1[i], 0) == string::npos && !vis[(int)k1[i]]){
				printf("%c", k1[i]);
				vis[(int)k1[i]] = 1;
			}
		}else if(k1[i] >= 'A' && k1[i] <= 'Z' && !vis[(int)k1[i]] ){
			if(k2.find(k1[i], 0) == string::npos){
				printf("%c", k1[i]);		
				vis[(int)k1[i]] = 1;
				vis[(int)k1[i] + 32] = 1;
			}
		}else if(k1[i] >= 'a' && k1[i] <= 'z' && !vis[(int)k1[i]] ){
			if(k2.find(k1[i], 0) == string::npos){
				printf("%c", k1[i] - 'a' + 'A');
				vis[(int)k1[i]] = 1;
				vis[(int)k1[i] - 32] = 1;
			}
		}
	}
	return 0;
}
