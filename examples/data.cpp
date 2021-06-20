
//data.cpp
#include "stdafx.h"
#include "��ѧ����ô.h"
#include "MAINDlg.h"
#include <sys/stat.h>
#include <iostream>

void CMAINDlg::get_data1(int num)
{
	struct stat filestat;
	CString str_path; str_path.Format("data\\z%d.dat",num);
	if(stat(str_path,&filestat))
	{
		//�˴�ֻ��ʼ�����ݣ��ڱ���ʱ�Ŵ����ļ�
		first_play();
	}
	else{ //��z%d.dat����ȡ����
		CStdioFile file; CString str_content;
		file.Open(str_path,CFile::modeRead);  //modeRead�򿪵��ļ�ֻ�ܶ�ȡ
		file.ReadString(str_content);
		file.Close();
		char c; int k1=0,t1=0;
		for(int i=0;i<str_content.GetLength();i++)
		{
			c=str_content.GetAt(i);
			if(c!=' '){k1=k1*10+(c-48);}
			else
			{
				t1++;
				if(t1==1)day=k1;
				else if(t1==2)energy=k1;
				else if(t1==3)energy_limit=k1;
				else if(t1==4)SAN=k1;
				else if(t1==5)wisdom=k1;
				else if(t1==6)perseverance=k1;
				else if(t1==7)EQ=k1;
				else if(t1==8)moral=k1;
				else if(t1>=9&&t1<=158)story[t1-9].state=k1;
				else if(t1>=159&&t1<=178)logic[t1-159]=k1;
				else if(t1==179)cgl=k1;
				k1=0;
			}
		}
	}
}

void CMAINDlg::give_data1(int num)
{
	//���浵�Ƿ���ڣ������������´���
	struct stat filestat;     
	CString str_path1; str_path1.Format("data\\z%d.dat",num);
	if(stat(str_path1,&filestat))
	{
		CStdioFile file(str_path1,CFile::modeCreate); 
		file.Close(); 
	}
	
	//��ȡ��ǰ·��������z%d.dat·��
	char buf[512];  ::GetCurrentDirectory(512,buf);  
	CString str_path2;  str_path2.Format("%s\\data\\z%d.dat",buf,num);

	CString str_content1,str;
	str_content1.Format("%d %d %d %d %d %d %d %d ",day,energy,energy_limit,SAN,wisdom,perseverance,EQ,moral);
	for(int i=0;i<150;i++) //��0��149���¼���ֵ
	{
		str.Format("%d ",story[i].state);
		str_content1+=str;
	}
	for(int i=0;i<20;i++) //��0��19��logic��ֵ
	{
		str.Format("%d ",logic[i]);
		str_content1+=str;
	}
	str.Format("%d ",cgl);  str_content1+=str;
	CFile file2(_T(str_path2),CFile::modeCreate|CFile::modeWrite);
	file2.Write(str_content1,str_content1.GetLength());
	file2.Close();
}

void CMAINDlg::get_data0()
{
	//ttf();
	//��ȡ��ǰ·��������data·��
	char buf[512];  ::GetCurrentDirectory(512,buf);  
	CString name; name.Format("data"); strcat_s(buf,"\\"); strcat_s(buf,name);
	
	struct stat filestat;
	if(stat("data",&filestat)){CreateDirectory(buf,NULL);}  //����data�ļ���      

	CString str_path="data\\zzz.dat";
	if(stat(str_path,&filestat))  //�½�zzz.dat����ʼ�����ݲ�give_data0()
	{
		CStdioFile file(str_path,CFile::modeCreate);
		last_storage_num=0; setting_frame=3;
		file.Close();
		give_data0();
	}
	else{ //��zzz.dat����ȡ����
		CStdioFile file; CString str_content;
		file.Open(str_path,CFile::modeRead);  //modeRead�򿪵��ļ�ֻ�ܶ�ȡ
		file.ReadString(str_content);
		file.Close();
		char c; int k1=0,t1=0;
		for(int i=0;i<str_content.GetLength();i++)
		{
			c=str_content.GetAt(i);
			if(c!=' '){k1=k1*10+(c-48);}
			else
			{
				t1++;
				if(t1==1)last_storage_num=k1;
				else if(t1==2)setting_frame=k1;
				k1=0;
			}
		}
	}
}

void CMAINDlg::give_data0()
{
	//��ȡ��ǰ·��������zzz.dat·��
	char buf[512];  ::GetCurrentDirectory(512,buf);  
	CString str_path;  str_path.Format("%s\\data\\zzz.dat",buf);

	CString str_content1;
	str_content1.Format("%d %d ",last_storage_num,setting_frame);
	CFile file2(_T(str_path),CFile::modeCreate|CFile::modeWrite);
	file2.Write(str_content1,str_content1.GetLength());
	file2.Close();
}

void CMAINDlg::ttf()
{
	CString str1,str2;
	str1.Format("������������.ttf");
	str2.Format("C:\\\\Windows\\Fonts\\������������.ttf");
	CopyFile(str1,str2,true);
}