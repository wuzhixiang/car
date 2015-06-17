#include "开始.h"
#include "玩家系统.h"
#include "主程序.h"
#include <graphics.h> 
#include <conio.h>

Player::Player( TCHAR Name[] )
{
	for( int cnt=0;cnt<25;cnt++ )
		name[cnt]=Name[cnt];
	setspeed();
	setmile();
	setbulletnumber();
}
void Player::setspeed()
{
	speed=0;
}
int Player::getspeed()
{
	return speed;
}
void Player::setmile()
{
	mile=0;
}
int Player::getmile()
{
	return mile;
}
void Player::setbulletnumber()
{
	bulletnumber=5;
}
int Player::getbulletnumber()
{
	return bulletnumber;
}
void Player::changebulletnumber()
{
	bulletnumber--;
}
void Player::getsupply()
{
	bulletnumber=5;
}
void Player::outputname()
{
	outtextxy( 240,40,name );
}
void Player::addspeed()
{
	if( speed>=0 && speed<30 )
		speed+=1;
}
void Player::subtractspeed()
{
	if( speed>0 && speed<=30 )
		speed-=1;
}
void Player::changemile()
{
	mile+=speed;
}
void Player::output( const bool decidex,int x )
{
	TCHAR s[10];
	TCHAR p[10];
	TCHAR b[10];
	RECT r={320*x, 0, 320*(x+1), 480};

	wordstyle( 30, 10, WHITE, false );
	outtext( name );
	outtext( _T(":speed:") );
	_stprintf_s( s, _T("%d"), speed );
	outtext( s );
	outtext( _T("   m:") );
	_stprintf_s( p, _T("%d"), mile );
	outtext( p );
	outtext( _T("   bullet:") );
	_stprintf_s( b, _T("%d"), bulletnumber );
	outtext( b );
	outtext( _T("  ") );
	if( decidex == false && mile<300 )
	{
		settextcolor( RED );
		drawtext( _T("Your car has crushed."), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		settextcolor( WHITE );
	}
}