#pragma once
#include "string.h"
#include "string"
#include "cstring"

// CMyNewDlg 对话框

class CMyNewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyNewDlg)

public:
	CMyNewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyNewDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void myshow1(CString s);
	void myshow2(CString s);
	CString m_display1;
	CString str;
	afx_msg void OnBnClickedButton2();
	CString m_display2;
	afx_msg void OnBnClickedButton3();
};
