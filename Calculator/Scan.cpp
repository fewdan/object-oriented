/* 
 * File:   Scan.cpp
 * Author: fewdan
 * 
 * Created on 2016年2月24日, 下午7:59
 */

#include "Scan.h"
#include<iostream>
#include<queue>
#include<string>
using namespace std;

queue<string> Scan::ToStringQueue(string input)
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