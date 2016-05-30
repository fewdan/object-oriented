#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

class Data{
public:
    int a[8];
    int l,r,ans,now,last;
    void work()
    {
        l=r=1;ans=-1;
        now=0;last=0;
        for (int i=1;i<=7;i++)
        {
            now+=a[i];
            if (now<=0)
            {
                now=0;
                last=i;
                continue;
            }
            if (now>ans)
            {
                ans=now;
                l=last+1;r=i;
            }
        }
        if (ans<=0)
          cout<<"won't buy!"<<endl;
        else
          cout<<ans<<" "<<l<<" "<<r<<endl;
    }
};


void doing ()
{
    Data t;
    while (1)
    {
        bool p=0;
        for (int i=1;i<=7;i++)
        {
            scanf("%d",&t.a[i]);
            if (t.a[i]) p=1;
        }
        if (!p) break;
        t.work();
    }
}

int main ()
{
    doing ();
    return 0;
}