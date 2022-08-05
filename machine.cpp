#include "machine.h"
using namespace std;

Machine::Machine()
{
	Name = "";
	Publisher = "";
	Type = "";
	Year = 0; // Initializes private variables to default.
}

Machine::~Machine()
{
}

// The getters
string Machine::getName()
{
	return Name;
}
string Machine::getPublisher()
{
	return Publisher;
}
int Machine::getYear()
{
	return Year;
}
string Machine::getType()
{
	return Type;
}
// The setters
void Machine::setName(string name)
{
	Name = name;
}
void Machine::setPublisher(string publisher)
{
	Publisher = publisher;
}
void Machine::setYear(int year)
{
	Year = year;
}
void Machine::setType(string type)
{
	Type = type;
}

void Machine::printMachine() //Print all the information in the machine object.
{
	cout << Name << endl << Publisher << endl << Year << endl << Type << endl << endl;
}
