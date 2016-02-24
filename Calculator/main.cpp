/* 
 * File:   main.cpp
 * Author: fewdan
 *
 * Created on 2016年2月24日, 下午7:58
 */

#include<iostream>
#include<string>
#include<queue>
#include"Scan.h"
#include"Print.h"
using namespace std;

int main ()
{
    Scan IN;
    Print OUT;
    string tempin;
    queue<string>tempqueue;
    cin>>tempin;
    tempqueue=IN.ToStringQueue(tempin);
    OUT.Myprint(tempqueue);
    return 0;
}

