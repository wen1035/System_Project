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
	abc.initializeAvailtable(availtables);//初始化
	
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

//從鍵盤輸入一個整數，然後
//如果它屬於[begin，end]，則返回整數，否則返回-1。
int inputAnInteger(int begin, int end)
{
	string abc;
	int number = 0;
	int i = 0;
	cin >> abc;//輸入字或2以上數字
	int k = pow(10, abc.length() - 1);//10的次方，用來轉數字

	//將輸入字串改成數字
	while (abc[i] != '\0')
	{
		if (!((abc[i] >= 48) && (abc[i] <= 57)))//判斷是否在ASCII的數字代號的範圍(其中48～57為0到9十個阿拉伯數字)
		{
			number = -1;
			break;
		}
		if (abc.length() == 2 && abc[i] == '0' && abc[i + 1] == '0')
		{
			number = -1;
			break;
		}
		number += (abc[i] - '0') * k;//字元-'0'乘10的次方
		k /= 10;//減一個次方
		i++;
	}

	//判斷是否在範圍內
	for (int j = begin; j <= end; j++)
	{
		if (number == j)
			return j;
	}
	return -1;
};
