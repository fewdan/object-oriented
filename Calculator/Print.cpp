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
#include <fstream>
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
        cout << s.front() << endl;
        s.pop();
    }
}

/*  输出答案函数  */
void Print::printans ( int ans )
{
    cout<< ans << endl;
}

void Print::print_file (string s,int ans)
{
    ofstream fout;
    fout.open ( s.c_str() , ios::out);
    fout << ans << endl;
    fout.close();
}

void Print::print_full_s (string s)
{
    cout << s << " ";
}