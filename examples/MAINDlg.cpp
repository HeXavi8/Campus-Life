
// MAINDlg.cpp
#include "stdafx.h"
#include "大学轻松么.h"
#include "MAINDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMAINDlg::CMAINDlg(CWnd* pParent) : CDialogEx(CMAINDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CMAINDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMAINDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

BOOL CMAINDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 当应用程序主窗口不是对话框时，框架将自动执行此操作  
	SetIcon(m_hIcon, TRUE);			// 大图标
	SetIcon(m_hIcon, FALSE);		// 小图标
	::SetWindowPos(AfxGetMainWnd()->m_hWnd,HWND_TOP,0,0,1504,1034,SWP_NOMOVE);  //注意此处定义了1200*800！
	load_initialization(0);
	return TRUE;  // 除非焦点设置到控件，否则返回 TRUE
}

void CMAINDlg::OnPaint()
{
	if (IsIconic())  //判断窗口是否处于最小化状态
	{
		CPaintDC sdc(this); // 用于绘制的设备上下文
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(sdc.GetSafeHdc()), 0);   //发送擦除背景的图片的消息,要进行背景图片的更换
		int cxIcon = GetSystemMetrics(SM_CXICON); int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;  GetClientRect(&rect);
		int x=(rect.Width()-cxIcon+1)/2;  int y=(rect.Height()-cyIcon+1)/2;    // 使图标在工作区矩形中居中
		sdc.DrawIcon(x, y, m_hIcon);   // 绘制图标
	}
	else
	{
		CRect rect;  this->GetClientRect(&rect);
		CPaintDC sdc(this);   //this让sdc可在此窗体持续重绘，用CDC *pdc=GetDC()就没办法
		dc.CreateCompatibleDC(NULL);   //如果这个句柄为NULL，则创建一个和当前屏幕一致的CDC;每次delete之后都要重新create
		CBitmap bmp_bk; bmp_bk.CreateCompatibleBitmap(&sdc,rect.Width(),rect.Height());  //初始化一个与sdc上下文兼容的位图
		dc.SelectObject(&bmp_bk);
		paint();
		sdc.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);
		bmp_bk.DeleteObject();   dc.DeleteDC();
		//CDialogEx::OnPaint();   该不该留下这句话？？
	}
}

void CMAINDlg::draw_bmp1(int flag,int px,int py,double k)  //去除bmp白色背景
{
	CDC dc1,dcback;
	CBitmap cbmp1;
	HBITMAP hbmp1;
	hbmp1=(HBITMAP)::LoadImage(hMode1,MAKEINTRESOURCE(flag),IMAGE_BITMAP,0,0,LR_DEFAULTCOLOR);
	//else hbmp1=(HBITMAP)::LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(flag),IMAGE_BITMAP,0,0,LR_DEFAULTCOLOR);
	cbmp1.Attach(hbmp1);
	BITMAP bm1; cbmp1.GetBitmap(&bm1);
	CBitmap bmp_back;
    bmp_back.CreateBitmap((int)bm1.bmWidth*k,(int)bm1.bmHeight*k,1,1,NULL);
	dc1.CreateCompatibleDC(NULL);  dc1.SelectObject(&cbmp1);
	dc1.SetBkColor(RGB(255,255,255));   //如果背景模式不透明，系统将使用背景颜色来填充dc1中的空白
	dcback.CreateCompatibleDC(NULL);  dcback.SelectObject(&bmp_back);
	dcback.BitBlt(0,0,bm1.bmWidth,bm1.bmHeight,&dc1,0,0,SRCCOPY);
	dc.BitBlt(px,py,bm1.bmWidth,bm1.bmHeight,&dc1,0,0,SRCINVERT);   //XOR(异或)操作符将源和目标矩形区域的颜色合并
	dc.BitBlt(px,py,bm1.bmWidth,bm1.bmHeight,&dcback,0,0,SRCAND);   //AND(与)操作符将来源和目标矩形区域内的颜色合并
	dc.BitBlt(px,py,bm1.bmWidth,bm1.bmHeight,&dc1,0,0,SRCINVERT);   //XOR(异或)操作符将源和目标矩形区域的颜色合并
	/*dcback.StretchBlt(px+(1-k)*bm1.bmWidth/2,py+(1-k)*bm1.bmHeight/2,bm1.bmWidth*k,bm1.bmHeight*k,&dc1,0,0,bm1.bmWidth,bm1.bmHeight,SRCCOPY);
	dc.StretchBlt(px+(1-k)*bm1.bmWidth/2,py+(1-k)*bm1.bmHeight/2,bm1.bmWidth*k,bm1.bmHeight*k,&dc1,0,0,bm1.bmWidth,bm1.bmHeight,SRCINVERT);
	dc.StretchBlt(px+(1-k)*bm1.bmWidth/2,py+(1-k)*bm1.bmHeight/2,bm1.bmWidth*k,bm1.bmHeight*k,&dcback,0,0,bm1.bmWidth,bm1.bmHeight,SRCAND);
	dc.StretchBlt(px+(1-k)*bm1.bmWidth/2,py+(1-k)*bm1.bmHeight/2,bm1.bmWidth*k,bm1.bmHeight*k,&dc1,0,0,bm1.bmWidth,bm1.bmHeight,SRCINVERT);*/
	if(bm1.bmWidth<300&&bm1.bmHeight<200)re_bmp[flag-6000].SetRect(px,py,px+bm1.bmWidth,py+bm1.bmHeight);
	else re_bmp[flag-6000].SetRect(px+0.05*bm1.bmWidth,py+0.1*bm1.bmHeight,px+0.9*bm1.bmWidth,py+0.9*bm1.bmHeight);  //设置对应矩形
}

