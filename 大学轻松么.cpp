
// 大学轻松么.cpp : 定义应用程序的类行为。
#include "stdafx.h"
#include "大学轻松么.h"
#include "MAINDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyApp
BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CMyApp::CMyApp()  // CMyApp 构造
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	// TODO: 在此处添加构造代码，将所有重要的初始化放置在 InitInstance 中
}

CMyApp theApp;    // 唯一的一个 CMyApp 对象

BOOL CMyApp::InitInstance()     // CMyApp 初始化
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化如果未使用这些功能并希望减小最终可执行文件的大小，则应移除下列不需要的特定初始化例程，更改用于存储设置的注册表项

	SetRegistryKey(_T("大学轻松么工作室"));

	CMAINDlg dlg;  m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK){}
	else if (nResponse == IDCANCEL){}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，而不是启动应用程序的消息泵
	return FALSE;
}

