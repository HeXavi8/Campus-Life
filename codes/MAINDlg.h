
// MAINDlg.h : 头文件
#pragma once
#include <mmsystem.h>
#pragma comment(lib,"load")
#pragma comment(lib,"sound")
#pragma comment(lib,"winmm.lib")

// CMAINDlg 对话框
class CMAINDlg : public CDialogEx
{
public:
	CMAINDlg(CWnd* pParent = NULL);	// 标准构造函数
	enum { IDD = IDD_MY_DIALOG };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
protected:
	int last_storage_num,setting_frame;

	CDC dc;
	CPoint mpt;
	HMODULE hMode1,hMode2;
	HICON m_hIcon;
	HFONT hf;
	HCURSOR	cursor_hand,cursor_redhand,cursor_goldlight;

	int window;
	int now_sound;
	TCHAR tmpwav[_MAX_PATH];
	TCHAR mcicmd[300];
	CRect re_bmp[500],re_position[20];
	
	int load_cap_num;

	int storage_type;

	int day; int energy,energy_limit;
	int SAN,wisdom,perseverance,EQ,moral;

	int story_num;  int story_scene;
	struct story_information{int day; int position; int max_scene; int state; int choice_scene; int choice; int bgm; int pic;}story[100]; //state 0-2
	bool show[200];
	int last_choice;
	static const int sum_story=88,sum_position=11;

	bool ismove;
	int mapx,mapy,downpointx,downpointy,downmapx,downmapy,positionx[20],positiony[20];
	int game_t11_enter,game_t11_gantan,game_t11_pic;

	void paint();
	void draw_bmp1(int flag,int px,int py,double k);
	void draw_bmp2(int x0,int y0,int w,int h,int r,int g,int b);
	void text1(const char*c,int w,int h,int we,int r,int g,int b,int x0,int y0,int x1,int y1,char*p);
	void InstallResourceFont(HINSTANCE hResInstance, LPCTSTR lpsFont, LPCTSTR lpsType);

	void get_data0();
	void give_data0();
	void get_data1(int num);
	void give_data1(int num);
	void ttf();

	void load_initialization(int x);
	void load_paint();
	void load_timer1();
	void load_cursor();
	void load_lb();
	bool ExtractResource(LPCTSTR strPosition, LPCTSTR strResType, LPCTSTR strResName);
	void init(int flag);
	void play1(int flag);
	void play2(int flag);

	void storage_initialization();
	void storage_paint();
	void storage_cursor();
	void storage_lb();

	void game_initialization(int x);
	void game_paint();
	void game_lb();
	void game_lbu();
	void game_mm();
	void game_timer1();
	void game_cursor();
	
	void first_play();
	void find_story();
	void load_story(int num);
	void end_story(int num);
	void deal_choice(int num);
	void story_information_initialization(int num);
	char* w1(char*c);
	void sound_control();
	int judge_pic(int x);

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};