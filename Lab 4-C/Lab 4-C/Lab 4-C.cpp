// Victor Villarreal 
// This program reads votes.dat line by line and tallies up yes and no's for each 
// district. 
// Lab 4-C 



//preprocessor directive
#include <iostream>
#include<cctype>
#include <fstream>
#include <iomanip>

using namespace std;

//variables
int district;
char vote;

int d1_vote_y = 0;
int d1_vote_n = 0;
int d2_vote_y = 0;
int d2_vote_n = 0;
int d3_vote_y = 0;
int d3_vote_n = 0;


int main()
{
    // declare file stream variables.
    ifstream indata;

    //open files
    indata.open("C:/Users/Owner/OneDrive/Desktop/school/Programming_Fundamentals_II/votes.dat");
    

    //bring data in from file.
    indata >> district >> vote;
    
    //switch case to add vote to corrosponding district
    switch (district)
    {
    case 1:
        if (vote == 'Y')
            d1_vote_y += 1;
        else
            d1_vote_n += 1;
        break;

    case 2:
        if (vote == 'Y')
            d2_vote_y += 1;
        else
            d2_vote_n += 1;
            break;
    case 3:
        if (vote == 'Y')
            d3_vote_y += 1;
        else
            d3_vote_n += 1;
            break;
    default:
        "error";
    }


    //(34-63) repeated 4 more times for each line .
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //bring data in from file.
    indata >> district >> vote;

    //switch case to add vote to corrosponding district
        switch (district)
        {
        case 1:
            if (vote == 'Y')
                d1_vote_y += 1;
            else
                d1_vote_n += 1;
            break;

        case 2:
            if (vote == 'Y')
                d2_vote_y += 1;
            else
                d2_vote_n += 1;
            break;
        case 3:
            if (vote == 'Y')
                d3_vote_y += 1;
            else
                d3_vote_n += 1;
            break;
        default:
            "error";
        }

    //bring data in from file.
    indata >> district >> vote;

    //switch case to add vote to corrosponding district
        switch (district)
        {
        case 1:
            if (vote == 'Y')
                d1_vote_y += 1;
            else
                d1_vote_n += 1;
            break;

        case 2:
            if (vote == 'Y')
                d2_vote_y += 1;
            else
                d2_vote_n += 1;
            break;
        case 3:
            if (vote == 'Y')
                d3_vote_y += 1;
            else
                d3_vote_n += 1;
            break;
        default:
            "error";
        }

    //bring data in from file.
    indata >> district >> vote;

    //switch case to add vote to corrosponding district
        switch (district)
        {
        case 1:
            if (vote == 'Y')
                d1_vote_y += 1;
            else
                d1_vote_n += 1;
            break;

        case 2:
            if (vote == 'Y')
                d2_vote_y += 1;
            else
                d2_vote_n += 1;
            break;
        case 3:
            if (vote == 'Y')
                d3_vote_y += 1;
            else
                d3_vote_n += 1;
            break;
        default:
            "error";
        }

    //bring data in from file.
    indata >> district >> vote;

    //switch case to add vote to corrosponding district
        switch (district)
        {
        case 1:
            if (vote == 'Y')
                d1_vote_y += 1;
            else
                d1_vote_n += 1;
            break;

        case 2:
            if (vote == 'Y')
                d2_vote_y += 1;
            else
                d2_vote_n += 1;
            break;
        case 3:
            if (vote == 'Y')
                d3_vote_y += 1;
            else
                d3_vote_n += 1;
            break;
        default:
            "error";
        }


    //bring data in from file.
    indata >> district >> vote;

    //switch case to add vote to corrosponding district
        switch (district)
        {
        case 1:
            if (vote == 'Y')
                d1_vote_y += 1;
            else
                d1_vote_n += 1;
            break;

        case 2:
            if (vote == 'Y')
                d2_vote_y += 1;
            else
                d2_vote_n += 1;
            break;
        case 3:
            if (vote == 'Y')
                d3_vote_y += 1;
            else
                d3_vote_n += 1;
            break;
        default:
            "error";
        }
    //////////////////////////////////////////////////////////////////////////////////////////////////


    //print out poll statistics.
    cout << "ditrict 1:" << endl;
    cout << "Yes: " << d1_vote_y << endl;
    cout << "No: " << d1_vote_n << endl;
    cout << endl;
    cout << "ditrict 2:" << endl;
    cout << "Yes: " << d2_vote_y << endl;
    cout << "No: " << d2_vote_n << endl;
    cout << endl;
    cout << "ditrict 3:" << endl;
    cout << "Yes: " << d3_vote_y << endl;
    cout << "No: " << d3_vote_n << endl;


    indata.close();

    return 0;

}
