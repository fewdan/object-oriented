/* 
 * File:   Print.cpp
 * Author: fewdan
 * 
 * Created on 2016年2月24日, 下午8:06
 */

#include "Print.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*************************************************
  Description:    将得到的字符串队列输出
  Input:          字符串数列
  Output:         输出字符串数列
  Return:         
  Others:         
*************************************************/
void Print::Myprint( queue<string>s )
{
    while ( s.size() )
    {
        cout<<s.front()<<endl;
        s.pop();
    }
}

