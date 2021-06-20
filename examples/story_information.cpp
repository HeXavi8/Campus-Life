//CString str; str.Format("%d",); MessageBox(str,MB_OK);
//story_information.cpp
#include "stdafx.h"
#include "大学轻松么.h"
#include "MAINDlg.h"

void CMAINDlg::find_story()  //此函数在开始游戏或结束某剧情或开始新一天时调用
{
	if(logic[15]==1){load_story(117);}
	else if(day==1001&&story[0].state==1)load_story(0);
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
	else if (day == 1013 && story[49].state == 1)load_story(49);
	else if (day == 1014 && story[56].state == 1)load_story(56);
	else if (day == 1015 && story[62].state == 1)load_story(62);
	else if (day == 1016 && story[66].state == 1)load_story(66);
	else if (day == 1018 && story[71].state == 1)load_story(71);
	else if (day == 1020 && story[78].state == 1)load_story(78);
	else if (day == 1021 && story[81].state == 1)load_story(81);
	else if (day == 1022 && story[84].state == 1)load_story(84);
	else if (day == 1023 && story[88].state == 1)load_story(88);
	else  //若无必显示剧情，开始处理感叹号如何显示
	{
		show[11]=true;
		for(int i=1;i<=sum_position;i++)show[100+i]=false;  //将所有地点初始化为不显示
		int sum=0;
		for(int i=0;i<sum_story;i++)   //遍历一次剧情，确定状态
		{
			if(story[i].state==1&&day==story[i].day){show[100+story[i].position]=true;sum=i;}
		}
		sound_control();
		if(sum==0&&logic[15]==0)
		{
			CString str; str.Format("本周所有剧情已结束，是否直接进入下一周？"); 
			if(MessageBox(str,"时光虫洞",MB_YESNO)==IDYES)
			{
				day++;  if(day==1035)logic[15]=1;
				energy+=10;
				if(day>=1022&&logic[4]==1)energy-=10;
				if(energy>=energy_limit)energy=energy_limit;
				find_story();
			}
		}
	}
}

void CMAINDlg::load_story(int num)   //点击感叹号时调用
{
	show[0]=true;   show[1]=true;   show[11]=false;
	story_scene=1; game_t11_enter=0; story_num=num;
	if(num==10)energy-=5;
	else if(num==11)energy-=6;
	else if(num==17)energy-=4;
	else if(num==18)energy-=1;
	else if(num==22)play2(4016);
	else if (num == 25)energy -= 4;
	else if (num == 26)energy -= 4;
	else if (num == 33)energy -= 1;
	else if (num == 36)energy -= 4;
	else if (num == 42)energy -= 4;
	else if (num == 45)energy -= 3;
	else if (num == 47)energy -= 1;
	else if (num == 52)energy -= 4,perseverance+=3;
	else if (num == 55)energy -= 2;
	else if (num == 57)energy -= 7;
	else if (num == 62)energy -= 13;
	else if (num == 63)energy -= 2;
	else if (num == 64)energy -= 5;
	else if (num == 65)energy -= 3;
	else if (num == 72)energy -= 5;
	else if (num == 75)energy -= 4;
	else if (num == 76)energy -= 3;
	else if (num == 83)energy -= 2;
	else if (num == 84)energy -= 1;
	else if (num == 85)energy -= 1;
	else if(num==88){if(logic[2]==1)cgl=15;else cgl=10;}
	if(energy<=40){energy=40;}
	if(energy>=energy_limit){energy=energy_limit;}
	if(cgl>100)cgl=100;
	sound_control();
}

void CMAINDlg::end_story(int num)   //退出剧情时调用
{
	if(num==1){story[2].state=1;}
	else if(num==2){story[6].state=1;}
	else if (num ==19 ){SAN+=2;}
	else if (num ==45 ){wisdom+=2,EQ+=2,moral+=1;}
	else if (num ==63 ){SAN += 5 ,EQ+=1;}
	else if (num ==64 ){SAN += 1, EQ += 2;}
	else if (num ==75 ){SAN += 7, EQ += 1;}
	else if(num==95){wisdom+=5;EQ+=4;perseverance+=3;SAN+=5;energy-=4;}
	else if(num==97){SAN+=3;perseverance+=8;energy-=6;}
	else if(num==110){if(cgl>=45){SAN+=7;energy-=2;wisdom+=2;EQ+=2;}else{   for(int i=story_num+1;i<sum_story;i++){if(story_type(i)==7)story[i].state=0;}  }}
	else if(num==111){wisdom+=2;EQ+=3;SAN+=3;energy-=4;}
	else if(num==113){cgl+=10;}
	else if(num==115){if(logic[8]==1)SAN+=3; else SAN-=3;}

	if(energy<=40){energy=40;}
	if(energy>=energy_limit){energy=energy_limit;}
	if(cgl>100)cgl=100;
	story_information_initialization(story_num);
	story[num].state=2;
	story_num=-1;   story_scene=-1;
	show[2]=false; show[0]=false; show[11]=true;
	if(logic[15]==0)find_story();
	else{give_data1(last_storage_num);load_initialization(1);}
}

void CMAINDlg::first_play()  //用户第一次玩(没有存档)时为从存档中读取的变量赋值
{
	day=1001; energy=50; energy_limit=100;
	SAN=20; wisdom=10; perseverance=10; EQ=20; moral=20;
	for(int i=0;i<150;i++)
	{
		if(story_type(i)!=0)story[i].state=0;
		else if(i==2)story[i].state=0;    //事件1班会结束后才发生
		else if(i==6)story[i].state=0;    //事件2去过图书馆一次后才发生
		else if(i==63)story[i].state=0;    //事件53选A帮助大一生才发生
		else if(i==92)story[i].state=0;    //事件89选A购置复印机才发生
		else story[i].state=1;
	}
	for(int i=0;i<20;i++)logic[i]=0;
	cgl=0;
}

int CMAINDlg::story_type(int i)
{
	if(i==18||i==31||i==39){return 1;}  //班级晚会
	else if(i==12||i==26||i==42||i==52||i==65||i==76||i==83){return 2;}  //班委
	else if(i==10||i==17||i==22||i==27||i==33||i==35||i==47||i==54||i==68||i==72||i==75||i==82||i==85){return 3;}   //社团
	else if(i==11||i==23||i==32||i==38||i==41||i==48||i==55||i==57){return 4;}   //学生会大一
	else if(i==58||i==64||i==67||i==69||i==73||i==77||i==81||i==84){return 5;}   //学生会留任
	else if(i==95||i==98||i==100||i==103||i==105||i==109){return 6;}   //情感
	else if(i==93||i==94||i==96||i==97||i==101||i==104||i==107||i==110||i==113||i==116){return 7;}   //创业
	else if(i==106||i==108||i==112){return 8;}   //企业
	else if(i==111||i==114){return 9;}   //考研
	else {return 0;}   //主线+其他小支线
}