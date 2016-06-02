// MyNewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calctry.h"
#include "MyNewDlg.h"
#include "afxdialogex.h"
#include "string"
#include "string.h"
#include "cstring"
#include "Scan.h"
#include "Calculation.h"
#include "fstream"

// CMyNewDlg 对话框

IMPLEMENT_DYNAMIC(CMyNewDlg, CDialogEx)

CMyNewDlg::CMyNewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_display1(_T(""))
	, m_display2(_T(""))
	, str(_T(""))
{

}

CMyNewDlg::~CMyNewDlg()
{
}

void CMyNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_display1);
	DDX_Text(pDX, IDC_EDIT2, m_display2);
}


BEGIN_MESSAGE_MAP(CMyNewDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyNewDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyNewDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyNewDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMyNewDlg 消息处理程序

void CMyNewDlg::myshow1(CString s)
{
	m_display1 = s;
	UpdateData(false);
}
void CMyNewDlg::myshow2(CString s)
{
	m_display2 = s;
	UpdateData(false);
}

void CMyNewDlg::OnBnClickedButton1()
{
	LPCTSTR szFilter = _T("txt(*.txt)|*.txt|excel(*.xls)|*.xls|All Files(*.*)|*.*||");
	CFileDialog dlg(1, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if (IDOK != dlg.DoModal())
		return;
	myshow1(dlg.GetPathName());
}

void CMyNewDlg::OnBnClickedButton2()
{
	LPCTSTR szFilter = _T("txt(*.txt)|*.txt|excel(*.xls)|*.xls|All Files(*.*)|*.*||");
	CFileDialog dlg(1, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if (IDOK != dlg.DoModal())
		return;
	myshow2(dlg.GetPathName());
}

void CMyNewDlg::OnBnClickedButton3()
{
	CString str1, str2;
	GetDlgItemText(IDC_EDIT1, str1);
	GetDlgItemText(IDC_EDIT2, str2);
	ifstream fin;
	ofstream fout;
	USES_CONVERSION;
	string s1(W2A(str1));
	string s2(W2A(str2));
	fin.open(s1.c_str(), ios::in);
	fout.open(s2.c_str(), ios::out);
	while (!fin.eof())
	{
		string temp_s;
		Scan Myscan;
		queue<string>tempqueue;
		Calculation calc;
		double result;
		getline(fin, temp_s, '\n');
		tempqueue = Myscan.ToStringQueue(temp_s);
		result = calc.work(tempqueue);
		fout << result << endl;
	}
	fin.close();
	fout.close();
	MessageBox(_T("计算完成"));
}
