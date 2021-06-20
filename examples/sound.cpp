
//sound.cpp
#include "stdafx.h"
#include "大学轻松么.h"
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


bool CMAINDlg::ExtractResource(LPCTSTR strPosition, LPCTSTR strResType, LPCTSTR strResName)  //将资源提取为临时文件
{
    HANDLE hFile = ::CreateFile(strPosition, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);  // 创建文件
    if (hFile == INVALID_HANDLE_VALUE) return false;
    HRSRC hRes=::FindResource(hMode2,strResName, strResType);
    HGLOBAL hMem=::LoadResource(hMode2, hRes);
    DWORD dwSize=::SizeofResource(hMode2, hRes);
    DWORD dwWrite=0;
    ::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);  // 写入文件
    ::CloseHandle(hFile);
    return true;
}

void CMAINDlg::init(int flag) //初始化函数
{
    CString str; str.Format("~DXQSM%d.wav",flag);
	::GetTempPath(_MAX_PATH,tmpwav);  _tcscat_s(tmpwav, _T(str));   //在C:\Users\Administrator\AppData\Local\Temp产生临时文件
    ExtractResource(tmpwav, _T("WAVE"),MAKEINTRESOURCE(flag));  // 将wav资源提取为临时文件
    _stprintf_s(mcicmd, _T("open \"%s\" alias mymusic"),tmpwav);        // VC2008、VC2010 请用 _stprintf_s 函数
}

void CMAINDlg::play2(int flag)  //播放函数
{
	mciSendString(("stop mymusic"), NULL, 0, NULL);  //停止播放
	mciSendString(_T("close mymusic"), NULL, 0, NULL);
	DeleteFile(tmpwav);  // 删除临时文件
	init(flag);
	mciSendString(mcicmd, NULL,0, NULL);  // 打开音乐
	mciSendString(_T("play mymusic"), NULL, 0, NULL); // 播放音乐       
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

/*bool CSound::ExtractResource(LPCTSTR strPosition, LPCTSTR strResType, LPCTSTR strResName)  //将资源提取为临时文件
{
    HANDLE hFile = ::CreateFile(strPosition, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);  // 创建文件
    if (hFile == INVALID_HANDLE_VALUE) return false;

    HRSRC hRes=::FindResource(hMode2,strResName, strResType);
    HGLOBAL hMem=::LoadResource(hMode2, hRes);
    DWORD dwSize=::SizeofResource(hMode2, hRes);
    DWORD dwWrite=0;
    ::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);  // 写入文件
    ::CloseHandle(hFile);
    return true;
}

void CSound::init(int flag) //初始化函数
{
    TCHAR tmpwav[_MAX_PATH];  ::GetTempPath(_MAX_PATH,tmpwav);  _tcscat_s(tmpwav, _T("test.wav"));   //在C:\Users\Administrator\AppData\Local\Temp产生临时文件
    ExtractResource(tmpwav, _T("WAVE"),MAKEINTRESOURCE(flag));  // 将wav资源提取为临时文件
    _stprintf_s(mcicmd, _T("open \"%s\" alias mymusic"),tmpwav);        // VC2008、VC2010 请用 _stprintf_s 函数
    //mciSendString(mcicmd, NULL,0, NULL);  // 打开音乐
    //mciSendString(_T("play mymusic"), NULL, 0, NULL); // 播放音乐
    //mciSendString(("stop mymusic"), NULL, 0, NULL);  //停止播放
    //mciSendString(("close mymusic"), NULL, 0, NULL);  //关闭音乐
    //DeleteFile(tmpwav);  // 删除临时文件
}

void CSound::play(int flag)  //播放函数
{
    mciSendString(_T("close mymusic"), NULL, 0, NULL);
    mciSendString(mcicmd, NULL,0, NULL);
    mciSendString(_T("play mymusic"),NULL,0, NULL);        
}*/