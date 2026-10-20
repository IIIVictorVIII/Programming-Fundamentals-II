// Victor Villarreal
// This program asks user for starting and desired ending location then based off of given table 
// the program tells the users how much the trip will cost. 
//last updtated: 10/17/2026

#include <iostream>
using namespace std;

void TripCost(int userStart, int userEnd);
void getmenuOption(int& option1, int& option2);



int main()
{

	int startloc= 0;
	int endloc= 0 ;
	char Looping = 'y';

	//keeps program running if user wants to calculate another route
	while (Looping == 'y')
	{
		getmenuOption(startloc, endloc);
		TripCost(startloc, endloc);
		
		//check for additoinal route calculation.
		cout << "Would you like to calculate another route? (y/n): ";
		cin >> Looping;

	}

	return 0;
}
void getmenuOption(int& option1, int& option2){

	//possible do while
	//menu options 
	
	cout << "1.Rowe Lane" << endl;
	cout << "2.I-95" << endl;
	cout << "3.Kelly Lane" << endl;
	cout << "4.Martin Street" << endl;
	cout << "=======================" << endl;
	cout << endl;

	//gets users first location.
	cout << "Enter number for starting location: ";
	cin >> option1;
	while (option1 < 1 || option1 > 4) {

		cout << "!invalid option!"<<endl;
		cout << "Enter number for starting location: ";
		cin >> option1;

	}
	//gets users second location.
	cout << "Enter number for end location: ";
	cin >> option2;
	while (option2 < 1 || option2 > 4) {
		cout << "!Invalid Option!" << endl;
		cout << "Enter number for end location ";
		cin >> option2;
	}


}

//gets trip from the table of toll costs. 
void TripCost(int userStart, int userEnd) {
	
	
	double cost;
	double tableValues[4][4] = {{ 0, 2.33 , 2.56 , 3.28},
								{ 2.33 , 0 , 1.58 , 2.33 },
								{ 2.56 , 1.58 , 0 , 1.95 },
								{ 3.28 , 2.33 , 1.95 , 0 }};	
	

	cost = tableValues[userStart - 1][userEnd - 1];
	

	cout << "the trip cost is: " << cost<<endl;

}
