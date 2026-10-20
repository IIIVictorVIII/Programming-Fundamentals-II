//Victor Villarrreal
//this program takes the slaes of 4 divisons stores them in variables then
//find the division or divisions with the top sales. 
//last updated: 10/01/2026

//preprocessor directives.
#include <iostream>
#include <string>
using namespace std; 

//function prototypes.
double getSales(string division);
void findHighest(double& division1, double& division2, double& division3, double& division4);

int main()
{
	//variables to hold each divisions sales.
	double neSales;
	double seSales;
	double nwSales;
	double swSales;

	//calls the function 4 tiems for each division.
	neSales = getSales("Northeast");
	seSales = getSales("Southeast");
	nwSales = getSales("Northwest");
	swSales = getSales("Southwest");
	
	//get highest sales or tie sales and print them. 
	findHighest(neSales, seSales, nwSales, swSales);
	
	return 0;
}

double getSales(string division) 
{
	//initialize variable
	double sales;

	//get users sales for the division.
	cout << "Enter quarterly sales for " << division << " division: ";
	cin >> sales;

	//check for negative numbers. 
	while (sales < 0) 
	{
		cout << "Sales figures cannot be negative. please re-enter. " << endl;
		cout << "Enter quarterly sales for " << division << " division: ";
		cin >> sales; 
	}
	//return value back for later use. 
	return sales;
	
}
void findHighest(double& division1, double& division2, double& division3, double& division4)
{
	//initialize variables
	double Highest = division1;
	string topDivision = "Northeast";
	string equalDivisions = "Northeast ";
	int choice = 1;


	//check for highest number between divisions and store both division name and 
	//division sales in variables.
	//also check if vlaues are equal and store them in an equal divisions variable. 
	if (division2 > Highest)
	{
		Highest = division2;
		topDivision = "Southeast";
		equalDivisions = "Southeast ";
	}	
	else if (Highest == division2)
	{
		equalDivisions += "Southeast ";
		choice = 2;
	}

	if (division3 > Highest)
	{
		Highest = division3;
		topDivision = "Northwest";
		equalDivisions = "Northwest  ";
	}
	else if (Highest == division3)
	{
		equalDivisions += "Northwest ";
		choice = 2;
	}

	if (division4 > Highest)
	{
		Highest = division4;
		topDivision = "Southwest ";
		equalDivisions = "Southwest";
	}
	else if (Highest == division4)
	{
		equalDivisions += "Southwest ";
		choice = 2;
	}

	//switch between case of tie and case of one highest divisons 
	switch (choice) 
	{

	case 1:
		cout << "The " << topDivision << " had the highest sales this quarter." << endl;
		cout << "Their sales were: $" << Highest << endl;

	case 2:
		cout << "the " << equalDivisions << "divisions had the a tie for the highest sales this quarter." << endl;
		cout << "Their sales were: $" << Highest <<endl;
	}

}
