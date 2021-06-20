
//sound.cpp
#include "stdafx.h"
#include "��ѧ����ô.h"
#include "MAINDlg.h"

void CMAINDlg::sound_control()
{
	int num=0;
	if(window==0||window==1)num=4015;
	else if(window==2)
	{
		if(show[11]||show[12]||show[21]){num=4015;}
		else if(show[0])
		{
			if(story[story_num].bgm)num=story[story_num].bgm;
			else num=4015;
		}
	}
	play1(num);
}

void CMAINDlg::play1(int flag)
{
	if(flag==0)PlaySound(NULL,hMode2,SND_PURGE);
	else{
		if(now_sound!=flag)PlaySound(NULL,hMode2,SND_PURGE);
		PlaySound((LPCTSTR)MAKEINTRESOURCE(flag),hMode2,SND_RESOURCE|SND_ASYNC|SND_LOOP|SND_NOSTOP|SND_NODEFAULT);
	}
	now_sound=flag;
}


bool CMAINDlg::ExtractResource(LPCTSTR strPosition, LPCTSTR strResType, LPCTSTR strResName)  //����Դ��ȡΪ��ʱ�ļ�
{
    HANDLE hFile = ::CreateFile(strPosition, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);  // �����ļ�
    if (hFile == INVALID_HANDLE_VALUE) return false;
    HRSRC hRes=::FindResource(hMode2,strResName, strResType);
    HGLOBAL hMem=::LoadResource(hMode2, hRes);
    DWORD dwSize=::SizeofResource(hMode2, hRes);
    DWORD dwWrite=0;
    ::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);  // д���ļ�
    ::CloseHandle(hFile);
    return true;
}

void CMAINDlg::init(int flag) //��ʼ������
{
    CString str; str.Format("~DXQSM%d.wav",flag);
	::GetTempPath(_MAX_PATH,tmpwav);  _tcscat_s(tmpwav, _T(str));   //��C:\Users\Administrator\AppData\Local\Temp������ʱ�ļ�
    ExtractResource(tmpwav, _T("WAVE"),MAKEINTRESOURCE(flag));  // ��wav��Դ��ȡΪ��ʱ�ļ�
    _stprintf_s(mcicmd, _T("open \"%s\" alias mymusic"),tmpwav);        // VC2008��VC2010 ���� _stprintf_s ����
}

void CMAINDlg::play2(int flag)  //���ź���
{
	mciSendString(("stop mymusic"), NULL, 0, NULL);  //ֹͣ����
	mciSendString(_T("close mymusic"), NULL, 0, NULL);
	DeleteFile(tmpwav);  // ɾ����ʱ�ļ�
	init(flag);
	mciSendString(mcicmd, NULL,0, NULL);  // ������
	mciSendString(_T("play mymusic"), NULL, 0, NULL); // ��������       
}

/*class CSound : public CMAINDlg
{
public:
	bool ExtractResource(LPCTSTR strPosition, LPCTSTR strResType, LPCTSTR strResName);
	void init(int flag);
	void play(int flag);
protected:
	TCHAR mcicmd[300];
};*/

/*bool CSound::ExtractResource(LPCTSTR strPosition, LPCTSTR strResType, LPCTSTR strResName)  //����Դ��ȡΪ��ʱ�ļ�
{
    HANDLE hFile = ::CreateFile(strPosition, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);  // �����ļ�
    if (hFile == INVALID_HANDLE_VALUE) return false;

    HRSRC hRes=::FindResource(hMode2,strResName, strResType);
    HGLOBAL hMem=::LoadResource(hMode2, hRes);
    DWORD dwSize=::SizeofResource(hMode2, hRes);
    DWORD dwWrite=0;
    ::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);  // д���ļ�
    ::CloseHandle(hFile);
    return true;
}

void CSound::init(int flag) //��ʼ������
{
    TCHAR tmpwav[_MAX_PATH];  ::GetTempPath(_MAX_PATH,tmpwav);  _tcscat_s(tmpwav, _T("test.wav"));   //��C:\Users\Administrator\AppData\Local\Temp������ʱ�ļ�
    ExtractResource(tmpwav, _T("WAVE"),MAKEINTRESOURCE(flag));  // ��wav��Դ��ȡΪ��ʱ�ļ�
    _stprintf_s(mcicmd, _T("open \"%s\" alias mymusic"),tmpwav);        // VC2008��VC2010 ���� _stprintf_s ����
    //mciSendString(mcicmd, NULL,0, NULL);  // ������
    //mciSendString(_T("play mymusic"), NULL, 0, NULL); // ��������
    //mciSendString(("stop mymusic"), NULL, 0, NULL);  //ֹͣ����
    //mciSendString(("close mymusic"), NULL, 0, NULL);  //�ر�����
    //DeleteFile(tmpwav);  // ɾ����ʱ�ļ�
}

void CSound::play(int flag)  //���ź���
{
    mciSendString(_T("close mymusic"), NULL, 0, NULL);
    mciSendString(mcicmd, NULL,0, NULL);
    mciSendString(_T("play mymusic"),NULL,0, NULL);        
}*/