void CMAINDlg::draw_bmp2(int x0,int y0,int w,int h,int r,int g,int b)   //绘制纯色背景
{
	CRect rect(x0,y0,x0+w,y0+h);
	if(w==0&&h==0){this->GetClientRect(&rect);}
	CBrush brush1; brush1.CreateSolidBrush(RGB(r,g,b));
	dc.FillRect(rect,&brush1);
}

void CMAINDlg::text1(const char*c,int w,int h,int we,int r,int g,int b,int x0,int y0,int x1,int y1,char*p)
{
	//InstallResourceFont(hMode1, MAKEINTRESOURCE(4001), _T("TTF"));
	LOGFONT logFont;  ZeroMemory(&logFont,sizeof(logFont));  logFont.lfCharSet=GB2312_CHARSET;
	logFont.lfWidth=w; logFont.lfHeight=h; //logFont.lfPitchAndFamily=;
	logFont.lfWeight=we; strcpy_s(logFont.lfFaceName,c);

	CFont fntNew; fntNew.CreateFontIndirect(&logFont);
	dc.SelectObject(&fntNew);
	dc.SetTextColor(RGB(r,g,b));
	dc.SetBkMode(TRANSPARENT);    //相当于dc.SetBkColor(RGB(透明));
	
	dc.DrawText(p,-1,CRect(x0,y0,x1,y1),DT_CENTER);
}

void CMAINDlg::InstallResourceFont(HINSTANCE hResInstance, LPCTSTR lpsFont, LPCTSTR lpsType)
{
	HRSRC hRes = FindResource(hResInstance, lpsFont, lpsType);
	if(hRes)
	{
		HGLOBAL hMem = LoadResource(hResInstance, hRes);
		void *pData = LockResource(hMem);
		DWORD dwLen = SizeofResource(hResInstance, hRes);
		DWORD dwFonts = 0;
		HANDLE m_hFont = AddFontMemResourceEx(
			pData,          // font resource
			dwLen,          // number of bytes in font resource 
			NULL,           // Reserved. Must be 0.
			&dwFonts);      // number of fonts installed
		hf=(HFONT)m_hFont;
		if(m_hFont == NULL)AfxMessageBox(_T("InstallResourceFont function fails"));
	}
	
}

void CMAINDlg::paint()
{
	if(window==0){load_paint();}
	else if(window==1){storage_paint();}
	else if(window==2){game_paint();}
}

void CMAINDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent==1){load_timer1();}
	else if(nIDEvent==11){game_timer1();}
	CDialogEx::OnTimer(nIDEvent);
}

void CMAINDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	mpt=point;
	if(window==2)game_mm();
	CDialogEx::OnMouseMove(nFlags, point);
}

BOOL CMAINDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if(window==0){load_cursor();}
	else if(window==1){storage_cursor();}
	else if(window==2){game_cursor();}
	return TRUE;
	//return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}

