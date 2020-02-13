#include "MyCharStar.h"

void main()
{
	MyCharStar Star("test"), rast;

	Star = "another onE";
    Star = "dbl_another onE";
	cout << Star << endl;

	rast = rast + " " + "kek";
    cout << rast << endl;

	Star = Star + rast;
    cout << Star << endl;
	
	cout << Star[10];
	_getch();
}
