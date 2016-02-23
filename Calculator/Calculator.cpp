#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Scan
{
public:
    queue<string> ToStringQueue (string input)
    {
        failed=0;
        count=0;
        string temp="";
        for (int i=0;i<input.size();i++)
        {
            if (input[i]>='0'&&input[i]<='9')
            {
              temp+=input[i];//get number
              count++;
              if (count>10)
              {
                failed=1;
                break;
              }
            }
            else
            {
                if (input[i]=='.')//decimal
                {
                    temp+='.';
                    continue;
                }
                if (temp!="")//number and operator
                {
                  count=0;
                  s.push(temp);
                  temp=input[i];
                  s.push(temp);
                  temp="";
                }
                else//continual operator
                {
                  temp=input[i];
                  s.push(temp);
                  temp="";
                }
            }
        }
        if (temp!="")//last number
            s.push(temp);
        if (failed)
        {//failed
            while (s.size())
              s.pop();
            s.push("Error!!!!!!!!!!!!!!!!!!");
        }
        return s;
    }
    /*void Print( )
    {//test1
        while (s.size())
        {
            cout<<s.front()<<endl;
            s.pop();
        }
    }*/
    /*bool isfailed ()
    {
        return failed;
    }*/
private:
    queue<string>s;
    int count;
    bool failed;
};

class Print{
public:
    void Myprint (queue<string>s)
    {
        while (s.size())
        {
            cout<<s.front()<<endl;
            s.pop();
        }
    }
};

int main ()
{
    Scan IN;
    Print OUT;
    string tempin;
    queue<string>tempqueue;
    cin>>tempin;
    tempqueue=IN.ToStringQueue(tempin);
    OUT.Myprint(tempqueue);
    return 0;
}