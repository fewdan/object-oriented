/* 
 * File:   main.cpp
 * Author: fewdan
 *
 * Created on 2016年5月5日, 下午8:18
 */

#include <cstdlib>
#include <iostream>
#include "work.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    double r;
    cin>>r;
    work area;
    area.getpi();
    area.getarea(r);
    return 0;
}

