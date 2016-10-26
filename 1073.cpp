#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	string is, os;
	char n;
	scanf("%c", &n);
	getline(cin, os, 'E');
	int cnt;
	scanf("%d", &cnt);
	if(cnt < 0){
		os.insert(os.begin(), (-1) * cnt - 1, '0');	
		os.insert(0, "0.");
		int pos = os.rfind('.', os.length());
		os.erase(os.begin() + pos);
	}
	else if(cnt > 0){
		if(cnt >= os.length() - 2)
			os.append(cnt - (os.length() - 2), '0');
		else
			os.insert(os.begin() + cnt + 2, '.');
		os.erase(os.begin() + 1);
	}
	if(n == '-')
		printf("-");
	cout<<os<<endl;
//	cout<<n<<endl<<is<<endl<<cnt<<endl;
	return 0;
}
