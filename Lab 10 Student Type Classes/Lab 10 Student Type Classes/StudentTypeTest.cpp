//StudentTypeTest.cpp -- driver used to test StudentType implementation.
//CSIS 111-003
//<Sources if necessary>
//https://www.w3schools.com/cpp/cpp_class_methods.asp
//https://stackoverflow.com/questions/16827532/c-student-class-with-set-and-get-functions

//Include statements
#include <iostream>
#include <string>
#include "StudentType.h"

using namespace std;

//Global declarations: Constants and type definitions only -- no variables



int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jimmy Ortiz -- Lab 10" << endl << endl;

	//Variable declarations
	StudentType s;	//declare your StudentType variable

	//Program logic -- set your StudentType instance variables using your set functions
	// then display your student data using you StudentType get functions.
	s.setFirstName("Jimmy");
	s.setLastName("Ortiz");
	s.setTestScore(100);
	s.setGrade('A');

	cout << "First Name: " << s.getFirstName() << endl << endl;
	cout << "Last Name: " << s.getLastName() << endl << endl;
	cout << "Score: " << s.getTestScore() << endl << endl;
	cout << "Grade: " << s.getGrade() << endl << endl;

	//Closing program statements
		return 0;
}

