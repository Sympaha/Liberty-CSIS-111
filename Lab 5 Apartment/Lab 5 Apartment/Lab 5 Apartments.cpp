/******************************************************************************
(Apartment problem) A real estate office handles, say, 50 apartment units.
When the rent is, say, $600 per month, all the units are occupied. However,
for each, say, $40 increase in rent, one unit becomes vacant. Moreover, each
occupied unit requires an average of $27 per month for maintenance. How many
units should be rented to maximize the profit?

Write a program that reads the following from an input file (provided)

	The total number of units.

	The rent to occupy all the units.

	The Amount to maintain a rented unit (maintenance fee).

And prompts the user to enter the following:

	The increase in rent that results in a vacant unit.

The program then outputs the number of units to be rented to maximize the profit.
Algorithm:
	while (profit goes up)
	{
		increase the monthly rent
		decrease number of units rented by one
		calculate the profit which is (rent - maintenance fee) * number of units rented
	}
	output the results (remember to back out the last changes made to monthly rent,
	number of units, and profit above -- why do you need to back out the last changes)
		number of units rented
		monthly rent
		total profit

Malik, Ch 6, Programming Exercise 28 (page 345)
******************************************************************************/


//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>



//include any missing standard libraries required to complete the program

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes



int main()
{
	//In cout statement below substitute your name and lab number
	cout << "First Name -- Lab 5" << endl << endl;

	//Variable declarations
	int totalUnits, maxUnits, occupiedUnits;
	double  Rent, maintennaceFee, rentIncrease;
	double maxProfit, currentProfit;
	fstream Indata;

	//Program logic
	Indata.open("Input.dat");

	if (!Indata) //To see if the file was open properly
	{
		cout << " Could not open Input.dat file " << endl << endl;
		exit(1);
	}
	cout << "Input.dat opened successfully" << endl << endl;

	Indata >> totalUnits >> Rent >> maintennaceFee; //Input values from the Input.dat file

	maxProfit = 0; // Giving this declartion a value so they can be used in the program logic in if()

	Indata.close(); //Close the file

	cout << "Enter rent increase: $";
	cin >> rentIncrease; //User Input



	while (totalUnits > 0) // Using while loop till all the units are unoccupied
	{
		currentProfit = (Rent - maintennaceFee) * totalUnits; // Calaculate the current profit
		Rent = rentIncrease + Rent;

		if (currentProfit > maxProfit) // Making the max profit the same as current profit/ max units the same ad total units. Loops though till equal
		{
			maxProfit = currentProfit;
			maxUnits = totalUnits;
		}

		totalUnits = totalUnits - 1; //Takes away from the total unit by 1 each loop

	}

	cout << "Number of units rented: " << maxUnits << endl;
	cout << fixed << setprecision(2);
	cout << "Monthly Rent: $" << Rent << endl;
	cout << "Total Profit: $" << maxProfit << endl;






	//Closing program statements
	return 0;
}

