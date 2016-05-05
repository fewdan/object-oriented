/* 
 * File:   work.cpp
 * Author: fewdan
 * 
 * Created on 2016年5月5日, 下午8:21
 */

#include "work.h"
#include <iostream>
#include <cmath>
using namespace std;

void work::getpi ()
{
    pi=acos(-1.0);
}

void work::getarea (double r) 
{
    double area;
    area=pi*r*r;
    cout<<area<<endl;
}