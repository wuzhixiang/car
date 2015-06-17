#include "开始.h"
#include "玩家系统.h"
#include "主程序.h"
#include <graphics.h> 
#include <conio.h>

void decide( Player& player1, Player& player2, int& x1, int& x2, const bool decidex1, const bool decidex2, const bool renx )
{
	if( decidex1 == true )
	{
		if( GetAsyncKeyState('W') ) 
			player1.addspeed();
		if( GetAsyncKeyState('S') )  
			player1.subtractspeed();
		if( GetAsyncKeyState('A') ) 
		{
			if( x1>0 && x1<=296 )
				x1-=2;
		}
		if( GetAsyncKeyState('D') ) 
		{
			if( x1>=0 && x1<296 )
				x1+=2;
		}
	}
	if( decidex2 == true && renx == true )
	{
		if( GetAsyncKeyState(VK_UP) )
			player2.addspeed();
		if( GetAsyncKeyState(VK_DOWN) )  
			player2.subtractspeed();
		if( GetAsyncKeyState(VK_LEFT) ) 
		{
			if( x2>320 && x2<=616 )
				x2-=2;
		}
		if( GetAsyncKeyState(VK_RIGHT) ) 
		{
			if( x2>=320 && x2<616 )
				x2+=2;
		}
	}
}
void loadcar( int x )
{
	IMAGE img;

	loadimage( &img, _T("res/car.jpg"));
	putimage( x, 420, &img );
}
void launch( int bullet[5][2], int x, Player& player, IMAGE img )
{
	for( int i=0;i<20;i++ )
	{
		if( bullet[i][1] == 600 || bullet[i][1]<-36 )
		{
			bullet[i][0]=x+9;
			bullet[i][1]=384;
			player.changebulletnumber();
			putimage( bullet[i][0], bullet[i][1], &img );
			break;
		}
	}
}
void bulletattack( int bullet[][2], int randx[][2], const bool decidex, IMAGE img )
{
	if( decidex == true )
	{
		for( int x=0;x<20;x++ )
		{
			if( bullet[x][1]<=384 && bullet[x][1]>=-36 )
			{
				bullet[x][1]-=3;
				putimage( bullet[x][0], bullet[x][1], &img );
			}
		}
		for( int x=0;x<100;x++ )
		{
			for( int i=0;i<20;i++ )
			{
				if( randx[x][1]>=0 && randx[x][1]<=480 && randx[x][0]<bullet[i][0]+5 && randx[x][0]>bullet[i][0]-40 && bullet[i][1]<randx[x][1]+40 )
				{
					randx[x][1]=481;
					bullet[i][1]=600;
				}
			}
		}
	}
}
void obstacle( int randx1[][2], int randx2[][2], Player player1, Player player2, IMAGE img, const bool decidex1, const bool decidex2, int hardint )
{
	int cnt1=0;
	int	cnt2=0;
	
	for( int x=0;x<100;x++ )
	{
		if( decidex1 == true )
		{
			if( randx1[x][1]>=0 && randx1[x][1]<=480 )
			{
				randx1[x][1]+=player1.getspeed();
				putimage( randx1[x][0], randx1[x][1], &img );
			}
		}
		if( decidex2 == true )
		{
			if( randx2[x][1]>=0 && randx2[x][1]<=480 )
			{
				randx2[x][1]+=player2.getspeed();
				putimage( randx2[x][0], randx2[x][1], &img );
			}
		}
	}
	if( rand()%( 45-hardint ) == 0 )
	{
		int x=rand()%2;

		switch( x )
		{
		case 0:
			if( rand()%( 3-( player1.getmile() )/100 ) == 0 )
			{
				if( ( player1.getspeed() != 0 ) && ( decidex1 == true ) )
				{
					for( ;cnt1<100;cnt1++ )
					{
						if( randx1[cnt1][1]<=0 || randx1[cnt1][1]>480 )
							break;
					}
					randx1[cnt1][0]=rand()%279;
					randx1[cnt1][1]=0;
					putimage( randx1[cnt1][0], randx1[cnt1][1], &img );
				}
			}
			break;
		case 1:
			if( rand()%( 3-( player2.getmile() )/100 ) == 0 )
			{
				if( ( player2.getspeed() != 0 ) && ( decidex2 == true ) )
				{
					for( ;cnt2<100;cnt2++ )
					{
						if( randx2[cnt2][1]<=0 || randx2[cnt2][1]>480 )
							break;
					}
					randx2[cnt2][0]=rand()%280+321;
					randx2[cnt2][1]=0;
					putimage( randx2[cnt2][0], randx2[cnt2][1], &img );
				}
			}
			break;
		default:
			outtextxy( 0, 0, _T("your program is broken.") );
			break;
		}
	}
}
void supply( int supply[][2], const bool decidex, IMAGE img, int x, Player player )
{
	if( decidex == true && rand()%300 == 0 && player.getspeed() != 0 && ( supply[0][1] == -1 || supply[0][1]>480 ) )
	{
		supply[0][0]=rand()%294+321*x;
		supply[0][1]=0;
		putimage( supply[0][0], supply[0][1], &img );
	}
}
void getsupply( int x, int supply[][2], const bool decidex, IMAGE img, Player& player )
{
	if( decidex == true )
		if( supply[0][1]>=0 && supply[0][1]<=480 )
		{
			supply[0][1]+=player.getspeed();
			putimage( supply[0][0], supply[0][1], &img );
		}
	if( supply[0][0]-x<23 && x-supply[0][0]<25 && supply[0][1]>384 && supply[0][1]<464 )
	{
		supply[0][1]=-1;
		player.getsupply();
	}
}
void prevent( int randx[][2], IMAGE img, const bool decidex, Player player, int counter, int subx, int x )
{
	int cnt=0;

	if( decidex == true && player.getspeed() != 0 )
	{
		if( subx == x )
		{
			for( ;cnt<100;cnt++ )
			{
				if( randx[cnt][1]<=0 || randx[cnt][1]>480 )
					break;
			}
			if( x>( ( x/320+1 )*320-40 ) )
			{
				for( ;x>( ( x/320+1 )*320-40 ); )
					x--;
			}
			if( x/320 == 0 )
				randx[cnt][0]=x;
			else
				randx[cnt][0]=x+1;
			randx[cnt][1]=0;
			putimage( randx[cnt][0], randx[cnt][1], &img );
		}
	}
}
void lose( int randx1[][2], int randx2[][2], int x1, int x2, bool& decidex1, bool& decidex2 )
{
	for( int cnt1=0;cnt1<100;cnt1++ )
	{
		if( randx1[cnt1][1]>380 && randx1[cnt1][1]<464 )
		{
			if( randx1[cnt1][0]>x1-40 && randx1[cnt1][0]<x1+23 )
			{
				decidex1=false;
				break;
			}
		}
	}
	for( int cnt2=0;cnt2<100;cnt2++ )
	{
		if( randx2[cnt2][1]>380 && randx2[cnt2][1]<464 )
		{
			if( randx2[cnt2][0]>x2-40 && randx2[cnt2][0]<x2+23 )
			{
				decidex2=false;
				break;
			}
		}
	}
}
void ai( const int randx2[][2], Player& player2, int&x2, const bool renx, bool& ma, int bullet2[][2], IMAGE img4 )
{
	bool k=true;

	if( renx == false )
	{
		if( player2.getspeed() != 5 )
			player2.addspeed();
		for( int i=0;i<100;i++ )
		{
			if( randx2[i][0]<x2+24 && randx2[i][0]>x2-41 && x2-randx2[i][1]<440 )
			{
				k=false;
				int j=1;
				if( player2.getbulletnumber() != 0 && rand()%100 == 0 )
				{
					launch( bullet2, x2, player2, img4 );
					break;
				}
				if( x2-randx2[i][1]<80 )
					j=4;
				for( int k=0;k<=j;k++ )
				{
					if( x2-320<70 )
						ma=false;
					if( 616-x2<70 )
						ma=true;
					if( ma == true )
						x2--;
					if( ma == false )
						x2++;
				}
				break;
			}
		}
		if( k == true )
		{
			if( rand()%2 == 0 )
				x2--;
			else
				x2++;
		}
	}
}