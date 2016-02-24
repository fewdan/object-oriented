/* 
 * File:   Print.cpp
 * Author: fewdan
 * 
 * Created on 2016年2月24日, 下午8:06
 */

#include "Print.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;

void Print::Myprint(queue<string>s)
{
    while (s.size())
    {
        cout<<s.front()<<endl;
        s.pop();
    }
}

