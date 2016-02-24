/* 
 * File:   Scan.h
 * Author: fewdan
 *
 * Created on 2016年2月24日, 下午7:59
 */

#ifndef SCAN_H
#define	SCAN_H
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Scan
{
public:
    queue<string> ToStringQueue (string input);
    /*void Print( )
    {//test1
        while (s.size())
        {
            cout<<s.front()<<endl;
            s.pop();
        }
    }*/
    /*bool isfailed ()
    {
        return failed;
    }*/
private:
    queue<string>s;
    int count;
    bool failed;
};

#endif	/* SCAN_H */

