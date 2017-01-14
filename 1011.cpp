#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int i = 3;
	char res[3];	
	float sum = 1, w, t, l, max;
	while(i)	
	{
		scanf("%f %f %f", &w, &t, &l);
		max = w>t ? w : t;
		max = max>l ? max : l;
		if(max == w)		
			res[3 - i] = 'W';
		else if(max == t)	
			res[3 - i] = 'T';
		else if(max == l)
			res[3 - i] = 'L';
		sum *= max;	
		i --;	
	}
	printf("%c %c %c %.2f", res[0], res[1], res[2], (sum * 0.65 - 1) * 2);	
}
