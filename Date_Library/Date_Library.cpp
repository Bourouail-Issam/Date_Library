#include <iostream>
#include "clsDate.h"
using namespace std;

int main()
{
	clsDate Date1;
	Date1.Print();

	clsDate Date2("42/04/1999");
	Date2.Print();

	clsDate Date3(20,12,2022);
	Date3.Print();

	clsDate Date4(250, 2022);
	Date4.Print();

	Date4.PrintMonthCalendar() ;
	Date4.PrintYearCalendar();

	cout << "My Age In Days : " << clsDate::CalculateMyAgeInDays(clsDate(6, 11, 1977)) << endl;
	cout << Date4.IsDate1BeforeDate2(Date1,Date2);
}
