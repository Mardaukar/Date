#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date d1, d2(21, 8, 34);
	int d, m, y;

	cout << "First date is ";
	d1.print();
	cout << endl;
	cout << "Second date is ";
	d2.print();
	cout << endl;

	d = d2.get_day();
	m = d2.get_month();
	y = d2.get_year();
	cout << endl << d << " "
		<< m << " "
		<< y << endl;

	d2.next_day();
	cout << "Next day is ";
	d2.print();
	cout << endl;

	d1 = Date(31, 12, 1999);
	d1.next_day();
	cout << "Day after 31/12/1999 is ";
	d1.print();
	cout << endl;

	Date d3(2, 1, 2020);
	Date d4(31, 12, 2020);
	Date d5(31, 12, 2019);
	cout << "Days from New Year from 2.1.2020: " << d3.days_since_newyear() << endl;
	cout << "Days from New Year from 31.12.2020 (leap year): " << d4.days_since_newyear() << endl;
	cout << "Days from New Year from 31.12.2019: " << d5.days_since_newyear() << endl;

	Date d6(1, 1, 2020);
	Date d7(2, 1, 2020);
	Date d8(1, 1, 2010);
	Date d9(1, 1, 2019);
	Date d10(1, 2, 2019);
	Date d11(1, 3, 2019);
	Date d12(1, 2, 2020);
	Date d13(1, 3, 2020);
	Date d14(1, 1, 2021);

	cout << "Days between 1.1.2020 and 1.1.2020: " << d6.days_between(d6) << endl; //Check equal

	cout << "Days between 1.1.2020 and 2.1.2020: " << d6.days_between(d7) << endl; //Check one day both ways
	cout << "Days between 2.1.2020 and 1.1.2020: " << d7.days_between(d6) << endl;

	cout << "Days between 1.1.2019 and 1.1.2020: " << d9.days_between(d6) << endl; //Check one year both ways
	cout << "Days between 1.1.2020 and 1.1.2019: " << d6.days_between(d9) << endl;

	cout << "Days between 1.1.2020 and 1.1.2021 (leap year): " << d6.days_between(d14) << endl; //Check one year over leap both ways
	cout << "Days between 1.1.2021 and 1.1.2020 (leap year): " << d14.days_between(d6) << endl;

	cout << "Days between 1.1.2020 and 1.1.2010: " << d6.days_between(d8) << endl; //Check ten years both ways
	cout << "Days between 1.1.2010 and 1.1.2020: " << d8.days_between(d6) << endl;

	cout << "Days between 1.2.2019 and 1.3.2019: " << d10.days_between(d11) << endl; //Check both Februaries
	cout << "Days between 1.2.2020 and 1.3.2020 (leap year): " << d12.days_between(d13) << endl;
}