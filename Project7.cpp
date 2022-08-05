// Jordan_Lyle_Project_7_PF2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "machine.h"
#include "MachineBST.h"

bool read_file_BST(BinaryTree &tree)
{
	cout << "Enter filename: ";
	string filename = "";
	cin >> filename; // Takes the name of the file to be read.

	ifstream din;
	string Name, Publisher, Type;
	Machine machineInputer;
	int Year;
	din.open(filename.c_str());
	if (din.fail()) // Decides to continue commands only if the file can be opened.
	{
		cout << "Error: could not open file" << endl;
		return 1;
	}
	else
	{
		while (!din.eof()) // Repeats until the file is done.
		{
			getline(din, Name, ',');
			getline(din, Publisher, ',');
			din >> Year;
			getline(din, Type);
			Type = Type.erase(0, 1);
			// Gets all of the info from the file and stores it in the Machine object.
			machineInputer.setName(Name);
			machineInputer.setPublisher(Publisher);
			machineInputer.setType(Type);
			machineInputer.setYear(Year);
			// Stores machine object into tree
			tree.Insert(machineInputer);
		}
	}
	return 0;
}

bool readFile()
{
	cout << "Enter filename: ";
	string filename = "";
	cin >> filename; // Takes the name of the file to be read.

	ifstream din;
	string Name, Publisher, Type;
	int Year;
	din.open(filename.c_str());
	if (din.fail()) // Decides to continue commands only if the file can be opened.
	{
		cout << "Error: could not open file" << endl;
		return 1;
	}
	else
	{
		while (!din.eof()) // Repeats until the file is done.
		{
			getline(din, Name, ',');
			getline(din, Publisher, ','); // Gets all of the info from the file and stores it in the Machine object.
			din >> Year;
			getline(din, Type);
			Type = Type.erase(0, 1);
			cout << Name << endl << Publisher << endl << Year << endl << Type << endl << endl;
		}
	}
	return 0;
}

int main()
{
	BinaryTree tree; // The Binary Search Tree
	int selection;
	int i = 0;
	while (i == 0) // Loops the switch selection menu
	{
		cout << "What would you like to do?";
		cout << endl << "1: Initialize the program";
		cout << endl << "2: Search the binary tree for a machine";
		cout << endl << "3: Insert a machine into the binary tree";
		cout << endl << "4: Delete a machine from the tree";
		cout << endl << "5: Print everything in the tree";
		cout << endl << "6: Quit";
		cout << endl << "Selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1:
		{
			read_file_BST(tree); // Reads in information from file to a Machine object and inserts it into tree
			cout << endl;
			break;
		}
		case 2:
		{
			string NameOfMachine;
			cout << endl << "What is the name of the machine you are searching for?: ";
			cin.clear();
			cin.ignore();
			getline(cin, NameOfMachine);
			tree.Search(NameOfMachine); // Searches tree and prints information of Machine object if name matches any of the object's names
			break;
		}
		case 3:
		{
			Machine UserInsert;
			string NameOfMachine, PublisherOfMachine, TypeOfMachine;
			int YearOfMachine;
			cout << endl << "What is the name of the machine?: ";
			cin.clear();
			cin.ignore();
			getline(cin, NameOfMachine);
			cout << endl << "Who is the publisher of the machine?: ";
			getline(cin, PublisherOfMachine);
			cout << endl << "What type of machine is it?: ";
			getline(cin, TypeOfMachine);
			cout << endl << "When was the machine made?: ";
			cin >> YearOfMachine;
			// Putting all data into machine object
			UserInsert.setName(NameOfMachine);
			UserInsert.setPublisher(PublisherOfMachine);
			UserInsert.setType(TypeOfMachine);
			UserInsert.setYear(YearOfMachine);
			tree.Insert(UserInsert); // Inserts machine object into tree if getName() doesn't match any of the object's names
			break;
		}
		case 4:
		{
			string NameOfMachine;
			cout << endl << "What is the name of the machine you would like to delete?: ";
			cin.clear();
			cin.ignore();
			getline(cin, NameOfMachine);
			tree.Delete(NameOfMachine); // Deletes machine object with the given name if it is found in the tree
			break;
		}
		case 5:
		{
			tree.Print(); // Prints everything in the tree in order by name
			break;
		}
		default:
		{
			i = 1; // Every other selection ends the program
			break;
		}
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
