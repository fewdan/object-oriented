#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

class myDate{
public:
    void init(int y,int m,int d)
    {
        year=y;month=m;day=d;
    }
    void display()
    {
        printf("%04d/%02d/%02d ",year,month,day);
    }
private:
    int year,month,day;
};

class myTime{
public:
    void init(int h,int m)
    {
        hour=h;minute=m;
    }
    void display()
    {
        printf("%02d:%02d\n",hour,minute);
    }
private:
    int hour,minute;
};

void doing ()
{
    int y,m,d,h,mi;
    myDate date;myTime t;
    while ((scanf("%d%d%d%d%d",&y,&m,&d,&h,&mi)!=EOF))
    {
        if (y==0&&m==0&&d==0&&h==0&mi==0) break;
        date.init(y,m,d);
        date.display();
        t.init(h,mi);
        t.display();
    }
}

int main ()
{
    doing ();
    return 0;
}