
// MFCApplicationDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"
#include "LocalMapParse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationDlg �Ի���



CMFCApplicationDlg::CMFCApplicationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplicationDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDOK, &CMFCApplicationDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CMFCApplicationDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMFCApplicationDlg ��Ϣ�������

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplicationDlg::OnPaint()
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
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplicationDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    //�������
    theApp.xmlMap = new CLocalMapParse(TEXT("LocalConfigMap.xml"));

    CString str = theApp.xmlMap->to_CString();

    MessageBox(str);

    //���ļ�ʧ��
    /*theApp.xmlMap = new CLocalMapParse(TEXT("LocalConfigMap2.xml"));

    int errcode = theApp.xmlMap->GetXMLErr();
    CString str;
    str.Format(_T("%d"), errcode);
    MessageBox(str);*/

    //�ļ�����ʧ��
    /*theApp.xmlMap = new CLocalMapParse(TEXT("LocalConfigMap1.xml"));

    int errcode = theApp.xmlMap->GetXMLErr();
    CString str;
    str.Format(_T("%d"), errcode);
    MessageBox(str);*/
}


void CMFCApplicationDlg::OnBnClickedCancel()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    delete(theApp.xmlMap);
    CDialogEx::OnCancel();
}
