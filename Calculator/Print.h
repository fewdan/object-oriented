/* 
 * File:   Print.h
 * Author: fewdan
 *
 * Created on 2016年2月24日, 下午8:06
 */

#ifndef PRINT_H
#define	PRINT_H
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Print
{
public:
    /* 输出原表达式得到的队列 */
    void Myprint (queue<string>s);
    void printans (int ans);
    void print_file (string s,int ans);
    void print_full_s (string s);
};

#endif	/* PRINT_H */

