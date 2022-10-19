
#ifndef RESERVATIONINQUIRY_H
#define RESERVATIONINQUIRY_H
#include<vector>
#include<string>
#include"AvailtableDatabase.h"
#include"Reservation.h"
#include"AvailTable.h"
#include<iostream>
using namespace std;
class ReservationInquiry {
public:
	void viewReservation( vector< Reservation >& reservations, vector<Availtable>& availtables);
	void displayReservationInfo( vector< Reservation >& reservations, vector<Availtable>& availtables,char reservationNumber[]);
	void displayReservationInfo(vector<Reservation>& reservationvec, const Reservation& reservation, vector<Availtable>& availtables);
	//bool exist(const vector< Reservation >& reservations, char phoneNumber[], char reservationnum[]);
	int exist(const vector< Reservation >& reservations, char reservationnumber[]);
	bool existnumber(const vector< Reservation >& reservations, char reservationnumber[]);
	bool existpassword(const vector< Reservation >& reservations, char reservationpassword[]);
	//void deletere(vector< Reservation >& reservations, char reservationnumber[]);
};
void ReservationInquiry::viewReservation( vector< Reservation >& reservations, vector<Availtable>& availtables)
{

	ReservationInquiry temp2;
	if (reservations.size() == 0)
	{
		cout << "\nNo reservations!\n";
		return;
	}
	else {
		for (int i = 0; i < reservations.size(); i++) {
			if (reservations[i].numCustomers != 0)
				break;
			if (i == reservations.size() - 1 && reservations[i].numCustomers == 0) {
				cout << "\nNo reservations!\n";
				return;
			}

		}
	}
	char reservationNumber[12];
	cout << "\nEnter reservation number: ";
	cin >> reservationNumber;
	if (!temp2.existnumber(reservations, reservationNumber)) {
		cout<< "\nNo reservations with this reservation number!\n";
		return;
	}

	char reservationpassword[12];
	cout << "\nEnter reservation password:";
	cin >> reservationpassword;
	if (!temp2.existpassword(reservations, reservationpassword)) {
		cout << "\nYour password is wrong!\n";
		return;
	}

	cin.ignore();
	int num = temp2.exist(reservations, reservationNumber);
	

	displayReservationInfo(reservations, availtables, reservationNumber);

	Availtable temp;
	char a;
	while (true) {
		cout << "\nCancel this reservation? (y/n)\n";
		cin >> a;
		if (a == 'y' || a == 'n')
			break;
	}
	if (a == 'y') {
		temp.increaseAvailtable(availtables, reservations[num].date, reservations[num].time, reservations[num].numCustomers);
		reservations[num] = Reservation();
		cout << "\nThis reservation has been cancelled.";
	}
}

bool ReservationInquiry::existnumber(const vector< Reservation >& reservations, char reservationnumber[])
{
	for (int i = 0; i < reservations.size(); i++) {
		if (strcmp(reservations[i].reservationNumber, reservationnumber) == 0)
			return true;
	}
	return false;
}

bool ReservationInquiry::existpassword(const vector< Reservation >& reservations, char reservationpassword[])
{
	for (int i = 0; i < reservations.size(); i++) {
		if (strcmp(reservations[i].password, reservationpassword) == 0)
			return true;
	}
	return false;

}

int ReservationInquiry::exist(const vector< Reservation >& reservations, char reservationnumber[])
{
	for (int i = 0; i < reservations.size(); i++) {
		if (strcmp(reservations[i].reservationNumber, reservationnumber) == 0)
			return i;
	}
	return -1;
}
void ReservationInquiry::displayReservationInfo(vector< Reservation >& reservations, vector<Availtable>& availtables,
	char reservationNumber[])
{
	cout << endl;
	int count = 0;
	for (size_t i = 0; i < reservations.size(); ++i)
		if (strcmp(reservations[i].reservationNumber, reservationNumber) == 0)
		{
			displayReservationInfo(reservations,reservations[i], availtables);
		}
}

void ReservationInquiry::displayReservationInfo( vector<Reservation>& reservationvec,const Reservation& reservation, vector<Availtable>& availtables)
{

	cout << setfill(' ') << setw(11) << "Mobile No." << setw(10) << "Name"
		<< setw(20) << "Date" << setw(9) << "Time" << setw(30) << "Email"
		<< setw(19) << "No of Custormers" << setw(12) << "Password"
		<< setw(19) << "Reservation No." << endl;

	cout << setfill(' ') << setw(11) << reservation.mobileNumber << setw(10) << reservation.name
		<< setw(14);

	cout << reservation.date.year << "/";

	if (reservation.date.month < 10)
		cout << '0';
	cout << reservation.date.month << "/";

	if (reservation.date.day < 10)
		cout << '0';
	cout << reservation.date.day;

	char times[5][6] = {"", "11:30", "14:30", "17:30"};
	cout << setw(9) << times[reservation.time] << setw(30) << reservation.email
		<< setw(19) << reservation.numCustomers << setw(12) << reservation.password
	    << setw(19) << reservation.reservationNumber << endl;
	
}

#endif
