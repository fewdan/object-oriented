// Calculation.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calctry.h"
#include "Calculation.h"
#include "afxdialogex.h"
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;


// Calculation �Ի���

IMPLEMENT_DYNAMIC(Calculation, CDialogEx)

Calculation::Calculation(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCTRY_DIALOG, pParent)
{

}

Calculation::~Calculation()
{
}

void Calculation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Calculation, CDialogEx)
END_MESSAGE_MAP()


// Calculation ��Ϣ�������

/*  ��������������ȼ������е�λ��  */
int Calculation::myconvert(char ch)
{
	switch (ch)
	{
	case '+':
		return 0;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 3;
	case '^':
		return 4;
	case '(':
		return 5;
	case ')':
		return 6;
	case '#':
		return 7;
	}
}

/*  ��������ı��ʽ  */
double Calculation::calc(double num1, double num2, char ch)
{
	switch (ch)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1*num2;
	case '/':
		return num1 / num2;
	case '^':
		return (double)pow((double)num1, (double)num2);
	}
}

/*  string ת double  */
void Calculation::strtoint(double &int_temp, const string &string_temp)
{
	stringstream stream(string_temp);
	stream >> int_temp;
}

/*  ������ʽ�����庯��  */
double Calculation::work(queue<string> str)
{
	/*  ��ʼ��  */
	while (num.size())
	{
		num.pop();
	}
	while (operators.size())
	{
		operators.pop();
	}
	double temp_num;
	operators.push('#');//������ջ�ձ�־
	num.push(0);//�����һ������
	while (str.front() != "#" || operators.top() != '#')
	{
		//ɨ���ַ�����
		//���ֽ�ջ
		if ((str.front()[0] >= '0' && str.front()[0] <= '9') ||
			(str.front()[1] >= '0' && str.front()[1] <= '9'))
		{
			strtoint(temp_num, str.front());
			num.push(temp_num);
			str.pop();
		}
		else
		{
			//���������
			char priority;
			priority = pre[myconvert(operators.top())][myconvert(str.front()[0])];
			if (priority == '<')
			{
				operators.push(str.front()[0]);
				str.pop();
			}
			else if (priority == '>')
			{
				double num2 = num.top();
				num.pop();
				double num1 = num.top();
				num.pop();
				char ch = operators.top();
				operators.pop();
				num.push(calc(num1, num2, ch));
				//cout<<num1<<ch<<num2<<" "<<calc(num1,num2,ch)<<endl;
			}
			else if (priority == '=')
			{
				operators.pop();
				str.pop();
			}
		}
	}
	/* ĳЩ������ܳ��ִ�Ϊ��0 */
	if (num.top() == -0)
		num.top() = 0;
	return (num.top());
}