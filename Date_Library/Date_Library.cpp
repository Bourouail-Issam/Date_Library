#include <iostream>
#include "clsDate.h"
using namespace std;

int main()
{
	clsDate Date1;
	Date1.Print();

	clsDate Date2("22/04/1999");
	Date2.Print();
}
