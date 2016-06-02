
// calctryDlg.h : 头文件
//

#pragma once


// CcalctryDlg 对话框
class CcalctryDlg : public CDialogEx
{
// 构造
public:
	CcalctryDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual BOOL PreTranslateMessage(MSG* pMsg);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCTRY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_display;
	CString s;
	void  UpdateDisplay(double dck);
	void myshow(CString s);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonPoint();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMutiply();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonAdd2();
	afx_msg void OnBnClickedButtonAdd3();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonpow();
	afx_msg void OnBnClickedButtonfile();
};
