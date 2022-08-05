#ifndef TREE_H
#define TREE_H

//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include "machine.h"
using namespace std;

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
public:
    int Count;
    Machine input;
    Node* Left;
    Node* Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
public:
    // Constructor functions
    BinaryTree();
    ~BinaryTree();

    // General binary tree operations
    bool Search(string UserInput);
    bool Insert(Machine input);
    bool Delete(string UserInput);
    void Print();

private:
    // Helper functions
    void DestroyHelper(Node* Tree);
    bool SearchHelper(string UserInput, Node* Tree);
    bool InsertHelper(Machine input, Node*& Tree);
    bool DeleteNode(Node*& Tree);
    bool DeleteHelper(string UserInput, Node*& Tree);
    void PrintHelper(Node* Tree);

    // Tree pointer
    Node* Root;
};

#endif
