#include<iostream>  
#include<iomanip>  
#include<string>  
#include<cstdio>  
#include<algorithm>  
#include<map>  
using namespace std;  
  
string a[3];  
long long int  tag,radix;  
long long int num1;  
  
long long int tolongint(string s,long long int  dig)  
{  
    long long int ans=0;  
    long long int d=1;  
    for(int i=s.size()-1;i>=0;i--)  
    {  
        int num;  
        if(s[i]>='0' && s[i]<='9') num=s[i]-'0';  
        else num=s[i]-'a'+10;  
  
        ans=ans+num*d;  
        d*=dig;  
    }  
    return ans;  
}  
  
int cmp(string s,long long int  dig)  
{  
    long long int ans=0;  
    long long int d=1;  
    for(int i=s.size()-1;i>=0;i--)  
    {  
        int num;  
        if(s[i]>='0' && s[i]<='9') num=s[i]-'0';  
        else num=s[i]-'a'+10;  
  
        ans=ans+num*d;  
        if(ans>num1) return 1;  
        d*=dig;  
    }  
    if(ans==num1) return 0;  
    return -1;  
}  
  
int Maxnum(string s)  
{  
    int d=-1;  
    for(int i=0;i<s.size();i++)  
    {  
        int num;  
        if(s[i]>='0' && s[i]<='9') num=s[i]-'0';  
        else num=s[i]-'a'+10;  
  
        if(num>d) d=num;  
    }  
    return d+1;  
}  
  
long long int Max(long long int a,long long int b)  
{  
    return a>b?a:b;  
}  
  
long long int BinarySearch(int cur)  
{  
    long long int L=Maxnum(a[cur]);  
    long long int R=Max(L,num1),M;  
  
    while(L<=R)  
    {  
        M=(L+R)/2;  
        int res=cmp(a[cur],M);  
  
        if(res==0) return M;  
        else if(res==1) R=M-1;  
        else L=M+1;  
    }  
    return -1;  
}  
  
int main()  
{  
    while(cin>>a[1]>>a[2]>>tag>>radix)  
    {  
        if(a[1]=="1" && a[2]=="1")  
        {  
            cout<<"2"<<endl;  
            continue;  
        }  
        if(a[1]==a[2])  
        {  
            cout<<radix<<endl;  
            continue;  
        }  
        num1=tolongint(a[tag],radix);  
  
        int cur;  
        if(tag==1) cur=2;  
        else cur=1;  
  
        long long int ans = BinarySearch(cur);  
  
        if(ans==-1) cout<<"Impossible"<<endl;  
        else cout<<ans<<endl;  
    }  
    return 0;  
}  
