/* 
 * File:   Calculation.h
 * Author: fewdan
 *
 * Created on 2016年4月7日, 下午11:07
 */

#ifndef CALCULATION_H
#define	CALCULATION_H
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

class Calculation
{
public:
    /*  返回运算符在优先级数组中的位置  */
    int myconvert (char op);
    /*  计算基本的表达式  */
    double calc (double num1,double num2,char op);
    /*  string 转 double  */
    void strtoint (double &int_temp,const string &string_temp);
    /*  计算表达式的主体函数  */
    void work (queue<string> str);
private:
    /* 数字栈与操作符栈 */
    stack<double> num;
    stack<char> operators;
    /* 运算优先级 */
    char pre[8][8]= 
    { 
    {'>','>','<','<','<','<','>','>'}, 
    {'>','>','<','<','<','<','>','>'}, 
    {'>','>','>','>','<','<','>','>'}, 
    {'>','>','>','>','<','<','>','>'}, 
    {'>','>','>','>','>','<','>','>'}, 
    {'<','<','<','<','<','<','=','>'}, 
    {' ',' ',' ',' ',' ',' ',' ',' '}, 
    {'<','<','<','<','<','<','<','='}
    };
};

#endif	/* CALCULATION_H */

