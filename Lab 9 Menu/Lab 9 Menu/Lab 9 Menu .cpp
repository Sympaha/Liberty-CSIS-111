/*
	Write a program to help a local restaurant automate its breakfast billing system. The program should do the following:

	1. Show the customer the different breakfast items offered by the restaurant.

	2. Allow the customer to select more than one item from the menu.

	3. Calculate and print the bill.

	Use an array menuList of type MenuItemType. MenuItemType consists of three components:
		menuItem of type string,
		menuPrice of type double, and
		isOrdered of type bool.

	Your program must contain at least the following functions:

	1. Function getData: This function loads the data into the array menuList from the file menu.txt.

	2. Function showMenu: This function shows the different items offered by the restaurant and tells the user how to select the items.

	3. Function printCheck: This function calculates and prints the check. (Note that the billing amount should include a 5% tax.)

	Format your output with two decimal places. The name of each item in the output must be left justified. You may assume that the user
	selects only one item of a particular type.

	Algorithm:

		main
		{
			GetData
			do {
				showMenu
			} while not done
			printCheck
		}
*/

//Include statements
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;



struct menuItemType
{
	// Declaring variables
	string menuItem;
	double menuPrice;
	int qwe;
	// Assigning default values to variables
	menuItemType()
	{
		menuItem = "";
		menuPrice = 0.0;
		qwe = 0;
	}
};

//Global declarations: Constants and type definitions only -- no variables



//Function prototypes
void getData(ifstream& dataIn, menuItemType menuList[], int& count);
void showMenu(menuItemType menuList[], int x);
void printCheck(menuItemType menuList[]);




int main()
{
	//cout statement below substitute your name and lab number
	cout << "Jimmy Ortiz -- Lab 9" << endl << endl;

	//setting the precision to two decimal places
	std::cout << std::setprecision(2) << std::fixed;

	//Variables
	int menuItems = 0;
	int orderChoice = 0;
	bool isOrdering = true;
	int count = 0;

	//Creating a struct array
	menuItemType menuList[100];

	//Opening menu file.
	ifstream dataIn;
	dataIn.open("menu.txt");

	//checking whether the file name is valid or not
	if (dataIn.fail())
	{
		cout << "Cannot open the input file!" << endl;
		exit(0);

	}

	else
	{
		//Calls getData and showMenu Functions
		getData(dataIn, menuList, menuItems);
		showMenu(menuList, menuItems);
		while (isOrdering)
		{
			//Ordering food
			cout << "Please enter the number for the item you would "
				<< "like to order, or enter [0] to complete your order." << endl;
			cin >> orderChoice;

			//Food ordering getting processed
			if ((orderChoice > 0 && orderChoice <= menuItems) && menuList[orderChoice - 1].qwe > 0)
			{
				++menuList[orderChoice - 1].qwe;

			}
			else if (orderChoice > 0 && orderChoice <= menuItems)
			{
				++menuList[orderChoice - 1].qwe;
			}
			else
			{

				isOrdering = false;
			}

		}

		//Calls printCheck function
		printCheck(menuList);
	}

	
	return 0;
}

//Functions
void getData(ifstream& dataIn, menuItemType menuList[], int& count)
{
	//Variables
	string name, str;

	//Reading the data from the file
	while (getline(dataIn, name))
	{
		menuList[count].menuItem = name;
		getline(dataIn, str);
		menuList[count].menuPrice = atof(str.c_str());
		count++;
	}

	//Closing file
	dataIn.close();

}

void showMenu(menuItemType menuList[], int x)
{
	//Variables
	int count;

	//Title display
	cout << "Welcome to Hoppy's Restaurant !" << endl;
	cout << "What would you like to order?" << endl;

	//Menu Display
	for (count = 0; count < x; count++)
	{
		cout << setw(2) << left << "[" << count + 1 << "]";
		cout << setw(30) << left << menuList[count].menuItem << '$'
			<< menuList[count].menuPrice << endl;
	}
}

void printCheck(menuItemType menuList[])
{
	//Variables
	double checkTotal = 0;
	double checkTax = 0;
	const double TAX = .05;
	
	//Title of the Bill
	cout << "Welcome to Hoppy's Restaurant !" << endl << endl;

	//Displaying What was ordered
	for (int i = 0; i < 8; i++)
	{
		if (menuList[i].qwe != 0)
		{
			cout << setw(5) << left << menuList[i].qwe << setw(20) << left << menuList[i].menuItem
				<< '$' << menuList[i].menuPrice * menuList[i].qwe << endl;
			checkTotal += (menuList[i].menuPrice * menuList[i].qwe);
		}

	}

	//Calculating everythnig in the bill
	checkTax = checkTotal * TAX;
	checkTotal += checkTax;

	//Displaying the total
	cout << setw(15) << left << " Tax " << setw(11) << right << "$" << checkTax << endl;
	cout << setw(14) << left << " Amount Due " << setw(11) << right << "$" << checkTotal << endl;
	system("pause");
}



