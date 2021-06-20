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
				story[26].state = 1;
				story[42].state = 1;
				story[52].state = 1;
				story[65].state = 1;
				story[76].state = 1;
				story[83].state = 1;
			}
		}
		else if(story_num==3)
		{
			if(num==1){SAN-=2; perseverance+=2;}
			else if(num==2){play2(4004);SAN+=3; perseverance-=2;}
		}
		else if(story_num==5)
		{
			if(story[story_num].choice_scene==7)
			{
				if(num==1){wisdom+=1;}
				else if(num==2){story[story_num].max_scene=12; story[story_num].choice_scene=11; EQ+=1;}
			}
			else if(story[story_num].choice_scene==11)
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
				story[22].state = 1;
				story[27].state = 1;
				story[33].state = 1;
				story[35].state = 1;
				story[47].state = 1;
				story[54].state = 1;
				story[68].state = 1;
				story[72].state = 1;
				story[75].state = 1;
				story[82].state = 1;
				story[85].state = 1;

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
				story[23].state = 1; 
				story[32].state = 1;
				story[38].state = 1;
				story[41].state = 1;
				story[48].state = 1;
				story[55].state = 1;
				story[57].state = 1;
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
			if(num==1)
			{
				EQ+=5;
				story[18].state = 1;  
				story[31].state = 1;
				story[39].state = 1;
			}
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
			if (story_scene == 3)
			{
				if (num == 1) { EQ += 1; }
				else if (num == 2)
				{
					perseverance += 1;
					story[story_num].max_scene = 7; story[story_num].choice_scene = 5; story[story_num].choice = 2;
				}
			}
			else if (story_scene == 5)
			{
				story[story_num].choice_scene = 7; story[story_num].choice = 2;
			}
			else if (story_scene == 7)
			{
				if (num == 1) { perseverance -= 1; }
				else if (num == 2) 
				{ 
					if (perseverance > 10) { perseverance += 4; } 
					else story[story_num].max_scene = 8; 
				}
			}
		}
		else if (story_num == 21)
		{
			if (num == 1) { SAN += 2; play2(4004);}
			else if(num==2){play2(4004);}
		}
		else if(story_num==22)
		{
			play2(4016);
			if(num==1){story[story_num].max_scene=6;}
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

		else if (story_num == 27)
		{
			if (num == 1) { moral += 2, EQ+=1, energy-=8;}
			else if (num == 2) { energy -= 3 ;}
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

		else if (story_num == 34)
		{
			if (num == 1) {  SAN += 2 ;}
			else if (num == 2) { SAN += 2 ;}
		}
		else if (story_num == 35)
		{
			if (num == 1) { SAN += 2,EQ+=1,energy-=5 ;story[story_num].max_scene=3;}
			else if (num == 2) { wisdom += 2,energy-=1 ;}
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

		else if (story_num == 46)
		{
			if(story_scene == 1)
			{
				if (num == 1) { SAN += 1; }
				else if (num == 2) { wisdom += 2, energy -= 5; }
				story[46].choice_scene = 2;
			}
			else if(story_scene == 2)
			{
				story[46].choice_scene = 3;
			}
			else if(story_scene == 3)
			{
				if (num == 1) { EQ += 1 ;}
				else if (num == 2) { wisdom += 1 ;}
			}
		}

		else if (story_num == 50)
		{
			if (num == 1) { EQ += 1, moral += 2;perseverance+=2;SAN+=2 ;}
			else if (num == 2) { wisdom += 1 ;}
		}
		else if (story_num == 51)
		{
			if (num == 1) { energy -= 5; }
			else if (num == 2) { energy -= 3; }
		}

		else if (story_num == 53)
		{
			if (num == 1) { energy -= 4,EQ+=2;SAN+=1; story[story_num].max_scene=3; story[63].state = 1;logic[0]=1; }
			else if (num == 2) { EQ+=1,energy-=1;logic[0]=2; }
		}
		else if (story_num == 55)
		{
			if (num == 1) 
			{ 
				energy -= 9, EQ += 2,perseverance+=5;
				for(int i=story_num+1;i<sum_story;i++)
				{
					if(story_type(i)==5){story[i].state = 1;}
				}
				story[story_num].max_scene=3;
				logic[2]=1;
			}
			else if (num == 2) { EQ += 1, energy -= 3,wisdom+=1;logic[2]=2; }
		}
		else if (story_num == 56)
		{
			if (num == 1) { energy -= 2, SAN += 2; }
			else if (num == 2) { energy -= 1, SAN += 2; }
		}
		else if (story_num == 57)
		{
			if (num == 2) { story[story_num].max_scene=5; }
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
			if (num == 1) { energy-= 2, EQ -= 1, wisdom += 1;logic[1]=1; }
			else if (num == 2){ energy -= 5, EQ += 1; logic[1]=2;}
		}
		else if (story_num == 69)
		{
			if (num == 1) { energy -= 6, EQ  += 1, SAN += 2; }
			else if (num == 2) { energy -= 5, EQ += 2,SAN+=2; }
		}
		else if (story_num == 70)
		{
			if(story_scene == 2)
			{
				if (num == 1) { energy -= 3, wisdom+=3,EQ += 1;perseverance+=3; }
				else if (num == 2) { energy -= 2,wisdom+=2,EQ+=1;perseverance+=2; }
				story[story_num].choice_scene = 4; story[story_num].choice = 2;
			}
			else if(story_scene == 4)
			{
				if (num == 1) { energy -= 2, wisdom += 2,EQ+=2; }
				else if (num == 2) { energy -= 2 ,wisdom+=1,EQ+=1; }
			}
		}
		else if (story_num == 71)
		{
			if (num == 1) { energy -= 5, moral += 2, EQ += 2, wisdom += 1; perseverance+=3;}
			else if (num == 2) { energy -= 1, EQ += 1, wisdom += 2 ;}
		}
		else if (story_num == 73)
		{
			if (num == 1) { energy -= 5, SAN -= 2, EQ += 2, wisdom += 2; }
			else if (num == 2) { energy -= 3, EQ += 1, wisdom += 2; }
		}
		else if (story_num == 74)
		{
			if(story_scene==2)
			{
				if (num == 1) { energy -= 2, SAN += 1, EQ += 2; perseverance+=3;}
				else if (num == 2) { energy -= 2, SAN += 1, EQ += 2; }
				story[story_num].choice_scene = 5;
			}
			else if(story_scene==5)
			{
				if (num == 1) { energy -= 2, SAN += 1, EQ += 1 ;}
				else if (num == 2) { energy -= 2, SAN += 1, EQ += 2; }
			}
		}
		else if (story_num == 77)
		{
			if (num == 1) { energy -= 2, SAN -= 1, EQ += 1 ;}
			else if (num == 2) { energy -= 2, SAN -= 2; }
		}
		else if (story_num == 78)
		{
			if (num == 1) { energy -= 4, wisdom += 1 ;perseverance+=1;}
			else if (num == 2) { energy -= 5, wisdom += 2,EQ+=1; perseverance+=1;}
			else if (num == 3) { energy -= 3, EQ -= 1 ;}
		}
		else if (story_num == 79)
		{
			if (num == 1) { energy -= 3, SAN += 2, EQ += 2; story[story_num].max_scene = 5;}
			else if (num == 2) { energy -= 1, SAN += 1,wisdom+=2; }
			
		}
		else if (story_num == 80)
		{
			if (num == 1) { energy -= 3, wisdom += 2, EQ += 1 ;}
			else if (num == 2) { energy -= 5, EQ += 2, wisdom += 1; }
		}
		else if (story_num == 81)
		{
			if(story_scene == 1)
			{
				if (num == 1) { energy -= 4, SAN -= 1, EQ += 2 ;}
				else if (num == 2) { energy -= 5, SAN -= 1, EQ -= 1 ;}
				story[81].choice_scene = 4; story[81].choice = 2;
			}
			else if(story_scene == 4)
			{
				if (num == 1) { energy -= 2, SAN += 2, EQ += 2,wisdom+=1; }
				else if (num == 2) { energy -= 1, wisdom += 2, EQ += 1; }
			}
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
			if (num == 1) { energy -= 2, SAN+=7,EQ += 2; logic[8]=1;  for(int i=story_num+1;i<sum_story;i++){if(story_type(i)==6)story[i].state=1;} }
			else if (num == 2) { energy -= 2, SAN+=4,EQ += 2; }
		}
		else if (story_num == 89)
		{
			if (num == 1) { energy -= 5, SAN+=3,EQ += 2;story[92].state=1; }
			else if (num == 2) { energy -= 3, SAN-=1,EQ += 1;perseverance+=3; }
		}
		else if(story_num==90)
		{
			if(last_choice==1)
			{
				if(num==1){energy-=3;   for(int i=story_num+1;i<sum_story;i++){if(story_type(i)==7)story[i].state=1;}  }
				else if(num==2){energy-=1;}
			}
			else if(last_choice==2)
			{
				if(num==1){perseverance+=3;wisdom+=3;EQ+=1;energy-=3;logic[3]=1;   for(int i=story_num+1;i<sum_story;i++){if(story_type(i)==8)story[i].state=1;}  }
				else if(num==2){wisdom+=1;EQ+=1;energy-=1;logic[3]=2;}
			}
			story[story_num].choice_scene=2;
		}
		else if(story_num==91)
		{
			if(num==1){perseverance+=10; EQ+=3; wisdom+=8; logic[4]=1;   for(int i=story_num+1;i<sum_story;i++){if(story_type(i)==9)story[i].state=1;}  }
			else if(num==2){logic[4]=2;}
		}
		else if(story_num==92)
		{
			if(story_scene==1)
			{
				if(num==1){EQ+=1;energy-=1;wisdom+=2;cgl+=5;story[story_num].max_scene=3;}
				else if(num==2){EQ+=2;energy-=1;}
			}
		}
		else if(story_num==94)
		{
			if(num==1){energy-=3;}
			else if(num==2)
			{
				if(perseverance>=40){energy-=5;perseverance+=5;cgl+=5;}
				else{energy-=3;}
			}
		}
		else if(story_num==96)
		{
			if(story_scene==1)
			{
				if(num==1){EQ+=3;wisdom+=3;energy-=2;story[story_num].max_scene=3;}
			}
			else if(story_scene==4)
			{
				if(num==1){wisdom+=1;EQ+=3;SAN+=1;energy-=2;}
				else if(num==2){wisdom+=3;EQ+=1;energy-=1;}
			}
		}
		else if(story_num==98)
		{
			if(num==1){SAN-=7;EQ-=3;energy-=5;}
			else if(num==2){SAN+=4;energy-=6;EQ+=2;perseverance+=2;}
		}
		else if(story_num==99)
		{
			if(story_scene==2)
			{
				if(num==1){EQ+=2;wisdom+=1;SAN+=1;perseverance+=1;energy-=2;story[story_num].max_scene=3;story[story_num].choice_scene=3;}
				else if(num==2){wisdom+=2;EQ+=1;energy-=1;}
			}
			else if(story_scene==3)
			{
				if(num==1){wisdom+=2;EQ+=2;SAN+=1;perseverance+=4;energy-=5;logic[5]=1;   for(int i=story_num+1;i<sum_story;i++){if(story_type(i)==8)story[i].state=1;}  }
				else if(num==2){wisdom+=4;EQ+=1;energy-=1;logic[5]=2;}
			}
		}
		else if(story_num==100)
		{
			if(story_scene==2)
			{
				if(num==1){EQ+=1;wisdom+=1;story[story_num].choice=3;story[story_num].choice_scene=4;story[story_num].max_scene=4;}
				else if(num==2){EQ+=4;wisdom+=2;SAN+=1;}
			}
			else if(story_scene==3)
			{
				if(num==1){energy-=2;SAN+=3;EQ+=1;}
				else if(num==2){SAN+=1;energy-=2;EQ+=3;}
				else if(num==3){energy-=2;EQ+=3;SAN+=1;  logic[8]=0;  for(int i=story_num+1;i<sum_story;i++){if(story_type(i)==6)story[i].state=0;}  }
			}
		}
		else if(story_num==101)
		{
			if(num==1){SAN+=2;wisdom+=3;EQ+=3;energy-=4;perseverance+=3;}
			else if(num==2){SAN+=1;wisdom+=1;EQ+=3;energy-=2;perseverance+=1;}
		}
		else if(story_num==102)
		{
			if(story_scene==2)
			{
				if(num==1){EQ+=2;wisdom+=1;energy-=2;}
				else if(num==2){SAN+=1;energy-=1;}
				story[story_num].choice_scene = 5;
			}
			else if(story_scene==5)
			{
				if(num==1){EQ+=2;wisdom+=1;energy-=2; logic[6]=1;   for(int i=story_num+1;i<sum_story;i++){if(story_type(i)==8)story[i].state=1;}  }
				else if(num==2){EQ+=1;wisdom+=2;energy-=1; logic[6]=2;}
			}
		}
		else if(story_num==104)
		{
			if(num==1){EQ+=3;wisdom+=3;perseverance+=3;SAN+=3;energy-=4;logic[7]=1;}
			else if(num==2){EQ+=1;wisdom+=1;perseverance+=1;energy-=1;logic[7]=2;}
		}
		else if(story_num==105)
		{
			if(num==1){EQ-=4;perseverance+=3;SAN-=3;energy-=5;}
			else if(num==2){SAN+=1;EQ+=4;energy-=5;}
			else if(num==3){SAN-=5;EQ-=4;energy-=3;}
		}
		else if(story_num==106)
		{
			if(num==1){EQ+=2;wisdom+=1;perseverance+=2;energy-=2;}
			else if(num==2){EQ+=1;wisdom+=2;perseverance+=2;energy-=2;}
		}
		else if(story_num==107)
		{
			if(logic[7]==1)
			{
				if(wisdom>53,EQ>35){cgl+=15;SAN+=3;}
				else{cgl-=5;SAN-=6;}
			}
			else{cgl+=10;}
			if(num==1){EQ+=2;perseverance+=2;SAN+=2;cgl-=10;}
			else if(num==2){EQ+=5;perseverance+=2;SAN+=3;wisdom+=2;cgl+=5;}
			else if(num==3){EQ+=5;perseverance+=3;SAN+=3;wisdom+=4;cgl+=10;}
			else if(num==4){SAN-=1;EQ-=1;}
		}
		else if(story_num==108)
		{
			if(story_scene==1)
			{
				if(num==1){EQ+=1;perseverance+=1;SAN-=3;energy-=2;}
				else if(num==2){EQ+=2;SAN+=1;energy-=2;}
				story[story_num].choice=3;story[story_num].choice_scene=2;
			}
			else if(story_scene==2)
			{
				if(num==1){EQ+=1;perseverance+=2;SAN-=3;energy-=3;}
				else if(num==2){EQ+=2;perseverance+=2;energy-=2;}
				else if(num==3){EQ+=1;perseverance+=1;energy-=2;}
				story[story_num].choice=2;story[story_num].choice_scene=3;
			}
			else if(story_scene==3)
			{
				if(num==1){EQ+=1;SAN-=3;energy-=1;}
				else if(num==2){EQ+=1;SAN-=3;energy-=1;}
			}
		}
		else if(story_num==109)
		{
			if(num==1){EQ+=3;wisdom+=3;SAN-=8;energy-=7; logic[8]=0;  for(int i=story_num+1;i<sum_story;i++){if(story_type(i)==6)story[i].state=0;}  }
			else if(num==2){EQ+=5;SAN+=3;energy-=5;}
		}
		else if(story_num==113)
		{
			if(num==1){EQ+=3;wisdom+=3;perseverance+=3;SAN+=3;energy+=5;}
			else if(num==2){wisdom+=3;perseverance+=6;EQ+=2;energy-=10;}
			else if(num==3){EQ+=1;energy+=5;}
		}
		last_choice=num;
		if(energy<=40){energy=40;}
		if(energy>=energy_limit){energy=energy_limit;}
		if(cgl>100)cgl=100;
		if(story_scene<story[story_num].max_scene)story_scene++;
		else show[2]=true;
	}
}