/* 
 * File:   Scan.h
 * Author: fewdan
 *
 * Created on 2016年2月24日, 下午7:59
 */

#ifndef SCAN_H
#define	SCAN_H
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Scan
{
public:
    queue<string> ToStringQueue (string input);
private:
    /* 键盘输入的字符串 */
    queue<string>s;
    /* 当前处理数字长度 */
    int count;
    /* 输入的字符串中是否有不满足的条件的数字 */
    bool failed;
};

#endif	/* SCAN_H */

