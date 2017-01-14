    #include<map>  
    #include<cstdio>  
    #include<stack>  
    #include<cstring>  
    #include<string>  
    #include<algorithm>  
    #include<iostream>  
    using namespace std;  
    typedef unsigned long long uLL;  
    const int maxn = 2e3 + 10;  
    int tot, n, m, x;  
    int f[1000005];  
    double c[maxn][4];  
    char ch[4] = { 'C', 'M', 'E', 'A' };  
      
    int main()  
    {  
      scanf("%d%d", &n, &m);  
      for (int i = 1; i <= n; i++)  
      {  
        scanf("%d", &x);  f[x] = i;  
        for (int j = 0; j < 3; j++) scanf("%lf", &c[i][j]);  
        c[i][3] = (c[i][0] + c[i][1] + c[i][2]) / 3;  
      }  
      while (m--)  
      {  
        scanf("%d", &x);  
        if (!f[x]) { printf("N/A\n"); continue; }  
        int ans[4] = { 0, 0, 0, 0 };  
        for (int i = 1; i <= n; i++)  
        {  
          for (int j = 0; j < 4; j++) if (c[i][j]>c[f[x]][j]) ans[j]++;  
        }  
        x = 3;  
        for (int j = 0; j < 3; j++) if (ans[j] < ans[x]) x = j;  
        printf("%d %c\n", ans[x] + 1, ch[x]);  
      }  
      return 0;  
    }  



