#ifndef AVAILTABLE_H
#define AVAILTABLE_H

#include <vector>
#include "Date.h"
#include "AvailTableDatabase.h"

int tabletype[13] = {0,1,1,2,2,3,4,4,0,0,5,5,5 };
const int totalNumtable = 2;

class Availtable 
{
public:
	Date date;
	int numAvailTables[4][6];

	void initializeAvailtable(vector< Availtable >& availtable) {

		Date currentDate;
		currentDate.computeCurrentDate(currentDate);

		Availtable temp;
		for (int j = 0;j < 4;j++)
			for (int i = 1; i < 6; i++)
				temp.numAvailTables[j][i] = totalNumtable;


		Date date;
		if (availtable.size() == 0)
		{
			date = date.addition(currentDate, 1);

			for (int i = 0; i < 31; i++) // initial (current date + 1) ~ (current date + 30)
			{
				temp.date = date.addition(date, i);
				availtable.push_back(temp);
			}
			return;

		}
		else
		{
			if (date.earlier(availtable[availtable.size() - 1].date, currentDate))
			{
				availtable.clear();

				date = date.addition(currentDate, 1);

				for (int i = 0; i < 31; i++) // initial (current date + 1) ~ (current date + 30)
				{
					temp.date = date.addition(date, i);
					availtable.push_back(temp);
				}
				return;
			}
			else if (date.earlier(availtable[0].date, currentDate))
			{
				do
				{
					temp.date = date.addition(availtable[0].date, 31);
					availtable.erase(availtable.begin());
					availtable.push_back(temp);
				} while (date.earlier(availtable[0].date, currentDate));
			}
		}
	};

	bool hasAvailableTable1(const vector< Availtable >& availtable, const Date date, int people) {
		int type = tabletype[people];
		int pos = findAvailTable(availtable, date);

		if (pos >= 0 && availtable[pos].numAvailTables[1][type] > 0 || availtable[pos].numAvailTables[2][type] > 0 ||
			availtable[pos].numAvailTables[3][type] > 0)
			return true;
		else
			return false;
	};
	bool hasAvailableTable2(const vector< Availtable >& availtable, const Date date, int timeCode, int people) {
		
		int type = tabletype[people];
		int pos = findAvailTable(availtable, date);

		if (pos>=0 && availtable[pos].numAvailTables[timeCode][type] > 0)
			return true;
		else
			return false;
	};
	int findAvailTable(const vector< Availtable >& availtable, Date date) {

		for (int i = 0; i < availtable.size(); i++) {//size()==length()   sizeof ¤£¦P
			if (availtable[i].date.year == date.year && availtable[i].date.month == date.month && availtable[i].date.day == date.day)
				return i;
		}
		return -1;
	};

	void decreaseAvailtable(vector< Availtable >& availtable, const Date date, int timeCode, int people)
	{
		int type = tabletype[people];
		int pos = findAvailTable(availtable, date);
		if (pos >= 0)
			availtable[pos].numAvailTables[timeCode][type] -= 1;
	};

	void increaseAvailtable(vector< Availtable >& availtable, const Date date, int timeCode, int people)
	{
		int type = tabletype[people];
		int pos = findAvailTable(availtable, date);
		availtable[pos].numAvailTables[timeCode][type] += 1;
	};
};
#endif //AVAILTABLE_H




