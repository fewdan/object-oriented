#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<string.h>
using namespace std;

class Date{
public:
    int y,m,d,ans;
    bool p;
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    void init ()
    {
        ans=0;
        p=0;
    }
    void work ()
    {
        if (((y%4==0)&&(y%100!=0))||(y%400==0))
            p=1;
        ans=d;
        for (int i=1;i<m;i++)
            ans=ans+month[i];
        if (p&&(m>2)) ans++;
    }
    void out ()
    {
        cout<<ans<<endl;
    }
};

int main ()
{
    Date t;
    while (cin>>t.y>>t.m>>t.d)
    {
        if (t.y==t.m && t.m==0 && t.m==t.d) break;
        t.init();
        t.work();
        t.out();
    }
    return 0;
}