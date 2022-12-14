//car_range.cpp -- Write a program that prompts the capacity, in gallons, of an automobile fuel tank 
//	and the miles per gallon the automobile can be driven. The program outputs the number of miles 
//	the automobile can be driven without refueling.
//CSIS 111-003
//Sources: My Mind :). Very Simple!


//Include statements
#include <iostream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes


int main()
{
	//In cout statement below substitute your name and lab number
	cout << "<First Name -- Lab 2" << endl << endl;

	//Variable declarations
	int tankCapacity;
	int milesPerGallon;
	int range;

	//Program logic
	//	Prompt user for tank capacity and miles per gallon
	cout << "Enter The Tank Capacity " << endl;
	cin >> tankCapacity;

	cout << "Enter the Miles per Gallon " << endl;
	cin >> milesPerGallon;

	//	Calculate the car's range and assign it to the variable range
	range = tankCapacity * milesPerGallon;
	//	Output the cars range as well as what the user entered.
	cout << "Your Tank Capacity is " << tankCapacity << " Gallons." << endl << endl;
	cout << "Your Miles per gallon is " << milesPerGallon << " MPG." << endl << endl;
	cout << "So your range is " << range << " Miles." << endl;

	//Closing program statements
	
	return 0;
}