BOOL CMAINDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN||pMsg->message==WM_SYSKEYDOWN)
	{
		if(pMsg->wParam==VK_ESCAPE)
		{
			if(window==1){load_initialization(1);this->Invalidate(false);}
			else if(window==2)
			{
				if(show[0]&&game_t11_enter>=20){show[2]=true;}  //正式版中此功能将会关闭/修改，因为要避免加了属性之后点击退出的情况(对于多选择剧情单靠判断choice_scene与scene是不行的)
				else if(show[11]){load_initialization(1);this->Invalidate(false);}
				else if(show[12]){show[12]=false; show[11]=true; find_story(); this->Invalidate(false);}
			}
			return TRUE;
		}
		else if(pMsg->wParam==VK_RETURN)
		{
			return TRUE;
		}
		else if(pMsg->wParam==VK_F5)
		{
			if(window==2)
			{
				give_data1(last_storage_num);MessageBox("存档成功！",MB_OK);
			}
			return TRUE;
		}
		else if(pMsg->wParam==VK_F4)
		{
			if(window==2&&show[11]&&!ismove)
			{
				CString str; str.Format("换个地图?"); 
				if(MessageBox(str,"地图转换",MB_YESNO)==IDYES)
				{
					if(setting_frame==2)setting_frame=3;
					else if(setting_frame==3)setting_frame=2;
					give_data0();
					story_information_initialization(-1);
				}
			}
			return TRUE;
		}
		else if(pMsg->wParam==VK_F7)
		{
			if(window==2&&show[11]&&!ismove)
			{
				CString str; str.Format("所有人物属性+3?体力+5?大三创业成功率+10?"); 
				if(MessageBox(str,"开发者选项",MB_YESNO)==IDYES)
				{
					SAN+=3; wisdom+=3; perseverance+=3; EQ+=3; moral+=3; energy+=5; if(day>=1023&&day<=1034)cgl+=10;
					if(energy>=energy_limit){energy=energy_limit;}
					if(cgl>100){cgl=100;}
				}
			}
			return TRUE;
		}
		else if(pMsg->wParam==VK_F2)  //调试用，记得删
		{
			if(window==2&&show[11])
			{
				if(logic[15]==0)
				{
					CString str; str.Format("是否直接进入下一周？"); 
					if(MessageBox(str,"时光虫洞",MB_YESNO)==IDYES)
					{
						day++;   if(day==1035)logic[15]=1;
						energy+=10;
						if(day>=1022&&logic[4]==1)energy-=10;
						if(energy>=energy_limit)energy=energy_limit;
						find_story();
					}
				}
				else{CString str; str.Format("恭喜你，到啦大结局！"); MessageBox(str,MB_OK);}
			}
		}
		else if(pMsg->wParam==VK_F3)  //调试用，记得删
		{
			if(window==2)
			{
				CString str_content,str;
				if(day>=1001&&day<=1012)str.Format("大一   第%d周(%d)\n",day-1000,day-1000);
				else if(day>=1013&&day<=1022)str.Format("大二   第%d周(%d)\n",day-1012,day-1000);
				else if(day>=1023&&day<=1034)str.Format("大三   第%d周(%d)\n",day-1022,day-1000);
				str_content+=str;
				str.Format("SAN值: %d\n智慧值: %d\n毅力: %d\n情商: %d\n道德: %d\n体力值->%d/%d\n创业成功率:%d\n光标地图位置->(%d,%d)\n光标窗体位置->(%d,%d)\n当前是第%d个剧情",
					SAN,wisdom,perseverance,EQ,moral,energy,energy_limit,cgl,-mapx+mpt.x,-mapy+mpt.y,mpt.x,mpt.y,story_num); 
				str_content+=str;
				MessageBox(str_content,"天眼查",MB_OK);
			}
		}
		else if(pMsg->wParam==VK_F6)
		{
			CString str;str.Format("按Esc  返回上一页面\n按F2   进入下一周\n按F3   查看人物属性\n按F4   切换地图\n按F5   进行存档\n\nAD/左右键   剧情进展\n数字键  选择剧情中对应选项"); 
			MessageBox(str,"游戏帮助",MB_OK);
		}
		else if(pMsg->wParam==VK_RIGHT||pMsg->wParam=='D')
		{
			if(window==2&&show[0]&&game_t11_enter==10)
			{
				if(story[story_num].choice_scene!=story_scene) //需不在选择页
				{
					//MessageBox("游戏帮助",MB_OK);
					if(story_scene<story[story_num].max_scene)story_scene++;
					else show[2]=true;
					this->Invalidate(false);
				}
			}
		}
		else if(pMsg->wParam==VK_LEFT||pMsg->wParam=='A')
		{
			if(window==2&&show[0]&&game_t11_enter==10)
			{
				if(story_scene>1&&(story[story_num].choice_scene==0||story[story_num].choice_scene!=story_scene-1)){story_scene--;this->Invalidate(false);}  //保证选项选择之后不能重来
			}
		}
		else if((pMsg->wParam>=VK_NUMPAD1&&pMsg->wParam<=VK_NUMPAD5)||(pMsg->wParam>='1'&&pMsg->wParam<='5'))  //97-101、49-53
		{
			if(show[0]&&game_t11_enter==10)
			{
				if(pMsg->wParam>=VK_NUMPAD1&&pMsg->wParam<=VK_NUMPAD5)deal_choice(pMsg->wParam-96);
				else deal_choice(pMsg->wParam-'1'+1);
				//CString str; str.Format("%d",pMsg->wParam); MessageBox(str,MB_OK);
				this->Invalidate(false);
			}
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CMAINDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(window==0){load_lb();}
	else if(window==1){storage_lb();}
	else if(window==2){game_lb();}
	this->Invalidate(false);
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CMAINDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(window==2){game_lbu();}
	CDialogEx::OnLButtonUp(nFlags, point);
}

BOOL CMAINDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	if(window==2)
	{
		if(show[11]&&setting_frame==3)
		{
			mapy+=zDelta*0.7; if(mapy>-50)mapy=-50;  if(mapy<-1640)mapy=-1640;
		}
	}
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示
HCURSOR CMAINDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
