#//-----------------------------------------------------------
// Purpose: Header file for the Table class.
//          This class is designed to store an array of Person
//          objects that describe a group of famous people.
//          The search methods locate and print information
//          about a specified subset of the famous people.
// Author:  Jordan Lyle
//-----------------------------------------------------------
#ifndef Machine_H
#define Machine_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Machine
{
public:
	// Constructor methods
	Machine();
	~Machine();

	// Input output methods
	void printMachine();

	// Get and Set methods
	string getName();
	string getPublisher();
	string getType();
	int getYear();

	void setName(string name);
	void setPublisher(string publisher);
	void setType(string type);
	void setYear(int year);

private:
	// Object attributes
	string Name;
	string Publisher;
	string Type;
	int Year;
};
#endif

