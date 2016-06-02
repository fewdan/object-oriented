#pragma once

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

// Calculation 对话框

class Calculation : public CDialogEx
{
	DECLARE_DYNAMIC(Calculation)

public:
	Calculation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Calculation();
	/*  返回运算符在优先级数组中的位置  */
	int myconvert(char op);
	/*  计算基本的表达式  */
	double calc(double num1, double num2, char op);
	/*  string 转 double  */
	void strtoint(double &int_temp, const string &string_temp);
	/*  计算表达式的主体函数  */
	double work(queue<string> str);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCTRY_DIALOG };
#endif
private:
	/* 数字栈与操作符栈 */
	stack<double> num;
	stack<char> operators;
	/* 运算优先级 */
	char pre[8][8] =
	{
		{ '>','>','<','<','<','<','>','>' },
		{ '>','>','<','<','<','<','>','>' },
		{ '>','>','>','>','<','<','>','>' },
		{ '>','>','>','>','<','<','>','>' },
		{ '>','>','>','>','>','<','>','>' },
		{ '<','<','<','<','<','<','=','>' },
		{ ' ',' ',' ',' ',' ',' ',' ',' ' },
		{ '<','<','<','<','<','<','<','=' }
	};
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
