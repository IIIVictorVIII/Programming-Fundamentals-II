// Victor villarreal 
// program goes through car sales file and prints contencts formatted with total commissions for employees and overall total
// sales, commissions and records. 
//last updated 9/23/2026

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main() 
{

	//heading 
	cout << "WEEKLY SALES REPORT\n" << endl;

	//initialize varibles 
	string file_header;
	string employeeid;
	double retail;
	double base;
	double commission;
	double totalCommisson = 0;
	int records = 0;
	double totalSales = 0;
	double alltimecommissions = 0;


	ifstream infile;

	//open file and store file header
	infile.open("C:/Users/Owner/OneDrive/Desktop/school/Programming_Fundamentals_II/Lab_Downloads/carsales.dat");
	getline(infile, file_header);

	//formatting 
	cout << setprecision(2) << fixed << showpoint << left;
	cout << setw(10) << "Employee" << setw(10) << "Retail" << setw(10) << "Base" << setw(10) << "Commission" << endl;

	// initilize first part of the loop
	infile >> employeeid>> retail>> base;
	commission = base * .30;
	if (commission < 100)
		commission = 100;
	cout << setw(10) << employeeid << setw(10) << retail << setw(10) << base << setw(10) << commission << endl;
	
	//totals
	totalCommisson += commission;// add to total commission.
	alltimecommissions += commission;
	records++;
	totalSales +=retail;

	//loop until data stops
	string currentid = employeeid;
	while (infile >> employeeid >> retail >> base)
	{	
		//tallies totals
		records++;
		totalSales +=retail;
		

		//check if employee id is still the same to output total comission
		if (currentid != employeeid)
		{

			cout << setw(10) << left << "total commission for " << currentid << ": " << setw(20) << right << totalCommisson << endl;
			cout << endl;
			totalCommisson = 0;// reset total commission for next id.

			commission = base * .30;
			if (commission < 100)
				commission = 100;

			totalCommisson += commission;
			alltimecommissions += commission;

			cout << setw(10) << left << employeeid << setw(10) << retail << setw(10) << base << setw(10) << commission << endl;

		}
		// else calculate commission and add it to total commission.
		else
		{

			commission = base * .30;
			if (commission < 100)
				commission = 100;

			totalCommisson += commission;
			alltimecommissions += commission;
			cout << setw(10) << employeeid << setw(10) << retail << setw(10) << base << setw(10) << commission << endl;

		}

		currentid = employeeid;
	}

	cout << setw(10) << left << "total commission for " << currentid << ": " << setw(20) << right << totalCommisson << endl;
	cout << endl;


	cout << "Records: " << records << endl;
	cout << "Total sales: " << totalSales << endl;
	cout << "Total commissions: " << alltimecommissions << endl;


	return 0;
}