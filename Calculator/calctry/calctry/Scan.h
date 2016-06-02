#pragma once
#include <iostream>
#include <string>
#include <queue>
using namespace std;
// Scan 对话框

class Scan : public CDialogEx
{
	DECLARE_DYNAMIC(Scan)

public:
	Scan(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Scan();
	queue<string> ToStringQueue(string input);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCTRY_DIALOG };
#endif
private:
	/* 键盘输入的字符串 */
	queue<string>s;
	/* 当前处理数字长度 */
	int count;
	/* 输入的字符串中是否有不满足的条件的数字 */
	bool failed;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
