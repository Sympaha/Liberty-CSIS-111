//Hotel.cpp -- brief statement as to the file�s purpose -- See assignment below.
/*	Assignment Description
	The cost of renting a room at a hotel is, say $100.00 per night. For special occasions,
	such as a wedding or conference, the hotel offers a special discount as follows: If
	the number of rooms booked is at least 10, the discount is 10%; at least 20, the discount
	is 20%; and at least 30, the discount is 30%. Also if rooms are booked for at least three
	days, then there is an additional 5% discount.

	Write a program that
		- loads the cost of renting one room and the sales tax rate
			from an input file (provided),
		- prompts the user to enter the number of rooms booked, and
		- prompts the user to enter the number of days the rooms are booked.

	The program outputs to an output file named (output.dat)
		- the cost of renting one room,
		- the discount on each room as a percent,
		- the number of rooms booked,
		- the number of days the rooms are booked,
		- the total cost of the rooms,
		- the sales tax,
		- and the total billing amount.

	Your program must use appropriate named constants to store special values such as various discounts.
*/

//Include statements

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

//include the standard library file needed to read and write files

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes


int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jimmy Ortiz -- Lab 4 Hotel" << endl << endl;

	//Variable declarations
	double roomRate, taxRate, discountRate, salesTax, totalRoomCost;
	double newTotalRoomCost, newRoomRate, roomDay;
	int roomsBooked, days;
	ifstream Indata;
	ofstream Outdata;

	//Add an ifstream variable to read the input file "input.dat" and open it.
	//Add an ofstream variable to output the final results to output.dat.

	//Program logic
	/*
		Open and read input.dat to get the cost of renting one room
		  and the sales tax rate.
		Prompt the user to provide the following:
		-the number of rooms booked and
		-the number of days the rooms are booked.
	*/
	Indata.open("Input.dat");

	Indata >> roomRate >> salesTax;

	cout << "How many rooms are booked: ";
	cin >> roomsBooked;
	cout << "How many days are they booked ";
	cin >> days;
	cout << endl << endl;
	cout << "You have booked " << roomsBooked << " rooms" << endl;
	cout << "You have booked " << roomsBooked << " rooms" << endl;
	cout << "They have been booked for " << days << " days" << endl << endl;

	// Complete the appropriate calculations
	//   Calculate the discount rate
	if (roomsBooked < 10)
		discountRate = 0.0;
	else if (roomsBooked < 20)
		discountRate = 0.1;		//10% discount
	else if (roomsBooked < 30)
		discountRate = 0.2;		//20% discount
	else
		discountRate = 0.3;		//30% discount

	// Discount rate for 3 or more days
	if (days < 3)
		roomDay = 0.0;
	else if (days >= 3)
		roomDay = 0.05;

	// Calculate totalRoomCost and salesTax
	newRoomRate = roomRate - ((roomRate * discountRate) + (roomRate * roomDay));// Calculates the Discount rate for each room.
	totalRoomCost = (newRoomRate * roomsBooked * days); //Calculates the Total cost for all rooms
	taxRate = totalRoomCost * salesTax; //Calculates the total tax
	newTotalRoomCost = (totalRoomCost + taxRate); // Final Bill

	/*
		Output to output.dat
		- the cost of renting one room,
		- the discount on each room as a percent,
		- the number of rooms booked,
		- the number of days the rooms are booked,
		- the total cost of the rooms,
		- the sales tax,
		- and the total billing amount.
		Your output should look nice and neat
	*/

	Outdata.open("output.dat");

	Outdata << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;
	Outdata << setfill('.') << left << setw(40) << "Renting one room cost" << right << " " << "$" << roomRate << endl << endl;
	Outdata << setfill('.') << left << setw(40) << "Discount on each room" << right << " " << (discountRate + roomDay) * 100 << "%" << endl << endl;
	Outdata << setfill('.') << left << setw(40) << "Number of rooms booked" << right << " " << roomsBooked << endl << endl;
	Outdata << setfill('.') << left << setw(40) << "Days they are booked for" << right << " " << days << endl << endl;
	Outdata << setfill('.') << left << setw(40) << "Total cost of the rooms" << right << " " << "$" << totalRoomCost << endl << endl;
	Outdata << setfill('.') << left << setw(40) << "Sales tax" << setfill(' ') << right << salesTax * 100 << "%" << endl << endl;
	Outdata << setfill('.') << left << setw(40) << "Total billing amount" << right << " " << "$" << newTotalRoomCost << endl;

	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;

	cout << setfill('.') << left << setw(40) << "Renting one room cost" << right << " " << "$" << roomRate << endl << endl;
	cout << setfill('.') << left << setw(40) << "Discount on each room" << right << " " << (discountRate + roomDay) * 100 << "%" << endl << endl;
	cout << setfill('.') << left << setw(40) << "Number of rooms booked" << right << " " << roomsBooked << endl << endl;
	cout << setfill('.') << left << setw(40) << "Days they are booked for" << right << " " << days << endl << endl;
	cout << setfill('.') << left << setw(40) << "Total cost of the rooms" << right << " " << "$" << totalRoomCost << endl << endl;
	cout << setfill('.') << left << setw(40) << "Sales tax" << right << " " << salesTax * 100 << "%" << endl << endl;
	cout << setfill('.') << left << setw(40) << "Total billing amount" << right << " " << "$" << newTotalRoomCost << endl;
	//Closing program statements


	
	return 0;
}

