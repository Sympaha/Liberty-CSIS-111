#pragma once
#include <string>
using namespace std;

class StudentType
{
private:

	//instance or class variables
	string firstName;
	string lastName;
	int score;
	char gr;


public:
	//Constructors
	StudentType();
	StudentType(string firstName, string lastName, int score, char gr);

	//Setter
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setTestScore(int score);
	void setGrade(char gr);

	//Getters
	string getFirstName() const;
	string getLastName() const;
	int getTestScore() const;
	char getGrade() const;
};
