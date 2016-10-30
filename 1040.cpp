#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main()
{
	string is;
	int left, right, max = 1, pivot;
	getline(cin, is);
	for(int i = 0; i < is.length(); i++)
	{
		if(i == 0){
			if(is[i] == is[i + 1]){
				max = 2;
			}
		}
		else if(i == is.length() - 1){
			if(is[i] == is[is.length() - 2]){
				max = MAX(max, 2);
			}
		}
		else{
			if(is[i] != is[i+1])
				left = right = i;
			else{
				left = i;
				right = i + 1;
			}
			while(is[left] == is[right])
			{
				int tmp = right - left + 1;
				max = MAX(max, tmp);	
				right++;
				left --;
				if(left < 0 || right > is.length() - 1)
					break;;
			}
		}
	}
	cout<<max<<endl;
	return 0;
}
