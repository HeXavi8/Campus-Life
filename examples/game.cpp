//CString str; str.Format("%d",); MessageBox(str,MB_OK);
//game.cpp
#include "stdafx.h"
#include "��ѧ����ô.h"
#include "MAINDlg.h"

void CMAINDlg::game_initialization(int x)   //Ӧ�����б����ɴ����浵��ֵһ�飬������ԭֵ��
{
	window=2;
	//������ԭ�м�ʱ�� �ڶ�ȡ�浵���� �۱��浱ǰ�������
	if(x==0)  //x=0��ʾ��һ������Ϸ��û�д浵
	{
		KillTimer(1);
		if(last_storage_num==0)
		{
			last_storage_num=1; give_data0();  //���ı��last_storage_num����zzz.dat
			get_data1(1);
		}
		else{
			for(int i=1;i<=3;i++){ if(last_storage_num==i)get_data1(i); }
		}
	}
	else{ //x��ʾ��x���浵
		last_storage_num=x; give_data0();
		get_data1(x);
	}
	//��ʼ���¼�����
	story_num=-1;
	story_scene=-1;
	story_information_initialization(-1);
	for(int i=0;i<200;i++)show[i]=false;
	last_choice=1;
	//��ʼ����ͼ����
	ismove=false; mapx=-445; mapy=-865; downpointx=0; downpointy=0; downmapx=0; downmapy=0;
	game_t11_enter=0; game_t11_gantan=0; game_t11_pic=0;
	SetTimer(11,60,NULL);
	//��ʼ
	find_story();
}

void CMAINDlg::game_paint()
{
	if(show[0])
	{
		draw_bmp2(0,0,0,0,150+game_t11_enter*6,150+game_t11_enter*6,150+game_t11_enter*6);
		if(game_t11_enter==10)
		{
			char* c1=new char;
			draw_bmp1(judge_pic(story[story_num].pic),0,0,1);
			//draw_bmp1(6141,85,580,1);
			if(story_scene%2==0)text1("����",17,40,1400,0,0,0,0,665,1500,1000,w1(c1));
			else text1("����",17,40,1400,0,0,0,0,665,1500,1000,w1(c1));
			delete[] c1;
		}
	}
	if(show[11])
	{
		draw_bmp1(6000,0,0,1);
		if(setting_frame==3)draw_bmp1(6101,mapx,mapy,1);
		else if(setting_frame==2)draw_bmp1(6102,0,0,1);
		draw_bmp1(6105,330,50,1);
		draw_bmp1(6106,1360,850,1);
		draw_bmp2(453,74,3*energy,35,255,0,0);
		for(int i=1;i<=sum_position;i++)  //�ݶ��ص���
		{
			if(show[100+i])
			{
				if(setting_frame==3)
				{
					draw_bmp1(6113+(i/3)*2+game_t11_gantan/10,mapx+positionx[i],mapy+positiony[i],1);
					re_position[i].SetRect(positionx[i]+mapx,positiony[i]+mapy,positionx[i]+mapx+37,positiony[i]+mapy+71);
				}
				else if(setting_frame==2)
				{
					draw_bmp1(6113+(i/3)*2+game_t11_gantan/10,positionx[i],positiony[i],1);
					re_position[i].SetRect(positionx[i],positiony[i],positionx[i]+37,positiony[i]+71);
				}
			}
		}
	}
	if(show[12])
	{
		draw_bmp1(6000,0,0,1);
		draw_bmp1(6107,0,0,1);
		for(int i=0;i<5;i++){draw_bmp1(6108+i,240+i*200,245,1);}
	}
	if(show[21])
	{
		draw_bmp1(6000,0,0,1);
		draw_bmp1(6151,0,0,1);
		draw_bmp1(6152+game_t11_gantan/10,200,250,1);
	}
}

void CMAINDlg::game_lb()
{
	if(show[0]&&game_t11_enter==10)
	{
		if(story[story_num].choice_scene!=story_scene)
		{
			if(story_scene<story[story_num].max_scene)story_scene++;
			else {show[2]=true;}
		}
	}
	if(show[11])
	{
		for(int i=1;i<=sum_position;i++) //�ݶ��ص���
		{
			if(re_position[i].PtInRect(mpt)&&show[100+i])
			{
				for(int j=0;j<sum_story;j++)   //��ʱ������
				{
					if(day==story[j].day&&story[j].state==1&&story[j].position==i){load_story(j);return;}
				}
			}
		}
		if(re_bmp[106].PtInRect(mpt))
		{
			show[11]=false; show[12]=true; ismove=false;
		}
		//��������������ѡ��
		if(setting_frame==3){downpointx=mpt.x; downpointy=mpt.y; downmapx=mapx; downmapy=mapy; ismove=true;}
	}
	if(show[12])
	{
		//if(re_bmp[108].PtInRect(mpt)){show[21]=true; show[12]=false;}
		CRect back(1350,475,1400,525);
		if(back.PtInRect(mpt)){show[12]=false; show[11]=true; find_story();}
	}
}

void CMAINDlg::game_lbu()
{
	if(show[11]&&setting_frame==3)
	{
		if(ismove)ismove=false;
	}
}

void CMAINDlg::game_mm()
{
	if(ismove&&setting_frame==3)
	{
		CRect rect(10,10,1490,990);
		if(!rect.PtInRect(mpt))ismove=false;
		mapx=downmapx-(downpointx-mpt.x)*1.5; if(mapx>-30)mapx=-30; if(mapx<-680)mapx=-680;
		mapy=downmapy-(downpointy-mpt.y)*1.5; if(mapy>-50)mapy=-50;  if(mapy<-1640)mapy=-1640;
	}
}

void CMAINDlg::game_timer1()
{
	if(show[0])
	{
		if(show[1]) //�������ʱ
		{
			if(game_t11_enter<10){game_t11_enter++;}
			else if(game_t11_enter==10){show[1]=false;}
		}
		if(show[2]) //�˳�����ʱ
		{
			if(game_t11_enter>3)game_t11_enter--;
			else
			{
				game_t11_enter=0;
				end_story(story_num);
			}
		}
		if(game_t11_pic<29){game_t11_pic++;}
		else if(game_t11_pic==29){game_t11_pic=0;}
	}
	else if(show[11]||show[12]||show[21])
	{
		game_t11_gantan++;
		if(game_t11_gantan==20)game_t11_gantan=0;
	}
	this->Invalidate(false);
}

void CMAINDlg::game_cursor()
{
	int num=2;
	if(show[0])
	{
		num=3;
	}
	else if(show[11])
	{
		for(int i=1;i<=sum_position;i++)  //�ݶ��ص���
		{
			if(show[100+i])
			{
				if(re_position[i].PtInRect(mpt)){num=1;}
			}
		}
		if(re_bmp[106].PtInRect(mpt)){num=1;}
	}
	else if(show[12])
	{
		for(int i=0;i<5;i++){ if(re_bmp[108+i].PtInRect(mpt))num=1; }
		CRect back(1340,465,1410,535);  if(back.PtInRect(mpt)){num=1;}
	}
	if(num==1)SetCursor(cursor_hand);
	else if(num==2)SetCursor(cursor_redhand);
	else if(num==3)SetCursor(cursor_goldlight);
}