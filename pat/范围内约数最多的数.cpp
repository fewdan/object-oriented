#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

int f,t,ans,now,sz;
int a[100010];

void work (int x)
{
    int t=sqrt(x);
    for (int i=1;i<=t;++i)
        if (x%i==0)
          now+=2;
    if (t*t==x) now--;
}

void out (int x)
{
    int t=sqrt(x);
    for (int i=1;i<=t;++i)
        if (x%i==0)
        {
            a[++sz]=i;
            if (x/i!=t)
              a[++sz]=x/i;
        }
    sort (a+1,a+1+sz);
    for (int i=1;i<=sz-1;++i)
        if (a[i]!=a[i-1])
          cout<<a[i]<<" ";
    cout<<a[sz]<<endl;
}

void doing ()
{
    int x;
    cin>>f>>t;
    cout<<"["<<f<<","<<t<<"] ";
    for (int i=f;i<=t;++i)
    {
        now=0;
        work(i);
        if (now>ans)
        {
          ans=now;
          x=i;
        }
    }
    cout<<x<<" "<<ans<<endl;
    out(x);
}

int main ()
{
    doing ();
    return 0;
}