/* 
 * File:   Calculation.cpp
 * Author: fewdan
 * 
 * Created on 2016年4月7日, 下午11:07
 */

#include "Calculation.h"
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

/*  返回运算符在优先级数组中的位置  */
int Calculation::myconvert(char ch)
{
    if (ch == '+') return 0;
    if (ch == '-') return 1;
    if (ch == '*') return 2;
    if (ch == '/') return 3;
    if (ch == '^') return 4;
    if (ch == '(') return 5;
    if (ch == ')') return 6;
    if (ch == '#') return 7;
}

/*  计算基本的表达式  */
double Calculation::calc(double num1,double num2,char ch)
{
    if (ch == '+') return num1+num2;
    if (ch == '-') return num1-num2;
    if (ch == '*') return num1*num2;
    if (ch == '/') return num1/num2;
    if (ch == '^') return (double)pow((double)num1,(double)num2);
}

/*  string 转 double  */
void Calculation::strtoint (double &int_temp,const string &string_temp)
{
    stringstream stream(string_temp);
    stream>>int_temp;
}

/*  计算表达式的主体函数  */
void Calculation::work (queue<string> str)
{
    double temp_num;
    operators.push ('#');
    num.push(0);
    while (str.front()!="#" || operators.top()!='#')
    {
        if ( (str.front()[0] >= '0' && str.front()[0] <= '9')||
           (str.front()[1] >= '0' && str.front()[1] <= '9') )
        {
            strtoint (temp_num,str.front());
            num.push(temp_num);
            str.pop();
        }
        else
        {
            char priority;
            priority=pre[myconvert(operators.top())][myconvert(str.front()[0])];
            if (priority == '<')
            {
                operators.push(str.front()[0]);
                str.pop();
            }
            else if (priority == '>')
            {
                double num2=num.top();
                num.pop();
                double num1=num.top();
                num.pop();
                char ch=operators.top();
                operators.pop();
                num.push(calc(num1,num2,ch));
                //cout<<num1<<ch<<num2<<" "<<calc(num1,num2,ch)<<endl;
            }
            else if (priority == '=')
            {
                operators.pop();
                str.pop();
            }
        }
    }
    if (num.top()==-0)
        num.top()=0;
    cout<<num.top()<<endl;
}