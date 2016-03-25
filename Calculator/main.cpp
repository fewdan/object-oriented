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
using namespace std;

int main ()
{
    /* 输入类 */
    Scan IN;
    /* 输出类 */
    Print OUT;
    /* 临时变量，输入字符串 */
    string tempin;
    /* 中间变量，传递字符串队列 */
    queue<string>tempqueue;
    cin>>tempin;
    tempqueue=IN.ToStringQueue(tempin);
    OUT.Myprint(tempqueue);
    return 0;
}