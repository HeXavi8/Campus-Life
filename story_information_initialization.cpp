
//story_information_initialization.cpp
#include "stdafx.h"
#include "大学轻松么.h"
#include "MAINDlg.h"

void CMAINDlg::story_information_initialization(int num) //num=-1表示单击开始游戏后的初始化，否则为游戏过程中重置第num个剧情
{
	if(num==-1)
	{
		if(setting_frame==3)
		{
			positionx[1]=1730;  positiony[1]=1230;
			positionx[2]=1080;  positiony[2]=1630;
			positionx[9]=860;   positiony[9]=1300;
			positionx[4]=1760;  positiony[4]=600;
			positionx[5]=550;   positiony[5]=830;
			positionx[6]=950;   positiony[6]=755;
			positionx[7]=1435;  positiony[7]=720;
			positionx[8]=1120;  positiony[8]=540;
			positionx[3]=850;   positiony[3]=1000;
			positionx[10]=1100; positiony[10]=820;
			positionx[11]=800;  positiony[11]=1550;
		}
		else if(setting_frame==2)
		{
			positionx[1]=720;  positiony[1]=700;
			positionx[2]=600;  positiony[2]=520;
			positionx[9]=290;   positiony[9]=250;
			positionx[4]=1330;  positiony[4]=610;
			positionx[5]=795;   positiony[5]=315;
			positionx[6]=345;   positiony[6]=560;
			positionx[7]=1335;  positiony[7]=390;
			positionx[8]=930;  positiony[8]=325;
			positionx[3]=485;   positiony[3]=365;
			positionx[10]=870;   positiony[10]=545;
			positionx[11]=530;   positiony[11]=700;
		}
	}
	for(int i=0;i<sum_story;i++)   //暂时剧情数
	{
		if(num!=-1&&i!=num)continue;
		//地点 1-教室 2-图书馆 3-一饭 4-校医院 5-C5宿舍 6-校道 7-二饭摆摊 8-C10面试地点  9-天桥 10-生活区操场 11-音乐厅
		if(i==0){story[i].day=1001;  story[i].position=0;  story[i].max_scene=5;  story[i].choice_scene=0; story[i].choice=0;  story[i].bgm=4015;}
		else if(i==1){story[i].day=1001;  story[i].position=1;  story[i].max_scene=8;  story[i].choice_scene=7; story[i].choice=2;  story[i].bgm=4014;}
		else if(i==2){story[i].day=1001;  story[i].position=2;  story[i].max_scene=7;  story[i].choice_scene=6; story[i].choice=5;  story[i].bgm=4014;}
		else if(i==3){story[i].day=1001;  story[i].position=9;  story[i].max_scene=5;  story[i].choice_scene=4; story[i].choice=2;  story[i].bgm=4005;}
		else if(i==4){story[i].day=1001;  story[i].position=4;  story[i].max_scene=10;  story[i].choice_scene=0; story[i].choice=0;  story[i].bgm=4020;}
		else if(i==5){story[i].day=1001;  story[i].position=5;  story[i].max_scene=8;  story[i].choice_scene=7; story[i].choice=2;  story[i].bgm=4021;}
		else if(i==6){story[i].day=1001;  story[i].position=2;  story[i].max_scene=6;  story[i].choice_scene=6; story[i].choice=4;   story[i].bgm=4014;}

		else if(i==7){story[i].day=1002;  story[i].position=0;  story[i].max_scene=6;  story[i].choice_scene=0; story[i].choice=0;  story[i].bgm=4020;}
		else if(i==8){story[i].day=1002;  story[i].position=6;  story[i].max_scene=3;  story[i].choice_scene=3; story[i].choice=2;  story[i].bgm=4010;}
		else if(i==9){story[i].day=1002;  story[i].position=7;  story[i].max_scene=3;  story[i].choice_scene=3; story[i].choice=2;  story[i].bgm=4012;}
		else if(i==10){story[i].day=1002;  story[i].position=5;  story[i].max_scene=5;  story[i].choice_scene=4; story[i].choice=2;  story[i].bgm=4015;}
		else if(i==11){story[i].day=1002;  story[i].position=8;  story[i].max_scene=8;  story[i].choice_scene=4; story[i].choice=3;  story[i].bgm=4012;}
		else if(i==12){story[i].day=1002;  story[i].position=1;  story[i].max_scene=2;  story[i].choice_scene=2; story[i].choice=2;  story[i].bgm=4012;}

		else if(i==13){story[i].day=1003;  story[i].position=0;  story[i].max_scene=2;  story[i].choice_scene=2; story[i].choice=2;  story[i].bgm=4009;}
		else if(i==14){story[i].day=1003;  story[i].position=5;  story[i].max_scene=2;  story[i].choice_scene=2; story[i].choice=3;  story[i].bgm=4009;}

		else if(i==15){story[i].day=1004;  story[i].position=0;  story[i].max_scene=2;  story[i].choice_scene=2; story[i].choice=2;  story[i].bgm=4019;}
		else if(i==16){story[i].day=1004;  story[i].position=7;  story[i].max_scene=1;  story[i].choice_scene=1; story[i].choice=2;  story[i].bgm=4009;}
		else if(i==17){story[i].day=1004;  story[i].position=8;  story[i].max_scene=5;  story[i].choice_scene=2; story[i].choice=2;  story[i].bgm=4012;}
		else if(i==18){story[i].day=1004;  story[i].position=11;  story[i].max_scene=2;  story[i].choice_scene=2; story[i].choice=3;  story[i].bgm=4019;}
		else if(i==19){story[i].day=1004;  story[i].position=10; story[i].max_scene=1;  story[i].choice_scene=0; story[i].choice=0;  story[i].bgm=4029;}

		else if(i==20){story[i].day=1005;  story[i].position=5;  story[i].max_scene=3;  story[i].choice_scene=3; story[i].choice=2;  story[i].bgm=4024;}
		else if(i==21){story[i].day=1005;  story[i].position=5;  story[i].max_scene=2;  story[i].choice_scene=2; story[i].choice=2;  story[i].bgm=4005;}
		else if(i==22){story[i].day=1005;  story[i].position=6;  story[i].max_scene=5;  story[i].choice_scene=5; story[i].choice=2;  story[i].bgm=4015;}
		else if(i==23){story[i].day=1005;  story[i].position=11; story[i].max_scene=3; story[i].choice_scene=3; story[i].choice=2;  story[i].bgm=4009;}

		else if (i == 24) { story[i].day = 1006;  story[i].position = 6; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4019; }
		else if (i == 25) { story[i].day = 1006;  story[i].position = 11; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 3;  story[i].bgm = 4009;}
		else if (i == 26) { story[i].day = 1006;  story[i].position = 1; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0;  story[i].bgm = 4007;}
		else if (i == 27) { story[i].day = 1006;  story[i].position = 7; story[i].max_scene = 3; story[i].choice_scene = 3; story[i].choice = 2;  story[i].bgm = 4023;}

		else if (i == 28) { story[i].day = 1007;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 3;  story[i].bgm = 4006; }
		else if (i == 29) { story[i].day = 1007;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2;  story[i].bgm = 4009; }
		else if (i == 30) { story[i].day = 1007;  story[i].position = 6; story[i].max_scene = 3; story[i].choice_scene = 3; story[i].choice = 2;  story[i].bgm = 4006; }
		else if (i == 31) { story[i].day = 1007;  story[i].position = 1; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 3;  story[i].bgm = 4019; }
		else if (i == 32) { story[i].day = 1007;  story[i].position = 11; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2;  story[i].bgm = 4006;}
		else if (i == 33) { story[i].day = 1007;  story[i].position = 8; story[i].max_scene = 3; story[i].choice_scene = 0; story[i].choice = 0;  story[i].bgm = 4015; }

		else if (i == 34) { story[i].day = 1008;  story[i].position = 9; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 3;  story[i].bgm = 4006; }
		else if (i == 35) { story[i].day = 1008;  story[i].position = 6; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2;  story[i].bgm = 4015; }
		else if (i == 36) { story[i].day = 1008;  story[i].position = 11; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4019; }

		else if (i == 37) { story[i].day = 1009;  story[i].position = 10; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 3;  story[i].bgm = 4019; }
		else if (i == 38) { story[i].day = 1009;  story[i].position = 11; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2;  story[i].bgm = 4009; }
		else if (i == 39) { story[i].day = 1009;  story[i].position = 11; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2;  story[i].bgm = 4006; }

		else if (i == 40) { story[i].day = 1010;  story[i].position = 8; story[i].max_scene = 3; story[i].choice_scene = 3; story[i].choice = 2; story[i].bgm = 4022; }
		else if (i == 41) { story[i].day = 1010;  story[i].position = 8; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4006; }
		else if (i == 42) { story[i].day = 1010;  story[i].position = 1; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4019; }

		else if (i == 43) { story[i].day = 1011;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 3; story[i].bgm = 4009; }
		else if (i == 44) { story[i].day = 1011;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 3; story[i].bgm = 4022; }
		else if (i == 45) { story[i].day = 1011;  story[i].position = 6; story[i].max_scene = 2; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4022; }

		else if (i == 46) { story[i].day = 1012;  story[i].position = 5; story[i].max_scene = 3; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4022; }
		else if (i == 47) { story[i].day = 1012;  story[i].position = 6; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4008; }
		else if (i == 48) { story[i].day = 1012;  story[i].position = 1; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4012; }
		//大二
		else if (i == 49) { story[i].day = 1013;  story[i].position = 0; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4014; }
		else if (i == 50) { story[i].day = 1013;  story[i].position = 6; story[i].max_scene = 3; story[i].choice_scene = 3; story[i].choice = 2; story[i].bgm = 4035; }
		else if (i == 51) { story[i].day = 1013;  story[i].position = 3; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4030; }
		else if (i == 52) { story[i].day = 1013;  story[i].position = 1; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4039; }
		else if (i == 53) { story[i].day = 1013;  story[i].position = 6; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4035; }
		else if (i == 54) { story[i].day = 1013;  story[i].position = 6; story[i].max_scene = 2; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4039; }
		else if (i == 55) { story[i].day = 1013;  story[i].position = 8; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4009; }

		else if (i == 56) { story[i].day = 1014;  story[i].position = 1; story[i].max_scene = 3; story[i].choice_scene = 3; story[i].choice = 2; story[i].bgm = 4037; }
		else if (i == 57) { story[i].day = 1014;  story[i].position = 6; story[i].max_scene = 4; story[i].choice_scene = 3; story[i].choice = 2; story[i].bgm = 4040; }
		else if (i == 58) { story[i].day = 1014;  story[i].position = 8; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4038; }
		else if (i == 59) { story[i].day = 1014;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4006; }
		else if (i == 60) { story[i].day = 1014;  story[i].position = 2; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4026; }
		else if (i == 61) { story[i].day = 1014;  story[i].position = 7; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4006; }

		else if (i == 62) { story[i].day = 1015;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4037; }
		else if (i == 63) { story[i].day = 1015;  story[i].position = 6; story[i].max_scene = 5; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4032; }
		else if (i == 64) { story[i].day = 1015;  story[i].position = 8; story[i].max_scene = 4; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4023; }
		else if (i == 65) { story[i].day = 1015;  story[i].position = 1; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4039; }

		else if (i == 66) { story[i].day = 1016;  story[i].position = 2; story[i].max_scene = 4; story[i].choice_scene = 3; story[i].choice = 2; story[i].bgm = 4033; }
		else if (i == 67) { story[i].day = 1016;  story[i].position = 8; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 4; story[i].bgm = 4039; }

		else if (i == 68) { story[i].day = 1017;  story[i].position = 6; story[i].max_scene = 6; story[i].choice_scene = 6; story[i].choice = 2; story[i].bgm = 4034; }
		else if (i == 69) { story[i].day = 1017;  story[i].position = 8; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4039; }
		else if (i == 70) { story[i].day = 1017;  story[i].position = 5; story[i].max_scene = 4; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4009; }

		else if (i == 71) { story[i].day = 1018;  story[i].position = 1; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4015; }
		else if (i == 72) { story[i].day = 1018;  story[i].position = 6; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4023; }
		else if (i == 73) { story[i].day = 1018;  story[i].position = 8; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4006; }
		else if (i == 74) { story[i].day = 1018;  story[i].position = 5; story[i].max_scene = 6; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4014; }

		else if (i == 75) { story[i].day = 1019;  story[i].position = 11; story[i].max_scene = 3; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4036; }
		else if (i == 76) { story[i].day = 1019;  story[i].position = 1; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4015; }
		else if (i == 77) { story[i].day = 1019;  story[i].position = 8; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4039; }

		else if (i == 78) { story[i].day = 1020;  story[i].position = 5; story[i].max_scene = 5; story[i].choice_scene = 4; story[i].choice = 3; story[i].bgm = 4027; }
		else if (i == 79) { story[i].day = 1020;  story[i].position = 10; story[i].max_scene = 1; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4031; }
		else if (i == 80) { story[i].day = 1020;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4014; }

		else if (i == 81) { story[i].day = 1021;  story[i].position = 6; story[i].max_scene = 4; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4028; }
		else if (i == 82) { story[i].day = 1021;  story[i].position = 6; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 5; story[i].bgm = 4039; }
		else if (i == 83) { story[i].day = 1021;  story[i].position = 1; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4028; }

		else if (i == 84) { story[i].day = 1022;  story[i].position = 6; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4025; }
		else if (i == 85) { story[i].day = 1022;  story[i].position = 6; story[i].max_scene = 1; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4025; }
		else if (i == 86) { story[i].day = 1022;  story[i].position = 1; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4014; }
		else if (i == 87) { story[i].day = 1022;  story[i].position = 6; story[i].max_scene = 3; story[i].choice_scene = 3; story[i].choice = 2; story[i].bgm = 4029; }
		//大三
		else if (i == 88) { story[i].day = 1023;  story[i].position = 1; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4050;}
		else if (i == 89) { story[i].day = 1023;  story[i].position = 6; story[i].max_scene = 3; story[i].choice_scene = 3; story[i].choice = 2; story[i].bgm = 4050;}
		else if (i == 90) { story[i].day = 1023;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4050;}
		else if (i == 91) { story[i].day = 1023;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4050;}
		
		else if (i == 92) { story[i].day = 1024;  story[i].position = 5; story[i].max_scene = 3; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4048;}
		else if (i == 93) { story[i].day = 1024;  story[i].position = 8; story[i].max_scene = 2; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4060;}

		else if (i == 94) { story[i].day = 1025;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4060;}
		else if (i == 95) { story[i].day = 1025;  story[i].position = 2; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4056;}
		
		else if (i == 96) { story[i].day = 1026;  story[i].position = 8; story[i].max_scene = 1; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4054;}
		else if (i == 97) { story[i].day = 1026;  story[i].position = 8; story[i].max_scene = 2; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4054;}
		else if (i == 98) { story[i].day = 1026;  story[i].position = 2; story[i].max_scene = 5; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4053;}

		else if (i == 99) { story[i].day = 1027;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4050;}
		else if (i == 100) { story[i].day = 1027;  story[i].position = 5; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4061;}

		else if (i == 101) { story[i].day = 1028;  story[i].position = 5; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4052;}
		else if (i == 102) { story[i].day = 1028;  story[i].position = 3; story[i].max_scene = 5; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4052;}
		else if (i == 103) { story[i].day = 1028;  story[i].position = 2; story[i].max_scene = 4; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4057;}
		
		else if (i == 104) { story[i].day = 1029;  story[i].position = 6; story[i].max_scene = 2; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4051;}
		else if (i == 105) { story[i].day = 1029;  story[i].position = 5; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 3; story[i].bgm = 4053;}
		else if (i == 106) { story[i].day = 1029;  story[i].position = 5; story[i].max_scene = 1; story[i].choice_scene = 1; story[i].choice = 3; story[i].bgm = 4053;}

		else if (i == 107) { story[i].day = 1030;  story[i].position = 1; story[i].max_scene = 5; story[i].choice_scene = 4; story[i].choice = 4; story[i].bgm = 4046;}

		else if (i == 108) { story[i].day = 1031;  story[i].position = 8; story[i].max_scene = 3; story[i].choice_scene = 1; story[i].choice = 2; story[i].bgm = 4046;}
		else if (i == 109) { story[i].day = 1031;  story[i].position = 6; story[i].max_scene = 4; story[i].choice_scene = 2; story[i].choice = 2; story[i].bgm = 4042;}

		else if (i == 110) { story[i].day = 1032;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4046;}
		else if (i == 111) { story[i].day = 1032;  story[i].position = 1; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4046;}
		
		else if (i == 112) { story[i].day = 1033;  story[i].position = 5; story[i].max_scene = 2; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4058;}
		else if (i == 113) { story[i].day = 1033;  story[i].position = 5; story[i].max_scene = 3; story[i].choice_scene = 2; story[i].choice = 3; story[i].bgm = 4058;}
		else if (i == 114) { story[i].day = 1033;  story[i].position = 5; story[i].max_scene = 1; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4058;}
		
		else if (i == 115) { story[i].day = 1034;  story[i].position = 10; story[i].max_scene = 3; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4047;}
		else if (i == 116) { story[i].day = 1034;  story[i].position = 11; story[i].max_scene = 5; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4041;}

		else if (i == 117) { story[i].day = 1035;  story[i].position = 6; story[i].max_scene = 2; story[i].choice_scene = 0; story[i].choice = 0; story[i].bgm = 4049;}


		if(i==0)story[i].pic=6121;
		else if(i==66||i==74||i==75||i==79||i==87)story[i].pic=6133;  //情窦初开剧情
		else if(story[i].position==3||story[i].position==6||story[i].position==7||story[i].position==8||story[i].position==9||story[i].position==11)story[i].pic=6122;
		else if(story[i].position==1)story[i].pic=6124;
		else if(story[i].position==5)story[i].pic=6126;
		else if(story[i].position==2)story[i].pic=6130;
		else if(story[i].position==4)story[i].pic=6131;
		else if(story[i].position==10)story[i].pic=6132;
		else story[i].pic=6122;
	}
}

int CMAINDlg::judge_pic(int x)
{
	if(x==6122||x==6124)return x+game_t11_pic/15;
	else if(x==6127)return x+game_t11_pic/10;
	else return x;
}