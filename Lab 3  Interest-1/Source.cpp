/* Interest.cpp -- See assignment instructions below for the purpose of this assignment.

Interest on a credit card's unpaid balance is calculated using the average daily balance.
Suppose that netBalance is the balance shown in the bill, payment is the payment made,
d1 is the number of days in the billing cycle, and d2 is the number of days payment is
made before billing cycle. Then, the average daily balance is:

	averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

If the interest rate per month is, say, 0.0152, then the interest on the unpaid balance is:

	interest = averageDailyBalance * 0.0152;

Write a program that accepts as input netBalance, payment, d1, d2, and interest rate per
month from the provided input file "input.dat". Place input.dat in the same directory as
your .cpp file when you create your Visual Studios project.

The program outputs the interest.

Format your output to two decimal places.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes


int main()
{
	cout << "First Name -- Lab 3 Interest" << endl << endl;
	//Variables
	double netBalance, payment, interestRatePerMonth, averageDailyBalance, interest;
	float newInterest;
	int d1, d2;
	ifstream in;

	//Open the input file using in.open()
	in.open("input.dat");
	

	//Get input for netBalance, payment, d1, d2, and interest rate per month using "in"
	//variable.
	in >> netBalance;
	in >> payment;
	in >> d1;
	in >> d2;
	in >> interestRatePerMonth;
	
	//Calculate averageDailyBalance using the formula in the heading above
	averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

	//Calculate interest using the formula in the heading above
	interest = averageDailyBalance * 0.0152;
	newInterest = ceil(interest * 100.0) / 100.0;

	//Output the interest formatted to two decimal places
	//	Formatting cout
	//	cout "The interest is $##.##" replacing ##.## with the actual interest calculated

	cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*"
		<< "_*_*_*_*_*_*" << endl;
	cout << setfill ('.') << left << setw(35) << "The Net Balance: " << right << " " << "$" << netBalance << endl << endl;
	cout << setfill('.') << left << setw(35) << "Payment: " << right << " " << "$" << payment << endl << endl;
	cout << setfill('.') << left << setw(35) << "Days in billing cycle: " << right << " " << d1 << " Days" << endl << endl;
	cout << setfill('.') << left << setw(35) << "Days before billing cycle: " << right << " " << d2 << " Days" << endl << endl;
	cout << setfill('.') << left << setw(35) << "Interest Rate Per Month: " << right << " " << interestRatePerMonth << endl << endl;
	cout << setfill('.') << left << setw(35) << "The interest is " << right << " " << "$" << newInterest << endl;
	
		//Close the program
	return 0;
}