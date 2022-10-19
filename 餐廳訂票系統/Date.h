#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<fstream>
#include <iomanip>
#include <vector>
using namespace std;

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct Date {
public:
	void computeCurrentDate(Date& currentDate);
	bool leapYear(int year);
	bool earlier(const Date& date1, const Date& date2);
	int difference(const Date& date1, const Date& date2);
	Date addition(const Date& currentDate, int numDays);

	int year = 2000;
	int month = 0;
	int day = 0;
}b;

void Date::computeCurrentDate(Date& currentDate)
{
	int remainingSeconds = static_cast<int>(time(0)) + 8 * 60 * 60;

	currentDate.year = 1970;

	int secondsPerYear = 365 * 24 * 60 * 60;
	if (leapYear(currentDate.year))
		secondsPerYear += 24 * 60 * 60;

	while (remainingSeconds >= secondsPerYear)
	{
		remainingSeconds -= secondsPerYear;
		currentDate.year++;

		secondsPerYear = 365 * 24 * 60 * 60;
		if (leapYear(currentDate.year))
			secondsPerYear += 24 * 60 * 60;
	}

	if (leapYear(currentDate.year))
		days[2] = 29;

	currentDate.month = 1;
	while (remainingSeconds >= days[currentDate.month] * 24 * 60 * 60)
	{
		remainingSeconds -= days[currentDate.month] * 24 * 60 * 60;
		currentDate.month++;
	}

	currentDate.day = remainingSeconds / (24 * 60 * 60) + 1;
}

bool  Date::leapYear(int year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
bool  Date::earlier(const Date& date1, const Date& date2)
{
	if (date1.year >= date2.year) {
		if (date1.month >= date2.month) {
			if (date1.day < date2.day) {
				return true;
			}
			if (date1.day == date2.day) {
				return false;
			}
			if (date1.day > date2.day) {
				return false;
			}
		}
		return true;
	}
	return true;

}
int  Date::difference(const Date& date1, const Date& date2)
{
	int d = -1;

	if (date1.month == date2.month) {
		d = date1.day - date2.day;
	}
	if (date1.month != date2.month) {

		for (int i = 0; i < date1.month - date2.month; i++)
		{
			d += days[date2.month + i];
		}

	}
	if (date1.year != date2.year) {
		d += 365 * (date1.year - date2.year);
	}

	return d;

} 
Date Date::addition(const Date& currentDate, int numDays)
{
	Date temp = currentDate;
	temp.day += numDays;
	if (temp.leapYear(temp.year))
		days[2] = 29;
	else
		days[2] = 28;
	while (temp.day > days[temp.month])
	{
		temp.day -= days[temp.month];
		temp.month++;
		if (temp.month == 13) // new year
		{
			temp.month = 1;
			temp.year++;
			if (temp.leapYear(temp.year))
				days[2] = 29;
			else
				days[2] = 28;
		}
	}
	return temp;
}
#endif // !DATE_H

