
// MAINDlg.cpp
#include "stdafx.h"
#include "��ѧ����ô.h"
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
	// ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�ִ�д˲���  
	SetIcon(m_hIcon, TRUE);			// ��ͼ��
	SetIcon(m_hIcon, FALSE);		// Сͼ��
	::SetWindowPos(AfxGetMainWnd()->m_hWnd,HWND_TOP,0,0,1504,1034,SWP_NOMOVE);  //ע��˴�������1200*800��
	load_initialization(0);
	return TRUE;  // ���ǽ������õ��ؼ������򷵻� TRUE
}

void CMAINDlg::OnPaint()
{
	if (IsIconic())  //�жϴ����Ƿ�����С��״̬
	{
		CPaintDC sdc(this); // ���ڻ��Ƶ��豸������
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(sdc.GetSafeHdc()), 0);   //���Ͳ���������ͼƬ����Ϣ,Ҫ���б���ͼƬ�ĸ���
		int cxIcon = GetSystemMetrics(SM_CXICON); int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;  GetClientRect(&rect);
		int x=(rect.Width()-cxIcon+1)/2;  int y=(rect.Height()-cyIcon+1)/2;    // ʹͼ���ڹ����������о���
		sdc.DrawIcon(x, y, m_hIcon);   // ����ͼ��
	}
	else
	{
		CRect rect;  this->GetClientRect(&rect);
		CPaintDC sdc(this);   //this��sdc���ڴ˴�������ػ棬��CDC *pdc=GetDC()��û�취
		dc.CreateCompatibleDC(NULL);   //���������ΪNULL���򴴽�һ���͵�ǰ��Ļһ�µ�CDC;ÿ��delete֮��Ҫ����create
		CBitmap bmp_bk; bmp_bk.CreateCompatibleBitmap(&sdc,rect.Width(),rect.Height());  //��ʼ��һ����sdc�����ļ��ݵ�λͼ
		dc.SelectObject(&bmp_bk);
		paint();
		sdc.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);
		bmp_bk.DeleteObject();   dc.DeleteDC();
		//CDialogEx::OnPaint();   �ò���������仰����
	}
}

void CMAINDlg::draw_bmp1(int flag,int px,int py,double k)  //ȥ��bmp��ɫ����
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
	dc1.SetBkColor(RGB(255,255,255));   //�������ģʽ��͸����ϵͳ��ʹ�ñ�����ɫ�����dc1�еĿհ�
	dcback.CreateCompatibleDC(NULL);  dcback.SelectObject(&bmp_back);
	dcback.BitBlt(0,0,bm1.bmWidth,bm1.bmHeight,&dc1,0,0,SRCCOPY);
	dc.BitBlt(px,py,bm1.bmWidth,bm1.bmHeight,&dc1,0,0,SRCINVERT);   //XOR(���)��������Դ��Ŀ������������ɫ�ϲ�
	dc.BitBlt(px,py,bm1.bmWidth,bm1.bmHeight,&dcback,0,0,SRCAND);   //AND(��)����������Դ��Ŀ����������ڵ���ɫ�ϲ�
	dc.BitBlt(px,py,bm1.bmWidth,bm1.bmHeight,&dc1,0,0,SRCINVERT);   //XOR(���)��������Դ��Ŀ������������ɫ�ϲ�
	/*dcback.StretchBlt(px+(1-k)*bm1.bmWidth/2,py+(1-k)*bm1.bmHeight/2,bm1.bmWidth*k,bm1.bmHeight*k,&dc1,0,0,bm1.bmWidth,bm1.bmHeight,SRCCOPY);
	dc.StretchBlt(px+(1-k)*bm1.bmWidth/2,py+(1-k)*bm1.bmHeight/2,bm1.bmWidth*k,bm1.bmHeight*k,&dc1,0,0,bm1.bmWidth,bm1.bmHeight,SRCINVERT);
	dc.StretchBlt(px+(1-k)*bm1.bmWidth/2,py+(1-k)*bm1.bmHeight/2,bm1.bmWidth*k,bm1.bmHeight*k,&dcback,0,0,bm1.bmWidth,bm1.bmHeight,SRCAND);
	dc.StretchBlt(px+(1-k)*bm1.bmWidth/2,py+(1-k)*bm1.bmHeight/2,bm1.bmWidth*k,bm1.bmHeight*k,&dc1,0,0,bm1.bmWidth,bm1.bmHeight,SRCINVERT);*/
	if(bm1.bmWidth<300&&bm1.bmHeight<200)re_bmp[flag-6000].SetRect(px,py,px+bm1.bmWidth,py+bm1.bmHeight);
	else re_bmp[flag-6000].SetRect(px+0.05*bm1.bmWidth,py+0.1*bm1.bmHeight,px+0.9*bm1.bmWidth,py+0.9*bm1.bmHeight);  //���ö�Ӧ����
}

