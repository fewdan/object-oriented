#pragma once
#include <iostream>
#include <string>
#include <queue>
using namespace std;
// Scan �Ի���

class Scan : public CDialogEx
{
	DECLARE_DYNAMIC(Scan)

public:
	Scan(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Scan();
	queue<string> ToStringQueue(string input);

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCTRY_DIALOG };
#endif
private:
	/* ����������ַ��� */
	queue<string>s;
	/* ��ǰ�������ֳ��� */
	int count;
	/* ������ַ������Ƿ��в���������������� */
	bool failed;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
