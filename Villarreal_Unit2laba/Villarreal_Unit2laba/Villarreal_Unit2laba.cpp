// Victor Villarreal 
// this program takes users fuel capacity and miles per gallon then calculates 
// how many miles before refuel is required
// 9/1/26

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	//define variables.
	double capacity, mpg, range;
	
	//get user fuel capacity and estimated MPG.
	cout << "Enter the fuel tank capacity in gallons:";
	cin >> capacity;
	cout << "Enter the estimated miles per gallon traveling : ";
	cin >> mpg;
	
	//calculate and display users range with rounding and without rounding. 
	range = capacity * mpg;
	cout << "The car can be driven " << range << " miles without refueling." << endl;
	cout << "the car can be driven " << round(range) << " miles wihtout refueling" << endl;
	return 0;
}

