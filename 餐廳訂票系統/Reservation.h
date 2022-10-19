#ifndef RESERVATION_H
#define RESERVATION_H

#include<string>
#include"AvailtableDatabase.h"
#include"AvailTable.h"
#include"Date.h"
#include<iostream>
using namespace std;

class Reservation {
public:
	int numCustomers = 0;                 
	Date date = Date();                 
	int time = 0;                   
	char name[8] = "";                  
	char mobileNumber[12] = "";      
	char email[40] = "";               
	char password[12] = "";           
	char reservationNumber[12] = ""; 


	void Rand_r( char reservationnum[]) {
		for (int i = 0;i < 8;i++) {
			reservationnum[i] =  (rand() % 10 + '0');
		}
	}

};
#endif
