#include<cstdlib>
#include<ctime>
#include "��ʼ.h"
#include "���ϵͳ.h"
#include "������.h"
#include "Vfw.h"
#include <graphics.h>
#include <conio.h>
#pragma comment( lib, "Winmm.lib" )
#pragma comment( lib, "Vfw32.lib" )

void TcharToChar( const TCHAR*, char*, int );

int main()
{
	initgraph( 640, 480, NOMINIMIZE );
	TCHAR name1[25];//�洢���1����
	TCHAR again[25];//�洢�Ƿ�Ҫ�������ѶϢ
	TCHAR hard[25];//�洢���׶�
	TCHAR answer[25];//�洢��սѡ����Ϣ
	char answer1[1];//ת����
	char again1[1];
	char hard1[2];
	int counter=0;//����·�̼�ʱ��
	int hardint;//ת���Ѷ���
	int x1=160;//���1�ĳ��ĺ�����
	int x2=480;//���2�ĳ��ĺ�����
	int subx1=x1;//�ж�����Ƿ���һ���ط�ͣ��
	int subx2=x2;
	int place1=0;//���ڸ���������
	int place2=0;
	int randx1[100][2];//�洢���1�������ϰ���Ϣ
	int randx2[100][2];//�洢���2�������ϰ���Ϣ
	int bullet1[20][2];//�洢�ӵ���Ϣ
	int bullet2[20][2];
	int supplyx1[1][2];//�洢������Ϣ
	int supplyx2[1][2];
	bool renx=true;//�ж��˻�or����
	bool ma=true;//�ж�ai�ƶ�����
	bool x=true;//�жϰ����Ƿ�仯
	bool exit=true;//�ж��Ƿ�Ҫ�뿪
	bool decidex1=true;//�ж����1�Ƿ������Ϸ
	bool decidex2=true;//�ж����2�Ƿ������Ϸ
	IMAGE img;
	IMAGE img1;
	IMAGE img2;
	IMAGE img3;
	IMAGE img4;
	IMAGE img5;

	loadimage( &img, _T("res/obstacle.jpg") );
	loadimage( &img1, _T("res/thanks.jpg") );
	loadimage( &img2, _T("res/bg.jpg") );
	loadimage( &img3, _T("res/cry.jpg") );
	loadimage( &img4, _T("res/bullet.jpg") );
	loadimage( &img5, _T("res/supply.jpg") );
	mciSendString( _T("open res/bg.mp3 alias mymusic"), NULL, 0, NULL );
	srand( time(0) );
	HWND hwnd = MCIWndCreate( GetHWnd(), NULL,WS_CHILD|WS_VISIBLE|MCIWNDF_NOMENU|MCIWNDF_NOPLAYBAR, NULL);
	SetWindowPos( hwnd, HWND_TOP, 0, 0, 0, 0, SWP_SHOWWINDOW );
	MCIWndOpen( hwnd, _T("res/0.wmv"), NULL ); 
	MCIWndPlay( hwnd );
	for( int cnt=0;cnt<13;cnt++ )
	{
		if( _kbhit() )
			break;
		Sleep(1000);
	}
	MCIWndStop( hwnd );
	MCIWndClose( hwnd );
	origin();//��ʼ����
	begin( x, exit );//��ʼ�����������
	setlinecolor( BLACK );
	if( exit == false )
		mciSendString( _T("stop music"), NULL, 0, NULL );
	for( int j=0;exit != false;j++ )
	{
		TCHAR name2[25]={ _T('��'), _T('��') };
		InputBox( answer, 20, _T("���˶�ս( y or n )"), _T("���˶�սor�˻���ս"), _T("y"), 0, 0, true );
		for( ;; )
		{
			TcharToChar( answer, answer1, 2 );
			if( ( answer1[0] != 'n' && answer1[0] != 'y' ) || ( answer1[1] != NULL ) )
				InputBox( answer, 20, _T("���˶�ս( y or n )"), _T("��������ȷ����Ϣ"), _T("y"), 0, 0, true );
			else
				break;
		}
		if( answer1[0] == 'n' )
			renx=false;
		InputBox( name1, 20, _T("���������1����"), _T("ע��"), _T("�ο�1"), 0, 0, true );
		if( renx == true )
			InputBox( name2, 20, _T("���������2����"), _T("ע��"), _T("�ο�2"), 0, 0, true );
		InputBox( hard, 20, _T("�������Ѷȣ�1-30)"), _T("���׳̶�"), _T("1"), 0, 0, true );
		for( ;; )
		{
			TcharToChar( hard, hard1, 3 );
			hardint=atoi( hard1 );
			if( hardint<1 || hardint>30 )
			{
				InputBox( hard, 20, _T("�������Ѷȣ�1-30)"), _T("��������ȷ����Ϣ"), _T("1"), 0, 0, true );
			}
			else
				break;
		}
		if( x == true )
		{
			mciSendString( _T("stop music"), NULL, 0, NULL );
			mciSendString( _T("play mymusic repeat"), NULL, 0, NULL );
		}
		time();
		Player player1( name1 );
		Player player2( name2 );
		for( int k=0;k<100;k++ )
		{
			randx1[k][0]=-1;
			randx1[k][1]=-1;
			randx2[k][0]=-1;
			randx2[k][1]=-1;
		}
		for( int k=0;k<20;k++ )
		{
			bullet1[k][0]=-1;
			bullet1[k][1]=600;
			bullet2[k][0]=-1;
			bullet2[k][1]=600;
		}
		supplyx1[0][0]=-1;
		supplyx1[0][1]=-1;
		supplyx2[0][0]=-1;
		supplyx2[0][1]=-1;
		if( j>=1 )//Ϊ�ڶ�����Ϸ������У���׼��
		{
			player1.setspeed();
			player1.setmile();
			player1.setbulletnumber();
			player2.setspeed();
			player2.setmile();
			player2.setbulletnumber();
			decidex1=true;
			decidex2=true;
			x1=160;
			x2=480;
		}
		BeginBatchDraw();
		for( int i=0;;i++ )
		{
			if( decidex1 == true )
			{
				putimage( 0, place1%480-480, &img2 );
				putimage( 0, place1%480, &img2 );
				place1+=player1.getspeed();
				loadcar( x1 );
			}
			else
				putimage( 0, 0, &img3 );
			if( decidex2 == true )
			{
				putimage( 321, place2%480-480, &img2 );
				putimage( 321, place2%480, &img2 );
				place2+=player2.getspeed();
				loadcar( x2 );
			}
			else
				putimage( 320, 0, &img3 );
			line( 320, 0, 320, 480 );
			obstacle( randx1, randx2, player1, player2, img, decidex1, decidex2, hardint );//�����ϰ���
			supply( supplyx1, decidex1, img5, 0, player1 );
			supply( supplyx2, decidex2, img5, 1, player2 );
			if( GetAsyncKeyState('E') )
					x=false;
			if( GetAsyncKeyState('R') )
					x=true;
			if( x == true )
				mciSendString( _T("play mymusic repeat"), NULL, 0, NULL );
			else
				mciSendString( _T("stop mymusic"), NULL, 0, NULL );
			if( counter%50 == 0 )
			{
				prevent( randx1, img, decidex1, player1, counter, subx1, x1 );
				prevent( randx2, img, decidex2, player2, counter, subx2, x2 );
				subx1=x1;
				subx2=x2;
			}
			if( counter%10 == 0 )
			{
				if( GetAsyncKeyState('Q') && player1.getbulletnumber() != 0 )
					launch( bullet1, x1, player1, img4 );
				if( GetAsyncKeyState('0') && player2.getbulletnumber() != 0 && renx == true )
					launch( bullet2, x2, player2, img4 );
			}
			bulletattack( bullet1, randx1, decidex1, img4 );
			bulletattack( bullet2, randx2, decidex2, img4 );
			getsupply( x1, supplyx1, decidex1, img5, player1 );
			getsupply( x2, supplyx2, decidex2, img5, player2 );
			decide( player1, player2, x1, x2, decidex1, decidex2, renx );//�����Ӽ��١������ƶ�
			if( renx == false && decidex2 == true )
				ai( randx2, player2, x2, renx, ma, bullet2, img4 );
			player1.output( decidex1, 0 );//��������Ϣ
			player2.output( decidex2, 1 );
			lose( randx1, randx2, x1, x2, decidex1, decidex2 );//�ж��Ƿ�������޷�������Ϸ
			if( ( player1.getmile()>=300 ) || ( player2.getmile()>=300 ) )//�ж��Ƿ�������Ѿ������Ϸ
			{
				decidex1=false;
				decidex2=false;
			}
			if( decidex1 == false  &&  decidex2 == false )//�ж��Ƿ����
			{
				if( player1.getmile()>player2.getmile() )
				{
					player1.outputname();
					outtextxy( 340, 40, _T("wins.") );
				}
				if( player1.getmile()<player2.getmile() )
				{
					player2.outputname();
					outtextxy( 340, 40, _T(" wins.") );
				}
				if( player1.getmile() == player2.getmile() )
				{
					outtextxy( 290, 40, _T("No one wins") );
				}
				break;
			}
			if( counter%100 == 0 )//�ж��Ƿ�����·��
			{
				if( decidex1 == true )
					player1.changemile();
				if( decidex2 == true )
					player2.changemile();
			}
			FlushBatchDraw();
			Sleep( 10 );
			cleardevice();
			counter++;
		}
		EndBatchDraw();
		mciSendString( _T("stop mymusic"), NULL, 0, NULL );
		InputBox( again, 20, _T("��Ҫ����һ��ô( y or n )"), _T("again"), _T("y"), 0, 0, true );
		for( ;; )
		{
			TcharToChar( again, again1, 2 );
			if( ( again1[0] != 'n' && again1[0] != 'y' ) || ( again1[1] != NULL ) )
				InputBox( again, 20, _T("��Ҫ����һ��ô( y or n )"), _T("��������ȷ����Ϣ"), _T("y"), 0, 0, true );
			else
				break;
		}
		if( again1[0] == 'n' )
			break;
		else
			renx=true;
	}
	mciSendString( _T("close mymusic"), NULL, 0, NULL );
	putimage( 0, 0, &img1 );
	wordstyle( 30, 10, BLACK, false );
	outtextxy( 0, 0, _T("Thanks for use.") );
	system ("pause");
}
void TcharToChar ( const TCHAR* tchar, char* _char, int x )   
{
	int cnt=0;
	for( ;cnt<x;cnt++ )
	{
		int iLength;
		iLength =WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);   
		WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL); 
		tchar++;
		_char++;
	}
}