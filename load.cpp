
//load.cpp
#include "stdafx.h"
#include "大学轻松么.h"
#include "MAINDlg.h"

void CMAINDlg::load_initialization(int x)
{
	window=0;
	if(x==0)
	{
		now_sound=0;
		memset(mcicmd,0,sizeof(mcicmd));
		memset(tmpwav,0,sizeof(tmpwav));
		hMode1=LoadLibrary("load.dll");  //加载句柄
		hMode2=LoadLibrary("sound.dll");  //加载句柄
		cursor_hand=(HCURSOR)LoadImage(hMode1,MAKEINTRESOURCE(5001),IMAGE_CURSOR,32,32,LR_DEFAULTCOLOR);
		cursor_redhand=(HCURSOR)LoadImage(hMode1,MAKEINTRESOURCE(5002),IMAGE_CURSOR,0,0,LR_DEFAULTCOLOR);
		cursor_goldlight=(HCURSOR)LoadImage(hMode1,MAKEINTRESOURCE(5003),IMAGE_CURSOR,32,32,LR_DEFAULTCOLOR);   //后续增加光标移动至边缘的改变
		load_cap_num=1;  //...正式版改为1
	}
	else if(x==1)
	{
		load_cap_num=25;
	}
	SetTimer(1,100,NULL);
	sound_control();
}

void CMAINDlg::load_paint()
{
	draw_bmp1(6000,0,0,1);
	if(load_cap_num<17){draw_bmp1(6018,580,325,1);draw_bmp1(load_cap_num+6000,640,420,1);}
	else if(load_cap_num<=24){draw_bmp1(6018,580,325,1);draw_bmp1(6017,640,420,1);}
	else
	{
		if(load_cap_num==25)draw_bmp1(6019,265,210,1);
		else if(load_cap_num==26)draw_bmp1(6020,265,210,1);
		draw_bmp1(6021,1075,180,1);
		draw_bmp1(6022,580,410,1);
		draw_bmp1(6023,600,485,1);
		draw_bmp1(6024,603,565,1);
		draw_bmp1(6025,665,650,1);
		draw_bmp1(6026,600,730,1);
	}
}

void CMAINDlg::load_timer1()
{
	if(load_cap_num<24)load_cap_num++;
	else if(load_cap_num==24){get_data0();load_cap_num++;}  //24时加载data
	else if(load_cap_num==25){load_cap_num=26;}
	else if(load_cap_num==26){load_cap_num=25;}
	this->Invalidate(false);
}

void CMAINDlg::load_cursor()
{
	int num=2;
	for(int i=22;i<=26;i++)
	{
		if(re_bmp[i].PtInRect(mpt)){num=1;}
	}
	if(num==1)SetCursor(cursor_hand);
	else if(num==2)SetCursor(cursor_redhand);
}

void CMAINDlg::load_lb()
{
	if(load_cap_num==25||load_cap_num==26)
	{
		if(re_bmp[22].PtInRect(mpt)){game_initialization(0);}
		else if(re_bmp[23].PtInRect(mpt)){storage_initialization();}
		else if(re_bmp[26].PtInRect(mpt))
		{
			CString str; str.Format("确定退出？"); 
			if(MessageBox(str,"大学轻松么",MB_YESNO)==IDYES)
			{
				if(tmpwav[0]!=NULL)DeleteFile(tmpwav);
				FreeLibrary(hMode1); FreeLibrary(hMode2);
				exit(0);
			}
		}
	}
}