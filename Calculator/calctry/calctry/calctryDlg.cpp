
// calctryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calctry.h"
#include "calctryDlg.h"
#include "afxdialogex.h"
#include "string"
#include "cstring"
#include "string.h"
#include "Scan.h"
#include "Calculation.h"
#include "MyNewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	//virtual BOOL PreTranslateMessage(MSG* pMsg);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalctryDlg �Ի���



CcalctryDlg::CcalctryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCTRY_DIALOG, pParent)
	, m_display(_T(""))
	, s(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalctryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_display);
}

BEGIN_MESSAGE_MAP(CcalctryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CcalctryDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CcalctryDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalctryDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalctryDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalctryDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalctryDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalctryDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalctryDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalctryDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalctryDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CcalctryDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &CcalctryDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CcalctryDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CcalctryDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUTIPLY, &CcalctryDlg::OnBnClickedButtonMutiply)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CcalctryDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_ADD2, &CcalctryDlg::OnBnClickedButtonAdd2)
	ON_BN_CLICKED(IDC_BUTTON_ADD3, &CcalctryDlg::OnBnClickedButtonAdd3)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CcalctryDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CcalctryDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CcalctryDlg::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_pow, &CcalctryDlg::OnBnClickedButtonpow)
	ON_BN_CLICKED(IDC_BUTTON_file, &CcalctryDlg::OnBnClickedButtonfile)
END_MESSAGE_MAP()


// CcalctryDlg ��Ϣ�������

BOOL CcalctryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalctryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalctryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalctryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcalctryDlg::UpdateDisplay(double dck)
{
	m_display.Format(_T("%f"), dck);
	int i = m_display.GetLength();
	while (m_display.GetAt(i - 1) == '0') //��ʽ�����,��������������ȥ
	{
		m_display.Delete(i - 1, 1);  i--;
	}
	if(m_display.GetAt(i-1)=='.')
	  m_display.Delete(i - 1, 1);
	s = m_display;
	UpdateData(false);//���±༭�����m_display
}

void CcalctryDlg::myshow(CString s)
{
	m_display = s;
	UpdateData(false);
}

void CcalctryDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CcalctryDlg::OnBnClickedButton1()
{
	m_display += "1";
	s += "1";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButton2()
{
	m_display += "2";
	s += "2";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButton3()
{
	m_display += "3";
	s += "3";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButton4()
{
	m_display += "4";
	s += "4";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButton5()
{
	m_display += "5";
	s += "5";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButton6()
{
	m_display += "6";
	s += "6";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButton7()
{
	m_display += "7";
	s += "7";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButton8()
{
	m_display += "8";
	s += "8";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButton9()
{
	m_display += "9";
	s += "9";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButton0()
{
	m_display += "0";
	s += "0";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButtonPoint()
{
	m_display += ".";
	s += ".";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButtonAdd()
{
	m_display += "+";
	s += "+";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButtonMinus()
{
	m_display += "-";
	s += "-";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButtonMutiply()
{
	m_display += "��";
	s += "*";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButtonDiv()
{
	m_display += "/";
	s += "/";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButtonAdd2()
{
	m_display += "(";
	s += "(";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButtonAdd3()
{
	m_display += ")";
	s += ")";
	myshow(m_display);
}
//���ں� ��ʾ���
void CcalctryDlg::OnBnClickedButtonEqual()
{
	m_display += "=";
	s += "=";
	if (s == "=") s = "0=";
	Scan Myscan;
	Calculation calc;
	USES_CONVERSION;
	//string ss(W2A(m_display));
	string ss(W2A(s));
	UpdateDisplay(calc.work(Myscan.ToStringQueue(ss)));
}

void CcalctryDlg::OnBnClickedButtonClear()
{
	m_display = "";
	s = "";
	myshow(m_display);
}

void CcalctryDlg::OnBnClickedButtonBack()
{
	int i = m_display.GetLength();
    m_display.Delete(i - 1, 1);
	s.Delete(i - 1, 1);
	if (s == "") s = "";
	UpdateData(false);//���±༭�����m_display
}


void CcalctryDlg::OnBnClickedButtonpow()
{
	m_display += "^";
	s += "^";
	myshow(m_display);
}

BOOL CcalctryDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_NUMPAD0:
			OnBnClickedButton0();
			return TRUE;
			break;
		case VK_NUMPAD1:
			OnBnClickedButton1();
			return TRUE;
			break;
		case VK_NUMPAD2:
			OnBnClickedButton2();
			return TRUE;
			break;
		case VK_NUMPAD3:
			OnBnClickedButton3();
			return TRUE;
			break;
		case VK_NUMPAD4:
			OnBnClickedButton4();
			return TRUE;
			break;
		case VK_NUMPAD5:
			OnBnClickedButton5();
			return TRUE;
			break;
		case VK_NUMPAD6:
			OnBnClickedButton6();
			return TRUE;
			break;
		case VK_NUMPAD7:
			OnBnClickedButton7();
			return TRUE;
			break;
		case VK_NUMPAD8:
			OnBnClickedButton8();
			return TRUE;
			break;
		case VK_NUMPAD9:
			OnBnClickedButton9();
			return TRUE;
			break;
		case '0':
			OnBnClickedButton0();
			return TRUE;
			break;
		case '1':
			OnBnClickedButton1();
			return TRUE;
			break;
		case '2':
			OnBnClickedButton2();
			return TRUE;
			break;
		case '3':
			OnBnClickedButton3();
			return TRUE;
			break;
		case '4':
			OnBnClickedButton4();
			return TRUE;
			break;
		case '5':
			OnBnClickedButton5();
			return TRUE;
			break;
		case '6':
			OnBnClickedButton6();
			return TRUE;
			break;
		case '7':
			OnBnClickedButton7();
			return TRUE;
			break;
		case '8':
			if (((GetAsyncKeyState(VK_SHIFT) & 0x8000)))
				OnBnClickedButtonMutiply();
			else
			    OnBnClickedButton8();
			return TRUE;
			break;
		case '9':
			OnBnClickedButton9();
			return TRUE;
			break;
		case VK_MULTIPLY:
			OnBnClickedButtonMutiply();
			return TRUE;
			break;
		case VK_ADD:
			OnBnClickedButtonAdd();
			return TRUE;
			break;
		case VK_SUBTRACT:
			OnBnClickedButtonMinus();
			return TRUE;
			break;
		case VK_DECIMAL:
			OnBnClickedButtonPoint();
			return TRUE;
			break;
		case VK_DIVIDE:
			OnBnClickedButtonDiv();
			return TRUE;
			break;
		case VK_RETURN:
			OnBnClickedButtonEqual();
			return TRUE;
			break;
		case VK_ESCAPE:
			OnBnClickedButtonClear();
			return TRUE;
			break;
		case VK_BACK:
			OnBnClickedButtonBack();
			return TRUE;
			break;
		case 190:
			OnBnClickedButtonPoint();
			return TRUE;
			break;
		case 191:
			OnBnClickedButtonDiv();
			return TRUE;
			break;
		case 189:
			OnBnClickedButtonMinus();
			return TRUE;
			break;
		case 187:
			if (((GetAsyncKeyState(VK_SHIFT) & 0x8000)))
				OnBnClickedButtonAdd();
			else
			    OnBnClickedButtonEqual();
			return TRUE;
			break;
		default:
			return TRUE;
			break;
		}
		return CDialog::PreTranslateMessage(pMsg);
	}
	return FALSE;
}

void CcalctryDlg::OnBnClickedButtonfile()
{
	CMyNewDlg  Dlg;
	Dlg.DoModal();
}
