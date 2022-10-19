#ifndef RESERVATIONDATABASE_H
#define RESERVATIONDATABASE_H
#include<vector>
#include<fstream>
#include"Reservation.h"
class ReservationDatabase {
public:
    void loadreservations(vector< Reservation >& reservations)
    {
        ifstream inFile;
        inFile.open("Reservations.dat", ios::in | ios::binary);

        Reservation a;
        /*      while (inFile)
               {
                   inFile.read(reinterpret_cast<char*>(a.mobileNumber), 12);
                   inFile.read(reinterpret_cast<char*>(a.name), 8);
                   inFile.read(reinterpret_cast<char*>(&a.date.year), sizeof(int));
                   inFile.read(reinterpret_cast<char*>(&a.date.month), sizeof(int));
                   inFile.read(reinterpret_cast<char*>(&a.date.day), sizeof(int));
                   inFile.read(reinterpret_cast<char*>(&a.time), sizeof(int));
                   inFile.read(reinterpret_cast<char*>(a.email), 40);
                   inFile.read(reinterpret_cast<char*>(&a.numCustomers), sizeof(int));
                   inFile.read(reinterpret_cast<char*>(a.password), 12);
                   inFile.read(reinterpret_cast<char*>(&a.reservationNumber), 12);

                   reservations.push_back(a);
               }
               if (reservations.size() != 0)
                   reservations.pop_back();*/
        while (inFile.read(reinterpret_cast<char*>(&a), sizeof(Reservation))) {
            reservations.push_back(a);
        }
        inFile.close();
    };

    void storereservations(vector< Reservation >& reservations)
    {
        ofstream outFile;
        outFile.open("Reservations.dat", ios::out | ios::binary);

        int i = 0;
        /*while (i < reservations.size())
        {
            outFile.write(reinterpret_cast<char*>(reservations[i].mobileNumber), 12);
            outFile.write(reinterpret_cast<char*>(reservations[i].name), 8);
            outFile.write(reinterpret_cast<char*>(&reservations[i].date), sizeof(Date));
            outFile.write(reinterpret_cast<char*>(&reservations[i].time), 3);
            outFile.write(reinterpret_cast<char*>(reservations[i].email), 40);
            outFile.write(reinterpret_cast<char*>(&reservations[i].numCustomers), 12);///?
            outFile.write(reinterpret_cast<char*>(&reservations[i].password), 12);
            outFile.write(reinterpret_cast<char*>(&reservations[i].reservationNumber), 12);
            i++;
        }*/
        for (int i = 0; i < reservations.size(); i++) {
            outFile.write(reinterpret_cast<const char*>(&reservations[i]), sizeof(reservations[i]));
        }
        outFile.close();

    };
};
#endif 
