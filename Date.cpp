#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int dd, int mm, int yy)
{
	day = dd;
	month = mm;
	year = yy;
}

Date::Date()
{
	day = 1;
	month = 1;
	year = 1900;
}

int Date::get_day()
{
	return day;
}

int Date::get_month()
{
	return month;
}

int Date::get_year()
{
	return year;
}

void Date::print()
{
	cout << day << '/'
		<< month << '/'
		<< year;
}

void Date::next_day()
{
	int days_in_month;
	day++;
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days_in_month = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days_in_month = 30;
			break;
		case 2:
			if (leap_year())
				days_in_month = 29;
			else days_in_month = 28;
			break;
	}
	if (day > days_in_month)
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
}

int Date::leap_year()
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else return 0;
}

int Date::days_since_newyear()
{
	int days = day - 1; //Because compared to 1st day
	int daysOfMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (leap_year()) {
		daysOfMonths[1]++; //If leap year, add 1 to February
	}

	for (int i = 1; i < month; i++) {
		days += daysOfMonths[i - 1];
	}

	return days;
}

int Date::days_between(Date secondDate)
{
	int days_between = secondDate.days_since_newyear() - this->days_since_newyear();

	if (year == secondDate.get_year()) {
		// No operation
	}
	else if (year < secondDate.get_year()) {
		for (int i = year; i < secondDate.get_year(); i++) {
			days_between += 365;
			if (leap(i) == 1) {
				days_between += 1;
			}
		}
	}
	else {
		for (int i = secondDate.get_year(); i < year; i++) {
			days_between -= 365;
			if (leap(i) == 1) {
				days_between -= 1;
			}
		}
	}

	if (days_between > 0) {
		return days_between;
	}
	else {
		return days_between * -1;
	}
}

int leap(int year)
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else return 0;
}