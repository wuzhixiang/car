#include "开始.h"
#include "玩家系统.h"
#include "主程序.h"
#include <graphics.h> 
#include <conio.h>

void wordstyle( int height, int width, COLORREF a, bool b)
{
	settextstyle( height,width, _T("微软雅黑"), 0, 0, 0, b, false, false );
	setbkmode( TRANSPARENT );
	settextcolor( a );
}
void origin()
{
	IMAGE img;

	loadimage( &img, _T("res/1.jpg") );
	putimage( 0, 0, &img );
	setfillcolor( RGB( 0, 100, 250 ) );
	solidroundrect( 270, 325, 370, 375, 10, 10 );
	solidroundrect( 270, 400, 370, 450, 10, 10 );
	solidroundrect( 570, 10, 630, 40, 30, 10 );
	solidroundrect( 520, 420, 620, 460, 10, 10 );
	wordstyle( 30, 10, BLACK, false );
	outtextxy( 580, 13, _T("音乐") );
	outtextxy( 300, 337, _T("开始") );
	outtextxy( 280, 412, _T("游戏说明") );
	outtextxy( 550, 427, _T("离开") );
}
void explanation()
{
	IMAGE img;
	RECT r = {0, 0, 640, 480};

	loadimage( &img, _T("res/2.jpg") );
	putimage( 0, 0, &img );
	settextcolor( RED );
	drawtext( _T("这是一个赛车游戏，可选单人模式或双人模式，可自选难度以及是否再玩一盘，当某一方跑到300m或双方都撞毁时结束,以最后路程多者为胜"), &r,DT_WORDBREAK );
	drawtext( _T("\n\n玩家1：A代表往左,D代表往右，W代表加速，S代表减速,Q代表发射子弹\n玩家2（或电脑）：←代表往左,→代表往右，↑代表加速，↓代表减速，0代表发射子弹"), &r,DT_WORDBREAK );
	drawtext( _T("\n\n\n\n\n游戏中摁E关闭音乐,摁R打开音乐"), &r,DT_WORDBREAK );
	settextcolor( BLACK );
	solidroundrect( 520, 420, 620, 460, 10, 10 );
	outtextxy( 550, 427, _T("返回") );
}
void begin( bool& x, bool& exit )
{
	IMAGE img;
	MOUSEMSG m;
	mciSendString( _T("open res/q.mp3 alias music"), NULL, 0, NULL );

	while( true )
	{
		m=GetMouseMsg();
		if( x == true )
			mciSendString( _T("play music repeat"), NULL, 0, NULL );
		else
			mciSendString( _T("stop music"), NULL, 0, NULL );
		if( m.x>=570 && m.x<=630 && m.y>=10 && m.y<=40 )
			picture1( 239, 155, 160, 11 );
		else
			picture1( 0, 100, 250, 13  );
		if( m.x>=270 && m.x<=370 && m.y>=325 && m.y<=375 )
			picture2( 239, 155, 160, 335 ); 
		else
			picture2( 0, 100, 250, 337 );
		if( m.x>=270 && m.x<=370 && m.y>=420 && m.y<=460 )
			picture3( 239, 155, 160,410 );
		else
			picture3( 0, 100, 250,412 );
		if( m.x>=520 && m.x<=620 && m.y>=410 && m.y<=450 )
		{
			picture4( 239, 155, 160,425 );
			outtextxy( 550, 427, _T("离开") );
		}
		else
		{
			picture4( 0, 100, 250,427 );
			outtextxy( 550, 427, _T("离开") );
		}
		if( m.uMsg == WM_LBUTTONDOWN )
	    {
			if( m.x>=570 && m.x<=630 && m.y>=10 && m.y<=40 )
			{
				if( x == true )
					x=false;
				else
					x=true;	
			}
			if( m.x>=270 && m.x<=370 && m.y>=420 && m.y<=460 )
			{
				explanation();
				while( true )
				{
					m=GetMouseMsg();
					if( m.x>=520 && m.x<=620 && m.y>=410 && m.y<=450 )
					{
						picture4( 239, 155, 160,425 );
						outtextxy( 550, 427, _T("返回") );
					}
					else
					{
						picture4( 0, 100, 250,427 );
						outtextxy( 550, 427, _T("返回") );
					}
					if( m.uMsg == WM_LBUTTONDOWN )
	                {
						if( m.x>=520 && m.x<=620 && m.y>=410 && m.y<=450 )
						{
							break;
						}
					}	
				}
				origin();
				begin( x, exit );
				break;
			}
			if( m.x>=520 && m.x<=620 && m.y>=410 && m.y<=450 )
			{
				exit=false;
				break;
			}
		    if( m.x>=270 && m.x<=370 && m.y>=325 && m.y<=375 )
		    {
			    loadimage( &img, _T("res/3.jpg") );
			    putimage( 0, 0, &img );
				break;
		    }
		}
	}
}
void time()
{
	IMAGE img;

	cleardevice();
	RECT r = {0, 0, 640, 480};
	wordstyle( 60, 20, YELLOW, true );
	loadimage( &img, _T("res/4.jpg") );
	putimage( 0, 0, &img );
	drawtext( _T("THREE!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
	Sleep( 1000 );
	cleardevice();
	putimage( 0, 0, &img );
	drawtext( _T("TWO!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
	Sleep( 1000 );
	cleardevice();
	putimage( 0, 0, &img );
	drawtext( _T("ONE!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
	Sleep( 1000 );
	cleardevice();
	putimage( 0, 0, &img );
	drawtext( _T("LET'S GO!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
	Sleep( 1000 );
	cleardevice();
}
void picture1( int r, int g, int b, int x )
{
	setfillcolor( RGB( r, g, b ) );
	solidroundrect( 570, 10, 630, 40, 30, 10 );
	outtextxy( 580, x, _T("音乐") );
}
void picture2( int r, int g, int b, int x )
{
	setfillcolor( RGB( r, g, b ) );
	solidroundrect( 270, 325, 370, 375, 10, 10 );
	outtextxy( 300, x, _T("开始") );
}
void picture3( int r, int g, int b, int x )
{
	setfillcolor( RGB( r, g, b ) );
	solidroundrect( 270, 400, 370, 450, 10, 10 );
	outtextxy( 280, x, _T("游戏说明") );
}
void picture4( int r, int g, int b, int x )
{
	setfillcolor( RGB( r, g, b ) );
	solidroundrect( 520, 420, 620, 460, 10, 10);
}