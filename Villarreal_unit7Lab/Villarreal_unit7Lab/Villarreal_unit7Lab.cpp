// Villarreal_unit7Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


string qualifies(string& record);

int main()
{
	string record;


	ifstream infile;
	infile.open("C:/Users/Owner/OneDrive/Desktop/school/Programming_Fundamentals_II/Lab_Downloads/ABCPharmainventory.txt");

	while (getline(infile, record))
	{

		qualifies(record);
		cout << record << endl;

	}

	return 0;
}

string qualifies(string& recordp)
{
	string code;

	code = recordp.substr(0, recordp.find(" "));

	if (code.find("A") == 0 || code.find("D") == 0 || code.find("H") == 0)
	{
		recordp = recordp + "--------------------->" + "Qualifed expense";
		return recordp;
	}

	else
		return recordp;
}
	