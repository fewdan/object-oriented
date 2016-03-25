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

/*************************************************
  Description:    将键盘输入的待处理字符串，处理成规定的字符串队列
  Input:          待处理字符串
  Output:         
  Return:         字符串队列
  Others:         
*************************************************/
queue<string> Scan::ToStringQueue(string input)
{
    failed = 0;
    count = 0;
    string temp = "";
    for (int i = 0 ; i < input.size() ; i++)
    {
        /* get number */
        if (input[i] >= '0' && input[i] <= '9')
        {
            temp += input[i];
            count++;
            /* 数字长度大于10 */
            if (count > 10)
            {
                failed = 1;
                break;
            }
        }
        else
        {
            /* 处理小数 */
            if (input[i] == '.')//decimal
            {
                temp += '.';
                continue;
            }
            /* 数字＋运算符
               number and operator  */
            if (temp != "")
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
                /* continual operator */
                temp = input[i];
                s.push(temp);
                temp = "";
            }
        }
    }
    /* last number */
    if (temp != "")
        s.push(temp);
    /* 数字不符合要求 */
    if (failed)
    {
        /* 清空队列 */
        while (s.size())
            s.pop();
        /* 压入错误信息 */
        s.push("Error!!!!!!!!!!!!!!!!!!");
    }
    return s;
}