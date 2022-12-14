/*Lab 7 Planets -- Write a C++ program that asks the user to enter his or her weight and the name of a planet using functions, a switch statement, 
and enum types for planets.The following table gives the factor by which the weight must be multiplied for each planet.The program should output an error
message if the user doesn�t input a correct planet name.The prompt and the error message should make it clear to the user how a planet name must be entered.Be sure to use proper
formatting and appropriate comments in your code. The output should be labeled clearlyand formatted neatly.*/
//CSIS 111-003
//<Sources if necessary>


//Include statements
#include <iostream>
#include <string>

using namespace std;

enum PlanetType
{
	Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto
};

//Function prototypes
double calWeight(PlanetType, double);
bool Planets(string, PlanetType&);


int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jimmy Ortiz -- Lab 7 Planets" << endl << endl;

	//Variable declarations
	double weight, weightOnPlanet;
	string planetName;
	PlanetType planet;

	//Program logic
	cout << "What is your weight on earth?: ";
		cin >> weight;
		cout << endl;

		do {
			cout << "Capitalize the first letter!" << endl << endl;
			cout << "Enter Planet name: ";
			cin >> planetName;
		} while (!Planets(planetName, planet));

		

		weightOnPlanet = calWeight(planet, weight);

		cout << "Weight on " << planetName << " is " << weightOnPlanet << endl;


	//Closing program statements
	
	return 0;
}

bool Planets(string planetName, PlanetType &planet)
{
	if (planetName == "Mercury")
	{
		planet = Mercury;
		return true;
	}
	else if (planetName == "Venus")
	{
		planet = Venus;
		return true;
	}
	else if (planetName == "Earth")
	{
		planet = Earth;
		return true;
	}
	else if (planetName == "Moon")
	{
		planet = Moon;
		return true;
	}
	else if (planetName == "Mars")
	{
		planet = Mars;
		return true;
	}
	else if (planetName == "Jupiter")
	{
		planet = Jupiter;
		return true;
	}
	else if (planetName == "Saturn")
	{
		planet = Saturn;
		return true;
	}
	else if (planetName == "Uranus")
	{
		planet = Uranus;
		return true;
	}
	else if (planetName == "Neptune")
	{
		planet = Neptune;
		return true;
	}
	else if (planetName == "Pluto")
	{
		planet = Pluto;
		return true;
	}
	return false;
}
double calWeight(PlanetType planet, double weight)
{
	double weightOnPlanet;

	switch (planet)
	{
	case Mercury: weightOnPlanet = weight * 0.4155; break;
	case Venus: weightOnPlanet = weight * 0.8975; break;
	case Earth: weightOnPlanet = weight * 1.0; break;
	case Moon: weightOnPlanet = weight * 0.166; break;
	case Mars: weightOnPlanet = weight * 0.3507; break;
	case Jupiter: weightOnPlanet = weight * 2.5374; break;
	case Saturn: weightOnPlanet = weight * 1.0677; break;
	case Uranus: weightOnPlanet = weight * 0.8947; break;
	case Neptune: weightOnPlanet = weight * 1.1794; break;
	case Pluto: weightOnPlanet = weight * 0.0899; break;
		
	}
	return weightOnPlanet;
}

