#include <graphics.h> 
#include <conio.h>

void decide( Player&, Player&, int&, int&, const bool, const bool, const bool );
void loadcar( int );
void launch( int [][2], int, Player&, IMAGE );
void bulletattack( int [][2], int[][2], const bool, IMAGE );
void obstacle( int [][2], int [][2], Player, Player, IMAGE, const bool, const bool, int );
void supply( int[][2], const bool, IMAGE, int, Player );
void getsupply( int, int[][2], const bool, IMAGE , Player& );
void prevent( int [][2], IMAGE, const bool, Player, int, int, int );
void lose( int [][2], int[][2], int, int, bool&, bool& );
void ai( const int[][2], Player&, int&, const bool, bool&, int[][2], IMAGE );