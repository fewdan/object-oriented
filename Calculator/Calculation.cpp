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
int Calculation::myconvert (char ch)
{
    switch ( ch )
    {
        case '+' :
            return 0;
        case '-' :
            return 1;
        case '*' :
            return 2;
        case '/' :
            return 3;
        case '^' :
            return 4;
        case '(' :
            return 5;
        case ')' :
            return 6;
        case '#' :
            return 7;
    }
}

/*  计算基本的表达式  */
double Calculation::calc(double num1,double num2,char ch)
{
    switch ( ch )
    {
        case '+' :
            return num1+num2;
        case '-' :
            return num1-num2;
        case '*' :
            return num1*num2;
        case '/' :
            return num1/num2;
        case '^' :
            return (double)pow((double)num1,(double)num2);
    }
}

/*  string 转 double  */
void Calculation::strtoint (double &int_temp,const string &string_temp)
{
    stringstream stream(string_temp);
    stream>>int_temp;
}

/*  计算表达式的主体函数  */
double Calculation::work (queue<string> str)
{
    /*  初始化  */
    while ( num.size() )
    {
        num.pop();
    }
    while ( operators.size() )
    {
        operators.pop();
    }
    double temp_num;
    operators.push ('#');//操作符栈空标志
    num.push(0);//处理第一个负数
    while ( str.front() != "#" || operators.top() != '#' )
    {
        //扫描字符队列
        //数字进栈
        if ( (str.front()[0] >= '0' && str.front()[0] <= '9')||
           (str.front()[1] >= '0' && str.front()[1] <= '9') )
        {
            strtoint (temp_num,str.front());
            num.push(temp_num);
            str.pop();
        }
        else
        {
            //处理操作符
            char priority;
            priority = pre[myconvert(operators.top())][myconvert(str.front()[0])];
            if ( priority == '<' )
            {
                operators.push(str.front()[0]);
                str.pop();
            }
            else if ( priority == '>' )
            {
                double num2 = num.top();
                num.pop();
                double num1 = num.top();
                num.pop();
                char ch = operators.top();
                operators.pop();
                num.push(calc(num1,num2,ch));
                //cout<<num1<<ch<<num2<<" "<<calc(num1,num2,ch)<<endl;
            }
            else if ( priority == '=' )
            {
                operators.pop();
                str.pop();
            }
        }
    }
    /* 某些情况可能出现答案为－0 */
    if (num.top() == -0)
        num.top() = 0;
    return ( num.top() );
}