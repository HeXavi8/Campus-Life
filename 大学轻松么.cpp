
// ��ѧ����ô.cpp : ����Ӧ�ó��������Ϊ��
#include "stdafx.h"
#include "��ѧ����ô.h"
#include "MAINDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyApp
BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CMyApp::CMyApp()  // CMyApp ����
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	// TODO: �ڴ˴���ӹ�����룬��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

CMyApp theApp;    // Ψһ��һ�� CMyApp ����

BOOL CMyApp::InitInstance()     // CMyApp ��ʼ��
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ������Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õĹ����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի�������κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ�����δʹ����Щ���ܲ�ϣ����С���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ����в���Ҫ���ض���ʼ�����̣��������ڴ洢���õ�ע�����

	SetRegistryKey(_T("��ѧ����ô������"));

	CMAINDlg dlg;  m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK){}
	else if (nResponse == IDCANCEL){}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó��򣬶���������Ӧ�ó������Ϣ��
	return FALSE;
}