void CMAINDlg::draw_bmp2(int x0,int y0,int w,int h,int r,int g,int b)   //���ƴ�ɫ����
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
	dc.SetBkMode(TRANSPARENT);    //�൱��dc.SetBkColor(RGB(͸��));
	
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
				if(show[0]&&game_t11_enter>=20){show[2]=true;}  //��ʽ���д˹��ܽ���ر�/�޸ģ���ΪҪ�����������֮�����˳������(���ڶ�ѡ����鵥���ж�choice_scene��scene�ǲ��е�)
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
				give_data1(last_storage_num);MessageBox("�浵�ɹ���",MB_OK);
			}
			return TRUE;
		}
		else if(pMsg->wParam==VK_F4)
		{
			if(window==2&&show[11]&&!ismove)
			{
				CString str; str.Format("������ͼ?"); 
				if(MessageBox(str,"��ͼת��",MB_YESNO)==IDYES)
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
				CString str; str.Format("������������+3?����+5?������ҵ�ɹ���+10?"); 
				if(MessageBox(str,"������ѡ��",MB_YESNO)==IDYES)
				{
					SAN+=3; wisdom+=3; perseverance+=3; EQ+=3; moral+=3; energy+=5; if(day>=1023&&day<=1034)cgl+=10;
					if(energy>=energy_limit){energy=energy_limit;}
					if(cgl>100){cgl=100;}
				}
			}
			return TRUE;
		}
		else if(pMsg->wParam==VK_F2)  //�����ã��ǵ�ɾ
		{
			if(window==2&&show[11])
			{
				if(logic[15]==0)
				{
					CString str; str.Format("�Ƿ�ֱ�ӽ�����һ�ܣ�"); 
					if(MessageBox(str,"ʱ��涴",MB_YESNO)==IDYES)
					{
						day++;   if(day==1035)logic[15]=1;
						energy+=10;
						if(day>=1022&&logic[4]==1)energy-=10;
						if(energy>=energy_limit)energy=energy_limit;
						find_story();
					}
				}
				else{CString str; str.Format("��ϲ�㣬�������֣�"); MessageBox(str,MB_OK);}
			}
		}
		else if(pMsg->wParam==VK_F3)  //�����ã��ǵ�ɾ
		{
			if(window==2)
			{
				CString str_content,str;
				if(day>=1001&&day<=1012)str.Format("��һ   ��%d��(%d)\n",day-1000,day-1000);
				else if(day>=1013&&day<=1022)str.Format("���   ��%d��(%d)\n",day-1012,day-1000);
				else if(day>=1023&&day<=1034)str.Format("����   ��%d��(%d)\n",day-1022,day-1000);
				str_content+=str;
				str.Format("SANֵ: %d\n�ǻ�ֵ: %d\n����: %d\n����: %d\n����: %d\n����ֵ->%d/%d\n��ҵ�ɹ���:%d\n����ͼλ��->(%d,%d)\n��괰��λ��->(%d,%d)\n��ǰ�ǵ�%d������",
					SAN,wisdom,perseverance,EQ,moral,energy,energy_limit,cgl,-mapx+mpt.x,-mapy+mpt.y,mpt.x,mpt.y,story_num); 
				str_content+=str;
				MessageBox(str_content,"���۲�",MB_OK);
			}
		}
		else if(pMsg->wParam==VK_F6)
		{
			CString str;str.Format("��Esc  ������һҳ��\n��F2   ������һ��\n��F3   �鿴��������\n��F4   �л���ͼ\n��F5   ���д浵\n\nAD/���Ҽ�   �����չ\n���ּ�  ѡ������ж�Ӧѡ��"); 
			MessageBox(str,"��Ϸ����",MB_OK);
		}
		else if(pMsg->wParam==VK_RIGHT||pMsg->wParam=='D')
		{
			if(window==2&&show[0]&&game_t11_enter==10)
			{
				if(story[story_num].choice_scene!=story_scene) //�費��ѡ��ҳ
				{
					//MessageBox("��Ϸ����",MB_OK);
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
				if(story_scene>1&&(story[story_num].choice_scene==0||story[story_num].choice_scene!=story_scene-1)){story_scene--;this->Invalidate(false);}  //��֤ѡ��ѡ��֮��������
			}
		}
		else if((pMsg->wParam>=VK_NUMPAD1&&pMsg->wParam<=VK_NUMPAD5)||(pMsg->wParam>='1'&&pMsg->wParam<='5'))  //97-101��49-53
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ
HCURSOR CMAINDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
