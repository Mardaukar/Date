#pragma once

#ifndef DATE_H
#define DATE_h

int leap(int);

class Date
{
public:
	Date();
	Date(int dd, int mm, int yy);
	void print();
	void next_day();
	int get_day();
	int get_month();
	int get_year();
	int days_between(Date);
	int days_since_newyear();

private:
	int day;
	int month;
	int year;
	int leap_year();
};

#endif