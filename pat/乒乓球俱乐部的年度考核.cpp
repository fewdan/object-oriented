#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

class GroupA{
protected:
    string name;
    int score,a,b;
public:
    void work()
    {
        cin>>name>>a>>b;
    }
    virtual void display()
    {
        score=2*a-b;
        cout<<name<<" A"<<" "<<score<<endl;
    }
};

class GroupB{
protected:
    string name;
    int score,a,b;
public:
    void work()
    {
        cin>>name>>a>>b;
    }
    virtual void display()
    {
        score=2*a-b;
        cout<<name<<" A"<<" "<<score<<endl;
    }
};

void doing ()
{
    //
}

int main ()
{aaa
    doing ();
    return 0;
}