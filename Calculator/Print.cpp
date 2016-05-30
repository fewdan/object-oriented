/* 
 * File:   Print.cpp
 * Author: fewdan
 * 
 * Created on 2016年2月24日, 下午8:06
 */

#include "Print.h"
#include "Scan.h"
#include "Calculation.h"
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
void Print::printans ( double ans )
{
    cout<< ans << endl;
}

/*  文件输出答案  */
void Print::print_file (string s1,string s2)
{

    ifstream fin;
    ofstream fout;
        
    fin.open ( s1.c_str() , ios::in);
    fout.open ( s2.c_str() , ios::out);    
    while ( !fin.eof() )
    {
        string temp_s;
        Scan Myscan;
        queue<string>tempqueue;
        Calculation calc;
        int result;
        getline (fin,temp_s,'\n');
        tempqueue = Myscan.ToStringQueue (temp_s);
        result = calc.work(tempqueue);
        fout << result << endl;
    }
    fin.close();
    fout.close();
}

/*  输出原本表达式  */
void Print::print_full_s (string s)
{
    cout << s << " ";
}