
//storage.cpp
#include "stdafx.h"
#include "大学轻松么.h"
#include "MAINDlg.h"

void CMAINDlg::storage_initialization()
{
	window=1;  KillTimer(1);
	storage_type=0;  //判断是档案还是成就
	sound_control();
}

void CMAINDlg::storage_paint()
{
	draw_bmp1(6000,0,0,1);
	if(storage_type==0)
	{
		draw_bmp1(6051,150,100,1);
		draw_bmp1(6056,210,170,1);
		draw_bmp1(6057,215,395,1);
		draw_bmp1(6058,215,600,1);
		draw_bmp1(6055,1252,108,1);
	}
	else if(storage_type==1)
	{
		draw_bmp1(6052,150,100,1);
		draw_bmp1(6055,1265,106,1);
	}
	draw_bmp1(6053,230,118,1);
	draw_bmp1(6054,395,112,1);
}

void CMAINDlg::storage_cursor()
{
	int num=2;
	for(int i=53;i<=55;i++)
	{
		if(re_bmp[i].PtInRect(mpt)){num=1;}
	}
	if(storage_type==0)
	{
		for(int i=56;i<=58;i++)
		{
			if(re_bmp[i].PtInRect(mpt)){num=1;}
		}
	}
	if(num==1)SetCursor(cursor_hand);
	else if(num==2)SetCursor(cursor_redhand);
}

void CMAINDlg::storage_lb()
{
	if(re_bmp[53].PtInRect(mpt)){storage_type=0;}
	else if(re_bmp[54].PtInRect(mpt)){storage_type=1;}
	else if(re_bmp[55].PtInRect(mpt)){load_initialization(1);}
	for(int i=56;i<=58;i++)
	{
		if(re_bmp[i].PtInRect(mpt)){game_initialization(i-55);}
	}
}