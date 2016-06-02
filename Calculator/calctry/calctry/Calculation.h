#pragma once

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

// Calculation �Ի���

class Calculation : public CDialogEx
{
	DECLARE_DYNAMIC(Calculation)

public:
	Calculation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Calculation();
	/*  ��������������ȼ������е�λ��  */
	int myconvert(char op);
	/*  ��������ı��ʽ  */
	double calc(double num1, double num2, char op);
	/*  string ת double  */
	void strtoint(double &int_temp, const string &string_temp);
	/*  ������ʽ�����庯��  */
	double work(queue<string> str);
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCTRY_DIALOG };
#endif
private:
	/* ����ջ�������ջ */
	stack<double> num;
	stack<char> operators;
	/* �������ȼ� */
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
