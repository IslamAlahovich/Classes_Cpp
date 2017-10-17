#include "stdafx.h"
#include <iostream>
#include "discpp.h"
using namespace std;
int main()
{
	Dislin g;
	g.disini();
	g.messag("This is a test", 100, 100);
	g.disfin();

	return 0;
}