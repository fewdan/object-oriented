/* 
 * File:   Scan.cpp
 * Author: fewdan
 * 
 * Created on 2016年2月24日, 下午7:59
 */

#include "Scan.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*  最大合法字符长度  */
#define maxlength 10

/*************************************************
  Description:    将键盘输入的待处理字符串，处理成规定的字符串队列
  Input:          待处理字符串
  Output:         
  Return:         字符串队列
  Others:         
*************************************************/
queue<string> Scan::ToStringQueue (string input)
{
    /*  将最后面的等于号删除  */
    string temp;
    temp = input.substr(0,input.size()-1);
    input = temp;
    /* 处理多余括号情况 */
    int kh = 0;
    for ( int i = 0; i < input.size() ; i++)
        if ( input[i] == '(' )
        {
            kh++;
        }
        else if ( input[i]==')' )
        {
            kh--;
        }
    while ( kh > 0)
    {
        input += ")";
        kh--;
    }
    while ( kh < 0)
    {
        input = "(" + input;
        kh++;
    }
    //括号处理完毕
    /* 处理类似(-())的情况 */
    for ( int i = 1 ; i < input.size() - 1 ; i++)
    {
        if ( input[i] == '-' && input[i-1] == '(' && input[i+1] == '(')
        {
            string temp1,temp2;
            temp1 = input.substr(0,i);
            temp2 = input.substr(i,input.size()-i);
            input = temp1 + "0" + temp2;
        }
    }
    failed = 0;
    count = 0;
    bool negative = 0;
    temp = "";
    input = input + "#";
    for ( int i = 0 ; i < input.size() ; i++)
    {
        /* get number */
        if ( input[i] >= '0' && input[i] <= '9' )
        {
            temp += input[i];
            count++;
            /* 数字长度大于10 */
            if ( count > maxlength )
            {
                failed = 1;
                break;
            }
        }
        else
        {
            /* 处理小数 */
            if ( input[i] == '.' )//decimal
            {
                temp += '.';
                continue;
            }
            if ( input[i] == '-' )
            {
                if ( i==0 && (input[i+1] >= '0' && input[i+1] <= '9') )
                {
                    negative = 1;
                }
                else if ( (i !=0 ) && (!(input[i-1]>='0' && input[i-1]<='9')) &&(input[i-1]!=')') )
                {
                    negative = 1;
                }
            }
            /* 数字＋运算符
               number and operator  */
            if ( temp != "" )
            {
                if ( negative == 0 )
                {
                    /* 压入数字 */
                    count = 0;
                    s.push(temp);
                    /* 压入运算符 */
                    temp = input[i];
                    s.push(temp);
                    temp = "";
                    /* 清空临时变量 */
                }
                else
                {
                    negative = 0;
                    temp = "-" + temp;
                    count = 0;
                    s.push(temp);
                    temp = input[i];
                    s.push(temp);
                    temp = "";
                }
            }
            else
            {
                /* continual operator */
                if ( !negative )
                {
                    temp = input[i];
                    s.push(temp);
                    temp = "";
                }
            }
        }
    }
    /* last number */
    if ( temp != "" )
    {
        if ( negative )
            temp="-"+temp;
        s.push(temp);
    }
    /* 数字不符合要求 */
    if ( failed )
    {
        /* 清空队列 */
        while ( s.size() )
            s.pop();
        /* 压入错误信息 */
        s.push("Error!!!!!!!!!!!!!!!!!!");
    }
    return s;
}