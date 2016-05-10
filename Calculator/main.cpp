/*
 * File:   main.cpp
 * Author: fewdan
 *
 * Created on 2016年2月24日, 下午7:58
 */

#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"
using namespace std;

int main (int argc,char* argv[])
{
    /*  临时表达式  */
    string temp_s;
    /*  处理类得到队列  */
    Scan Myscan;
    /*  输出类  */
    Print Myprint;
    /*  临时队列  */
    queue<string>tempqueue;
    /*  计算类  */
    Calculation calc;
    /*  答案变量  */
    int result;
     
    if ( strcmp(argv[1],"-f") == 0 )
    {
        /*  文件输出结果  */
        ifstream fin;
        string Text_file = argv[argc-2];
        string Result_filRe = argv[argc-1];
        
        fin.open ( Text_file.c_str() , ios::in);
        
        while ( !fin.eof() )
        {
            getline (fin,temp_s,'\n');
            tempqueue = Myscan.ToStringQueue (temp_s);
            result = calc.work(tempqueue);
            Myprint.print_file(Result_filRe,result);
        }
        fin.close();
    }
    else
    {
        /*  输出表达式及结果  */
        if ( strcmp(argv[1],"-a") == 0 )
        {
            temp_s=argv[2];
            tempqueue = Myscan.ToStringQueue (temp_s);
            result = calc.work(tempqueue);
            Myprint.print_full_s(temp_s);
            Myprint.printans(result);
        }
        /*  只输出结果  */
        else
        {
            temp_s=argv[1];
            tempqueue = Myscan.ToStringQueue (temp_s);
            result = calc.work(tempqueue);
            Myprint.printans(result);
        }
    }
    return 0;
}
