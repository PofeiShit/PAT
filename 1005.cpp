#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char s[100];		
	int sum = 0, re[3], len, quo, i = 0;
	cin>>s;
	len = strlen(s);	
	for(i = 0; i < len; i++)
	{
		sum += s[i] - 48;
	}	
//	cout<<sum<<endl;
	i = 0;	
	while(1)	
	{
			re[i] = sum % 10;	
			sum = sum / 10;	
			if(sum == 0)
				break;	
			i ++;	
			
	}	
	for(;i >= 0;i --)	
	{	
			switch(re[i])
			{
				case 0: cout<<"zero";break;	
				case 1: cout<<"one";break;
				case 2: cout<<"two";break;
				case 3: cout<<"three";break;
				case 4: cout<<"four";break;
				case 5: cout<<"five";break;	
				case 6: cout<<"six";break;
				case 7: cout<<"seven";break;
				case 8: cout<<"eight";break;
				case 9: cout<<"nine";break;
				default:break;

			}	
			if(i != 0)
				cout<<' ';
	}
	return 0;

}
