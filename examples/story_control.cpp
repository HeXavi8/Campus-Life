//CString str; str.Format("%d",); MessageBox(str,MB_OK);
//story_control.cpp
#include "stdafx.h"
#include "大学轻松么.h"
#include "MAINDlg.h"

void CMAINDlg::deal_choice(int num)   //剧情中按下数字键时调用
{
	if(story[story_num].choice_scene==story_scene&&(num>=1&&num<=story[story_num].choice))  //判断按键是否合法
	{
		if(story_num==1)
		{
			if(num==1)
			{
				//开启班委支线
				story[12].state=1;
			}
		}
		else if(story_num==3)
		{
			if(num==1){SAN-=2; perseverance+=2;}
			else if(num==2){play2(4004);SAN+=3; perseverance-=2;}
		}
		else if(story_num==5)
		{
			if(story[story_num].max_scene==8)
			{
				if(num==1){wisdom+=1;}
				else if(num==2){story[story_num].max_scene=12; story[story_num].choice_scene=11; EQ+=1;}
			}
			else if(story[story_num].max_scene==12)
			{
				if(num==1){wisdom+=1;}
				else if(num==2){story[story_num].max_scene=16; story[story_num].choice_scene=15; EQ+=1;}
			}
		}
		else if(story_num==8)
		{
			if(num==1)
			{
				EQ+=6; energy_limit-=20;
				//开启社团支线
				story[10].state=1;
				story[17].state=1;
			}
			else if(num==2){wisdom+=5;}
		}
		else if(story_num==9)
		{
			if(num==1)
			{
				EQ+=6; energy_limit-=20;
				//开启学生会支线
				story[11].state=1;
			}
			else if(num==2){wisdom+=5;}
		}
		else if(story_num==10)
		{
			if(num==1){EQ+=1;}
			else if(num==2){EQ+=2;}
		}
		else if(story_num==11)
		{
			if(num==1){EQ+=1;}
			else if(num==2){EQ+=1;}
		}
		else if(story_num==12)
		{
			if(num==1){EQ+=2;wisdom+=1;energy-=3;}
			else if(num==2){EQ+=1;wisdom+=2;energy-=4;}
		}
		else if(story_num==14)
		{
			if(num==1){EQ-=1; SAN-=1;}
			else if(num==2){SAN-=1;}
			else if(num==3){EQ+=1;}
		}
		else if(story_num==15)
		{
			if(num==1){EQ+=5;}
			else if(num==2){wisdom+=3;}
		}
		else if(story_num==16)
		{
			if(num==1){perseverance-=1; SAN+=2;}
			else if(num==2){perseverance+=1;  wisdom+=1;}
		}
		else if(story_num==17)
		{
			if(num==1){SAN+=1;}
			else if(num==2){EQ+=1;}
		}
		else if (story_num == 18)
		{
			if (num == 2) { SAN += 1; }
		}
		else if (story_num == 20)
		{
			if (num == 1) { EQ += 1; }
			else if (num == 2) 
			{
				perseverance += 1;
				if (num == 3){ perseverance -= 1; }
				if (num == 4) { if (perseverance > 25) { perseverance += 4; } }
			}
		}
		else if (story_num == 21)
		{
			if (num == 1) { SAN += 2; }
		}
		else if (story_num == 22)
		{
		}
		else if (story_num == 23)
		{
			if (num == 1) { EQ += 1; energy-=7;}
			else if(num == 2){ energy -= 3; }
		}
		else if (story_num == 24)
		{
			if (num == 1) { moral += 2; energy -= 5;EQ+=1; }
			else if (num == 2) { moral -= 1; }
		}
		else if (story_num == 25)
		{
			if (num == 1) { wisdom += 1; }
			else if (num == 2) { EQ += 1; }
		}
		else if (story_num == 26)
		{
		}
		else if (story_num == 27)
		{
			if (num == 1) { moral += 2, EQ+=1, energy-=8;}
			else if (num == 2) { energy -= 3 ;}
		}
		else if (story_num == 28)
		{
		}
		else if (story_num == 29)
		{
			if (num == 1) { EQ += 1; }
			else if (num == 2) { moral += 1; }
		}
		else if (story_num == 30)
		{
			if (num == 1) { wisdom -= 1, SAN += 3, energy -= 5 ;}
			else if (num == 2) { wisdom += 2, SAN -= 1, energy -= 2; }
		}
		else if (story_num == 31)
		{
			if (num == 1) { EQ+= 1, SAN -= 1;}
			else if (num == 2) { SAN -= 1; }
			else if (num == 3) { SAN -= 2 ;}
		}
		else if (story_num == 32)
		{
			if (num == 1) { EQ -= 2, wisdom += 1, energy -= 2 ;}
			else if (num == 2) { wisdom -= 1, EQ += 1, energy -= 5 ;}
		}
		else if (story_num == 33)
		{
		}
		else if (story_num == 34)
		{
			if (num == 1) {  SAN += 2 ;}
			else if (num == 2) { SAN += 2 ;}
		}
		else if (story_num == 35)
		{
			if (num == 1) { SAN += 2,EQ+=1,energy-=5 ;}
			else if (num == 2) { wisdom += 2,energy-=1 ;}
		}
		else if (story_num == 36)
		{
		}
		else if (story_num == 37)
		{
			if (num == 1) { wisdom += 5, perseverance += 2, energy -= 5 ;}
			else if (num == 2) { wisdom += 3, perseverance += 2, energy -= 5 ;}
			else if (num == 3) { wisdom += 3 ;}
		}
		else if (story_num == 38)
		{
			if (num == 1) { SAN += 5 ;}
			else if (num == 2) { wisdom += 2, perseverance += 1 ;}
		}
		else if (story_num == 39)
		{
			if (num == 1) { wisdom -= 2, energy -= 5;}
			else if (num == 2) { SAN-=2, energy -= 5 ;}
		}
		else if (story_num == 40)
		{
			if (num == 1) { wisdom += 2, EQ += 1, moral += 1 ;}
			else if (num == 2) { wisdom += 3, EQ += 2 ;}
		}
		else if (story_num == 41)
		{
			if (num == 1) { wisdom += 1, EQ -= 3,SAN -=1,energy-=4;}
			else if (num == 2) { wisdom -= 3, EQ += 1, SAN -= 1, energy -= 3; }
		}
		else if (story_num == 42)
		{
		}
		else if (story_num == 43)
		{
			if (num == 1) { wisdom += 3,energy -= 2; }
			else if (num == 2) { wisdom += 2, EQ += 1; }
			else if (num == 3) { wisdom += 2 ;}
		}
		else if (story_num == 44)
		{
			if (num == 1) { EQ += 1, SAN -= 2; }
			else if (num == 2) { SAN -= 1; }
			else if (num == 3) { SAN -= 2; }
		}
		else if (story_num == 45)
		{
			energy-=3,wisdom+=2,EQ+=2,moral+=1;
		}
		else if (story_num == 46)
		{
			if (num == 1) { SAN += 1; }
			else if (num == 2) { wisdom += 2, energy -= 5; }
			else if (num == 5) { EQ += 1 ;}
			else if (num == 6) { wisdom += 1 ;}
		}
		else if (story_num == 47)
		{
		}
		else if (story_num == 48)
		{
		}
		else if (story_num == 50)
		{
			if (num == 1) { EQ += 1, moral += 2; }
			else if (num == 2) { wisdom += 1 ;}
		}
		else if (story_num == 51)
		{
			if (num == 1) { energy -= 5; }
			else if (num == 2) { energy -= 3; }
		}
		else if (story_num == 52)
		{
			if (num == 1) { energy -= 5 ;}
			else if (num == 2) { energy -= 3; }
		}
		else if (story_num == 53)
		{
			if (num == 1) { energy -= 4,EQ+=2; }
			else if (num == 2) { EQ+=1,energy-=1; }
		}
		else if (story_num == 55)
		{
			if (num == 1) { energy -= 9, EQ += 2; }
			else if (num == 2) { EQ += 1, energy -= 3,wisdom+=1; }
		}
		else if (story_num == 56)
		{
			if (num == 1) { energy -= 2, SAN += 2; }
			else if (num == 2) { energy -= 1, SAN += 2; }
		}
		else if (story_num == 58)
		{
			if (num == 1) { energy -= 6, EQ += 2,wisdom+=1; }
			else if (num == 2) { energy -= 4, EQ += 1,SAN-=1; }
		}
		else if (story_num == 59)
		{
			if (num == 1) { energy -= 8, SAN += 3 ;}
			else if (num == 2) { energy -= 1, EQ += 2, SAN -= 1,wisdom+=2 ;}
		}
		else if (story_num == 60)
		{
			if (num == 1) { energy -= 2,EQ+=1,wisdom+=1, SAN += 1; }
			else if (num == 2) { energy -= 4, EQ += 2, wisdom += 2; }
		}
		else if (story_num == 61)
		{
			if (num == 1) { energy -= 5, SAN += 1; }
			else if (num == 2) { energy -= 1,wisdom += 1; }
		}
		else if (story_num == 63)
		{
			energy -= 2, SAN += 5 ,EQ+=1;
		}
		else if (story_num == 64)
		{
			energy -= 5, SAN += 1, EQ += 2;
		}
		else if (story_num == 66)
		{
			if (num == 1) { wisdom += 2,EQ+=1, SAN += 1; }
			else if (num == 2) { wisdom += 1, EQ += 2,SAN+=5; }
		}
		else if (story_num == 67)
		{
			if (num == 1) { energy-=2,SAN += 1 ;}
			else if (num == 2) { energy-=2; }
			else if (num == 3) { energy-=2,SAN += 1; }
			else if (num == 4) { energy-=2; }
		}
		else if (story_num == 68)
		{
			if (num == 1) { energy-= 2, EQ -= 1, wisdom += 1; }
			else if (num == 2) { energy -= 5, EQ += 1; }
		}
		else if (story_num == 69)
		{
			if (num == 1) { energy -= 6, EQ  += 1, SAN += 2; }
			else if (num == 2) { energy -= 5, EQ += 2,SAN+=2; }
		}
		else if (story_num == 70)
		{
			if (num == 1) { energy -= 3, wisdom+=3,EQ += 1; }
			else if (num == 2) { energy -= 2,wisdom+=2,EQ+=1; }
			else if (num == 3) { energy -= 2, wisdom += 2,EQ+=2; }
			else if (num == 4) { energy -= 2 ,wisdom+=1,EQ+=1; }
		}
		else if (story_num == 71)
		{
			if (num == 1) { energy -= 5, moral += 2, EQ += 2, wisdom += 1; }
			else if (num == 2) { energy -= 1, EQ += 1, wisdom += 2 ;}
		}
		else if (story_num == 73)
		{
			if (num == 1) { energy -= 5, SAN -= 2, EQ += 2, wisdom += 2; }
			else if (num == 2) { energy -= 3, EQ += 1, wisdom += 2; }
		}
		else if (story_num == 74)
		{
			if (num == 1) { energy -= 2, SAN += 1, EQ += 2; }
			else if (num == 2) { energy -= 2, SAN += 1, EQ += 2; }
			else if (num == 3) { energy -= 2, SAN += 1, EQ += 1 ;}
			else if (num == 4) { energy -= 2, SAN += 1, EQ += 2; }
		}
		else if (story_num == 75)
		{
			energy -= 4, SAN += 7, EQ += 1;
		}
		else if (story_num == 76)
		{
			energy -= 3;
		}
		else if (story_num == 77)
		{
			if (num == 1) { energy -= 2, SAN -= 1, EQ += 1 ;}
			else if (num == 2) { energy -= 2, SAN -= 2; }
		}
		else if (story_num == 78)
		{
			if (num == 1) { energy -= 4, wisdom += 1 ;}
			else if (num == 2) { energy -= 5, wisdom += 2,EQ+=1; }
			else if (num == 2) { energy -= 3, EQ -= 1 ;}
		}
		else if (story_num == 79)
		{
			if (num == 1) { energy -= 3, SAN += 2, EQ += 2; }
			else if (num == 2) { energy -= 1, SAN += 1,wisdom+=2; }
		}
		else if (story_num == 80)
		{
			if (num == 1) { energy -= 3, wisdom += 2, EQ += 1 ;}
			else if (num == 2) { energy -= 5, EQ += 2, wisdom += 1; }
		}
		else if (story_num == 81)
		{
			if (num == 1) { energy -= 4, SAN -= 1, EQ += 2 ;}
			else if (num == 2) { energy -= 5, SAN -= 1, EQ -= 1 ;}
			else if (num == 3) { energy -= 2, SAN += 2, EQ += 2,wisdom+=1; }
			else if (num == 4) { energy -= 1, wisdom += 2, EQ += 1; }
		}
		else if (story_num == 82)
		{
			if (num == 4) { energy -= 5; }
			else if (num == 5) { energy -= 1; }
			else if (num == 1|| num == 2|| num == 3) { energy -= 3 ;}
		}
		else if (story_num == 86)
		{
			if (num == 1) { energy -= 3,EQ+=1; }
			else if (num == 2) { energy -= 5,EQ+=2 ;}
		}
		else if (story_num == 87)
		{
			if (num == 1) { energy -= 2, SAN+=7,EQ += 2; }
			else if (num == 2) { energy -= 2, SAN+=4,EQ += 2; }
		}
		last_choice=num;
		if(story_scene<story[story_num].max_scene)story_scene++;
		else show[2]=true;
	}
}