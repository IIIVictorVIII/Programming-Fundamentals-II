//Victor Villarreal
//This program asks user for date input in mm/dd/yyyy format and prints out each peice of data stored 
//in the date with error checking for newline characters. 
//9/13/2026

#include <iostream>
#include <iomanip> // Needed for formatting output

int main() {
    int month, day, year;
    char slash1, slash2;

    // Prompt the user for input
    std::cout << "Enter date (mm/dd/yyyy): ";

    // Single input statement to accept all parts
    // The char variables (slash1, slash2) store the '/' characters
    std::cin >> month;

    if (std::cin.peek() == '\n') {
        
        std::cout << "Invalid input format." << std::endl;
    }
    else {
        std::cin >> slash1 >> day >> slash2 >> year;

        // Demonstrate correct input by outputting each piece
        std::cout << "Month entered: " << std::setw(2) << std::setfill('0') << month << std::endl;
        std::cout << "Day entered:   " << std::setw(2) << std::setfill('0') << day << std::endl;
        std::cout << "Year entered:  " << year << std::endl;
    }

    return 0;
}