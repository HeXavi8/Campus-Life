//CString str; str.Format("%d",); MessageBox(str,MB_OK);
//story_information.cpp
#include "stdafx.h"
#include "大学轻松么.h"
#include "MAINDlg.h"

void CMAINDlg::find_story()  //此函数在开始游戏或结束某剧情或开始新一天时调用
{
	if(day==1001&&story[0].state==1)load_story(0);
	else if(day==1002&&story[7].state==1)load_story(7);
	else if(day==1003&&story[13].state==1)load_story(13);
	else if(day==1004&&story[15].state==1)load_story(15);
	else if (day==1005&&story[20].state == 1)load_story(20);
	else if (day == 1006 && story[24].state == 1)load_story(24);
	else if (day == 1007 && story[28].state == 1)load_story(28);
	else if (day == 1008 && story[34].state == 1)load_story(34);
	else if (day == 1009 && story[37].state == 1)load_story(37);
	else if (day == 1010 && story[40].state == 1)load_story(40);
	else if (day == 1011 && story[43].state == 1)load_story(43);
	else if (day == 1012 && story[46].state == 1)load_story(46);
	else if (day == 1013 && story[50].state == 1)load_story(50);
	else if (day == 1014 && story[56].state == 1)load_story(56);
	else if (day == 1015 && story[62].state == 1)load_story(62);
	else if (day == 1016 && story[66].state == 1)load_story(66);
	else if (day == 1017 && story[71].state == 1)load_story(71);
	else if (day == 1018 && story[78].state == 1)load_story(78);
	else if (day == 1019 && story[81].state == 1)load_story(81);
	else if (day == 1020 && story[84].state == 1)load_story(84);
	else  //若无必显示剧情，开始处理感叹号如何显示
	{
		for(int i=1;i<=sum_position;i++)show[100+i]=false;  //将所有地点初始化为不显示
		for(int i=0;i<sum_story;i++)   //遍历一次剧情，确定状态
		{
			if(story[i].state==1&&day==story[i].day){show[100+story[i].position]=true;}
		}
		show[11]=true;
	}
	sound_control();
}

void CMAINDlg::load_story(int num)   //点击感叹号时调用
{
	show[0]=true;   show[1]=true;   show[11]=false;
	story_scene=1; game_t11_enter=0; story_num=num;
	if(num==10)energy-=5;
	else if(num==11)energy-=6;
	else if(num==17)energy-=4;
	else if(num==18)energy-=1;
	else if (num == 25)energy -= 4;
	else if (num == 26)energy -= 4;
	else if (num == 33)energy -= 1;
	else if (num == 36)energy -= 4;
	else if (num == 42)energy -= 4;
	else if (num == 47)energy -= 1;
	else if (num == 52)energy -= 4;
	else if (num == 55)energy -= 2;
	else if (num == 57)energy -= 7;
	else if (num == 62)energy -= 13;
	else if (num == 65)energy -= 3;
	else if (num == 72)energy -= 5;
	else if (num == 83)energy -= 2;
	else if (num == 84)energy -= 1;
	else if (num == 85)energy -= 1;
	if(energy<=0)
	{
		energy=0;
	}
	sound_control();
}

void CMAINDlg::end_story(int num)   //退出剧情时调用
{
	story_information_initialization(story_num);
	story[num].state=2;
	story_num=-1;   story_scene=-1;

	if(num==1){story[2].state=1;}
	else if(num==2){story[6].state=1;}
	else if (num == 8) { story[22].state = 1; story[27].state = 1;story[33].state = 1;story[35].state = 1;story[47].state = 1;story[54].state = 1;story[68].state = 1;story[72].state = 1;story[82].state = 1;story[85].state = 1; }
	else if (num == 9) { story[23].state = 1; story[32].state = 1;story[38].state = 1;story[41].state = 1;story[48].state = 1;story[55].state = 1;story[57].state = 1; }
	else if (num == 1) { story[26].state = 1; story[42].state = 1;story[52].state = 1;story[65].state = 1;story[76].state = 1;story[83].state = 1;}
	else if (num == 15) { story[31].state = 1;  story[39].state = 1; }
	else if (num == 55) { story[58].state = 1; }
	else if (num == 53) { story[63].state = 1; }
	else if (num == 55) { story[64].state = 1; }
	else if (num == 1) {  }
	else if (num == 55) { story[67].state = 1; }
	else if (num == 8) {  }
	else if (num == 55) { story[69].state = 1; }
	else if (num == 8) {  }
	else if (num == 55) { story[73].state = 1; }
	else if (num == 68) { story[75].state = 1; }
	else if (num == 1) {  }
	else if (num == 55) { story[77].state = 1; }
	else if (num == 55) { story[81].state = 1; }
	else if (num == 8) {  }
	else if (num == 1) {  }
	else if (num == 55) { story[84].state = 1; }
	else if (num == 8) {  }
	else if (num ==19 ){SAN+=2;}

	
	show[2]=false; show[0]=false; show[11]=true;
	find_story();
}

void CMAINDlg::first_play()  //用户第一次玩(没有存档)时为从存档中读取的变量赋值
{
	day=1001; energy=50; energy_limit=100;
	SAN=20; wisdom=10; perseverance=5; EQ=20; moral=20;
	for(int i=0;i<100;i++)
	{
		if(i==2||i==6||i==10||i==11||i==12||i==17||i==18||i==22||i==23||i==26||i==27||i==31||i==32||i==33||i==35||i==38||i==39||i==41||i==42||i==47||i==48||i==52||i==54||i==55||i==57||i==58||i==63||i==64||i==65||i==67||i==68||i==69||i==72||i==73||i==75||i==76||i==77||i==81||i==82||i==83||i==84||i==85)story[i].state=0;
		else story[i].state=1;
	}
}