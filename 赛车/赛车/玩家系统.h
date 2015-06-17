#include <graphics.h> 
#include <conio.h>

class Player
{
public:
	Player( TCHAR [] );
	void setspeed();
	int getspeed();
	void setmile();
	int getmile();
	void setbulletnumber();
	int getbulletnumber();
	void changebulletnumber();
	void getsupply();
	void outputname();
	void addspeed();
	void subtractspeed();
	void changemile();
	void output( const bool, int );
private:
	TCHAR name[25];
	int speed;
	int mile;
	int bulletnumber;
};