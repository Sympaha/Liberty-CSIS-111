/*
The cost to become a member of a fitness center is as follows:
	(a) the senior citizens monthly membership discount is 30%;
	(b) the discount for chosing to prepay the annual membership cost is 15%; and
	(c) if more than five personal training sessions are bought and paid for, the discount on each session is 20% (the discounts in a and b above do not apply to personal
	training).

Write a menu-driven program that determines the annual cost of a new membership. Your program must contain
	a function that displays the general information about the fitness center and its charges,
	a function to get all of the necessary information to determine the membership cost, and (use pass-by-reference parameters)
	a function to determine the membership cost.

Use appropriate parameters to pass information in and out of a function. (Do not use any global variables.)

Malik, Ch 6, Programming Exercise 25 (page 463)

*/

//Include statements
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const float MONTHLY_MEMBERSHIP_RATE = 25.00;
const float PERSONAL_SESSION_RATE = 50.00;

//Function prototypes
double math(float, float, bool, int, int);
void getInfo(bool& Senior, int& prePaid, int& trainingSessions);
void Display();


int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jimmy Ortiz -- Lab 6 Fitness" << endl << endl;

	//Variable declarations
	bool Senior{};
	int trainingSessions{}, prePaid{};
	double seniorDiscount{}, prePaidDiscount{}, trainingDiscount{}, costMemberShip{};

	//Program logic
	Display();
	getInfo(Senior, prePaid, trainingSessions);
	costMemberShip = math(MONTHLY_MEMBERSHIP_RATE, PERSONAL_SESSION_RATE, Senior, trainingSessions, prePaid);

	cout << endl;

	cout << "Cost of the Membership: $" << setprecision(2) << fixed << costMemberShip << endl << endl;



	//Closing program statements
	 	return 0;
}

void Display()
{
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_ SPARTIN GYM BROs *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;

	cout << "                            " << "Welcome to Spartin Gym Bros gym!" << endl << endl;
	cout << "We are here to get you in shape! We are dedicated to getting you where you need and want to be." << endl;
	cout << "We will grind till we run out of time. Remember pain is just weakness leaving the body!" << endl << endl;

	cout << "Our monthly rates are $25.00 and Personal Training Rate $50.00, but we do offer discounts:" << endl;
	cout << "            " << "a) Senior Citizents(65 and older) " << right << setw(30) << setfill('.') << " 30% off" << endl;
	cout << "            " << "b) Prepaid annual member ship " << right << setw(34) << setfill('.') << " 15% off" << endl;
	cout << "            " << "c) Prepaid Trainning lessions (5 or more) " << right << setw(27) << setfill('.') << " 20% off each" << endl << endl << endl;

}
void getInfo(bool& Senior, int& prePaid, int& trainingSessions)
{
	char serInput;
	cout << "Are you a senior citizen that is 65 or older? Enter 'Y' or 'N': ";
	cin >> serInput;

	if (serInput == 'Y' || serInput == 'y')
	{
		Senior = true;
		cout << endl;
	}
	else
	{
		Senior = false;
		cout << endl;
	}
	char prePaidInput;
	int prePaidIn;
	cout << "Do you plan on Prepaying? Enter 'Y' or 'N': ";
	cin >> prePaidInput;

	if (prePaidInput == 'Y' || prePaidInput == 'y')
	{
		prePaid = 12;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "How many months do you want to pay for? Enter here: ";
		cin >> prePaidIn;

		prePaid = prePaidIn;
		cout << endl;
	}


	int trainningSessionsInput;
	cout << "How many training sessions do you wish to pay for? Enter your amount: ";
	cin >> trainningSessionsInput;

	trainingSessions = trainningSessionsInput;
	cout << endl;

}
double math(float MONTHLY_MEMBERSHIP_RATE, float PERSONAL_SESSION_RATE, bool Senior, int trainingSessions, int prePaid)
{

	double costMemberShip = MONTHLY_MEMBERSHIP_RATE * prePaid;

	if (Senior)
	{
		costMemberShip = costMemberShip - (MONTHLY_MEMBERSHIP_RATE * 0.30 * prePaid);
	}

	if (prePaid >= 12)
	{
		costMemberShip = costMemberShip - (MONTHLY_MEMBERSHIP_RATE * 0.15 * prePaid);
	}

	costMemberShip = costMemberShip + (PERSONAL_SESSION_RATE * trainingSessions);

	if (trainingSessions > 5)
	{
		costMemberShip = costMemberShip - (PERSONAL_SESSION_RATE * 0.20 * trainingSessions);
	}


	return costMemberShip;
}


