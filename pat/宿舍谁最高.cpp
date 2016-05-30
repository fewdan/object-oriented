#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

void out (int x)
{
    if (x>9) out(x/10);
    putchar (x%10+'0');
}

class Student{
public:
    int num;
    char name[11];
    void read()
    {
        scanf("%d",&num);
        scanf("%s",name);
        scanf("%d%d",&height,&weight);
    }
    string getname()
    {
        return name;
    }
    int getheight()
    {
        return height;
    }
    int getweight()
    {
        return weight;
    }
private:
    int height,weight;
};

int n;
int a[1000010],sz;
bool v[1000010];
map<int ,int>mp;
map<int ,string>mpname;
map<int ,int>mpweight;

void doing ()
{
    Student temp;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        temp.read();
        if (!v[temp.num])
        {
            v[temp.num]=1;a[++sz]=temp.num;
        }
        if (mp[temp.num]<temp.getheight())
        {
            mp[temp.num]=temp.getheight();
            mpname[temp.num]=temp.name;
            mpweight[temp.num]=temp.getweight();
        }
    }
    sort (a+1,a+1+sz);
    //for (int i=0;i<999999;++i)
    for (int j=1;j<=sz;j++)
    {
        int i=a[j];
        if (mp[i])
        {
            printf("%06d ",i);
            printf("%s ",mpname[i].c_str());
            out(mp[i]);putchar(' ');
            out(mpweight[i]);putchar('\n');
        }
    }
}

int main ()
{
    doing ();
    return 0;
}