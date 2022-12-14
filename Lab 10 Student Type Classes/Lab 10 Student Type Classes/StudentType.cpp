#include "StudentType.h"

//Setter definitions
void StudentType::setFirstName(std::string Name)
{
	firstName = Name;
}

void StudentType::setLastName(std::string Name)
{
	lastName = Name;
}

void StudentType::setTestScore(int sscore)
{
	score = sscore;
}

void StudentType::setGrade(char sgr)
{
	gr = sgr;
}

//Constuctors
StudentType::StudentType(std::string firstName, std::string lastName, int score, char gr)
{
	setFirstName(firstName);
	setLastName(lastName);
	setTestScore(score);
	setGrade(gr);
}

StudentType::StudentType()
{
	setFirstName(firstName);
	setLastName(lastName);
	setTestScore(score);
	setGrade(gr);
}

//Getters
std::string StudentType::getFirstName() const
{
	return firstName;
}
std::string StudentType::getLastName() const
{
	return lastName;
}
int StudentType::getTestScore() const
{
	return score;
}
char StudentType::getGrade() const
{
	return gr;
}

