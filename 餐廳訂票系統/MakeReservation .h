
#ifndef MAKERESERVATION_H
#define MAKERESERVATION_H
//#include"ReservationDatabase.h" //#include"AvailtableDatabase.h"
#include"ReservationInquiry.h"
#include"ReservationDatabase.h"
#include"AvailTable.h"
#include"Date.h"
#include<iostream>
using namespace std;

class MakeReservation {
public:
	void makeReservation(vector< Reservation >& reservations,
		vector< Availtable >& availtable);
	int inputAnInteger(int begin, int end);
	void inputDate(vector< Availtable >& availtable, Date& date, const Date& currentDate, int people);
	void inputTimeCode(const vector< Availtable >& availtable, const Date date, int& timeCode, int people);
};

void MakeReservation::makeReservation(vector< Reservation >& reservations,vector< Availtable >& availtable)
{
	Reservation abc;
	ReservationInquiry temp2;
	Availtable temp;
	cout << endl;

	while (true) 
	{
		cout << "Enter the number of customers (1 - 7, 10 - 12): ";
		abc.numCustomers = inputAnInteger(1, 12);
		if (abc.numCustomers != -1 && abc.numCustomers != 8 && abc.numCustomers != 9) {
			break;
		}
	}

	Date currentDate;
	currentDate.computeCurrentDate(currentDate);

	inputDate(availtable, abc.date, currentDate,
		abc.numCustomers);

	inputTimeCode(availtable, abc.date, abc.time,
		abc.numCustomers);

	cout << "\nEnter name : ";
	cin >> abc.name;

	cout << "\nEnter mobile number : ";
	cin >> abc.mobileNumber;

	cout << "\nEnter email address : ";
	cin >> abc.email;

	cout << "\nEnter reservation password : ";
	cin >> abc.password;
	cin.ignore();

	abc.Rand_r(abc.reservationNumber);
	//cout << endl<< newReservation.reservationNumber;
	cout << endl;
	temp2.displayReservationInfo(reservations,abc,availtable);

	reservations.push_back(abc);
	cout << "\nReservation Completed.\n";

	temp.decreaseAvailtable(availtable, abc.date, abc.time, abc.numCustomers);
};

void MakeReservation::inputDate(vector< Availtable >& availtable, Date& date,
	const Date& currentDate, int people)
{
	Availtable temp1;
	Date temp;
	cout << "Choose a date" << endl;
	int j = 0;
	for (int i = 1; i < 31; i++) {
		temp = temp.addition(currentDate, i);
		if (temp1.hasAvailableTable1(availtable, temp, people)) 
		{
			cout << setw(3) << i  << ". " << temp.year << "/";
			if (temp.month < 10)
				cout << "0" << temp.month << "/";
			else
				cout << temp.month << "/";

			if (temp.day < 10)
				cout << "0" << temp.day << "  ";
			else
				cout << temp.day << "  ";
			j++;
		}

		if (j == 4) {
			cout << endl;
			j = 0;
		}

	}

	int choicet;
	while (true)
	{
		cout << endl << "?";
		choicet = inputAnInteger(1, 30);
		if (choicet == -1 || temp1.hasAvailableTable1(availtable, availtable[choicet - 1].date, people) == false) {
			continue;
		}
		date = availtable[choicet - 1].date;
		break;
	}

}
void MakeReservation::inputTimeCode(const vector< Availtable >& availtable, const Date date,
	int& timeCode, int people)
{
	Availtable temp1;
	int requiredtable = people;

	cout << "\nChoose a time:\n";
	string time[4] = { "","11:30","14:30","17:30"};
	int haveseat[5] = {};
	for (int i = 1; i < 4; i++) 
	{
		if (temp1.hasAvailableTable2(availtable, date, i, requiredtable) == true)
		{
			cout  << i << ". " << time[i] << endl;
			haveseat[i] = i;
		}
	}

	int choice2;
	while (true) {
		cout << "? ";
		choice2 = inputAnInteger(1, 3);
		if (choice2 == -1 || temp1.hasAvailableTable2(availtable, date, choice2, people) == false)
			continue;
		break;
	}

	timeCode = choice2;

}

//�q��L��J�@�Ӿ�ơA�M��
//�p�G���ݩ�[begin�Aend]�A�h��^��ơA�_�h��^-1�C
int MakeReservation::inputAnInteger(int begin, int end)
{
	string abc;
	int number = 0;
	int i = 0;
	cin >> abc;//��J�r��2�H�W�Ʀr
	int k = pow(10, abc.length() - 1);//10������A�Ψ���Ʀr

	//�N��J�r��令�Ʀr
	while (abc[i] != '\0')
	{
		if (!((abc[i] >= 48) && (abc[i] <= 57)))//�P�_�O�_�bASCII���Ʀr�N�����d��(�䤤48��57��0��9�Q�Ӫ��ԧB�Ʀr)
		{
			number = -1;
			break;
		}
		if (abc.length() == 2 && abc[i] == '0' && abc[i + 1] == '0')
		{
			number = -1;
			break;
		}
		number += (abc[i] - '0') * k;//�r��-'0'��10������
		k /= 10;//��@�Ӧ���
		i++;
	}

	//�P�_�O�_�b�d��
	for (int j = begin; j <= end; j++)
	{
		if (number == j)
			return j;
	}
	return -1;
};

#endif 

