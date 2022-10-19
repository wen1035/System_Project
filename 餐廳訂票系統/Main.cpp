#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>

#include"AvailtableDatabase.h"
#include"MakeReservation .h"
#include"ReservationDatabase.h"
#include"ReservationInquiry.h"
using namespace std;

int inputAnInteger(int begin, int end);

int main() {

	vector< Reservation > reservations;
	vector< Availtable > availtables;

	ReservationDatabase re_data;
	AvailtableDatabase a_data;

	Availtable abc;
	
	a_data.loadavailtables(availtables);
	abc.initializeAvailtable(availtables);//��l��
	
	re_data.loadreservations(reservations);
	

	MakeReservation M_Re;
	ReservationInquiry Booking;

	cout << "Welcome to Hi-Lai Harbour Taoyuan Location!" << endl;
	while (true) {

		cout << "\n1 - Book a Table" << endl;
		cout << "2 - My Bookings" << endl;
		cout << "3 - End" << endl;
		int choice;

		while (true) {
			cout << "\nEnter your choice:(1-3):";
			choice = inputAnInteger(1, 3);
			if (choice == -1)
				continue;
			break;
		}

		switch (choice) {
		case 1:
			M_Re.makeReservation(reservations, availtables);
			break;
		case 2:
			Booking.viewReservation( reservations,availtables);
			break;
		case 3:
			re_data.storereservations(reservations);

			a_data.storeavailtables(availtables);
			system("pause");
			exit(1);			
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

//�q��L��J�@�Ӿ�ơA�M��
//�p�G���ݩ�[begin�Aend]�A�h��^��ơA�_�h��^-1�C
int inputAnInteger(int begin, int end)
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
