#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int n, i, j, pos = 0;
	scanf("%d", &n);
	cin.get();
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for(i = s1.length() - 1, j = s2.length() - 1; i >= 0, j >= 0; i--, j--){
		if(s1[i] == s2[j])
			pos++;		
		else
			break;
	}
	string Std(s1.end() - pos, s1.end());
	if(pos == 0){
		cout << "nai" << endl;
		return 0;
	} else {
		for(i = 2; i < n; i++) {
			getline(cin, s1);
			for(j = 0; j < pos; j++){
				if(s1[s1.length() - 1 - j] != Std[pos - j - 1]){
					Std.erase(Std.begin(), Std.end() - j);
					pos = j;	
					break;
				}
			}
		}
	}
	if(Std.empty())
		cout << "nai" << endl;
	else
		cout << Std << endl;
	return 0;
}
