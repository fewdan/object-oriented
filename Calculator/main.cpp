/*
 * File:   main.cpp
 * Author: fewdan
 *
 * Created on 2016年2月24日, 下午7:58
 */

#include <iostream>
#include <string>
#include <queue>
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"
using namespace std;

int main (int argc,char* argv[])
{
    /* temp_s存待计算表达式 */
    string temp_s;
    temp_s = argv[argc-1];
    if ( argc == 3 )
    {
        cout<<temp_s<<"= ";
    }
    /* 输入类 */
    Scan Myscan;

    /* 中间变量，传递字符串队列 */
    queue<string>tempqueue;
    tempqueue = Myscan.ToStringQueue(temp_s);
    
    Calculation calc;
    calc.work(tempqueue);
    return 0;
}
