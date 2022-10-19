#ifndef AVAILTABLEDATABASE_H
#define AVAILTABLEDATABASE_H

#include <vector>
#include <fstream>
#include <iostream>
#include "AvailTable.h"

class AvailtableDatabase : Availtable
{
public:
	void loadavailtables(vector< Availtable >& availtables)
	{
		ifstream inFile;
		inFile.open("C:\\Users\\wendy\\Desktop\\Project2\\AvailTables.dat", ios::in | ios::binary);

		Availtable a;
		while (inFile)
		{
			inFile.read(reinterpret_cast<char*>(&a.date.year), sizeof(int));
			inFile.read(reinterpret_cast<char*>(&a.date.month), sizeof(int));
			inFile.read(reinterpret_cast<char*>(&a.date.day), sizeof(int));
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					inFile.read(reinterpret_cast<char*>(&a.numAvailTables[i][j]), sizeof(int));
				}
			}
		
			availtables.push_back(a);
		}
		if (availtables.size() != 0)
			availtables.pop_back();
		inFile.close();
	};


	void storeavailtables(vector< Availtable >& availtables)
	{
		ofstream outFile;
		outFile.open("C:\\Users\\wendy\\Desktop\\Project2\\AvailTables.dat", ios::out | ios::binary);
		int i = 0;
		while (i < availtables.size())
		{
			outFile.write(reinterpret_cast<char*>(&availtables[i].date.year), 4);
			outFile.write(reinterpret_cast<char*>(&availtables[i].date.month), 4);
			outFile.write(reinterpret_cast<char*>(&availtables[i].date.day), 4);

			outFile.write(reinterpret_cast<char*>(&availtables[i].numAvailTables[0]), 6);
			outFile.write(reinterpret_cast<char*>(&availtables[i].numAvailTables[1]), 6);
			outFile.write(reinterpret_cast<char*>(&availtables[i].numAvailTables[2]), 6);
			
			i++;
		}
		outFile.close();

	};

	
};
#endif
