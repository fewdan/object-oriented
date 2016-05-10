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
    string temp_s;
    Scan Myscan;
    Print Myprint;
    queue<string>tempqueue;
    Calculation calc;
    int result;
     
    if ( strcmp(argv[1],"-f") == 0 )
    {
        ifstream fin;
        string Text_file = argv[argc-2];
        string Result_filRe = argv[argc-1];
        
        fin.open ( Text_file.c_str() , ios::in);
        
        while ( !fin.eof() )
        {
            fin >> temp_s;
            tempqueue = Myscan.ToStringQueue (temp_s);
            result = calc.work(tempqueue);
            Myprint.print_file(Result_filRe,result);
        }
        fin.close();
    }
    else
    {
        if ( strcmp(argv[1],"-a") == 0 )
        {
            temp_s=argv[2];
            tempqueue = Myscan.ToStringQueue (temp_s);
            result = calc.work(tempqueue);
            Myprint.print_full_s(temp_s);
            Myprint.printans(result);
        }
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
