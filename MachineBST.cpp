//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "MachineBST.h"
#include <stdlib.h>

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
    Root = NULL;
}


//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BinaryTree::DestroyHelper(Node* Tree)
{
    // Delete node and it's children
    if (Tree != NULL)
    {
        DestroyHelper(Tree->Left);
        DestroyHelper(Tree->Right);
        delete Tree;
    }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
    // Call tree destroy function
    DestroyHelper(Root);
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string UserInput, Node* Tree)
{
    // Data value not found 
    if (Tree == NULL)
    {
        cout << endl << "!No matching machine found!" << endl << endl;
        return false;
    }

    // Data value found 
    else if (Tree->input.getName() == UserInput)
    {
        cout << Tree->input.getName() << endl << Tree->input.getPublisher() << endl << Tree->input.getType() << endl << Tree->input.getYear() << endl << endl;
        return true;
    }

    // Recursively search for data value
    else if (Tree->input.getName() > UserInput)
        return (SearchHelper(UserInput, Tree->Left));
    else if (Tree->input.getName() < UserInput)
        return (SearchHelper(UserInput, Tree->Right));
    else
        return false;
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(string UserInput)
{
    // Call tree searching function
    return (SearchHelper(UserInput, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(Machine input, Node*& Tree)
{
    // Insert data into the tree
    if (Tree == NULL)
    {
        Tree = new Node;
        Tree->input = input;
        Tree->Count = 1;
        Tree->Left = NULL;
        Tree->Right = NULL;
        return true;
    }

    // Data value already inserted
    else if (Tree->input.getName() == input.getName())
    {
        cout << endl << "!Machine already exists in tree!" << endl << endl;
        Tree->Count++;
        return true;
    }

    // Recursively search for insertion position
    else if (Tree->input.getName() > input.getName())
    {
        return (InsertHelper(input, Tree->Left));
    }
    else if (Tree->input.getName() <= input.getName())
    {
        return (InsertHelper(input, Tree->Right));
    }
    else
        return false;
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(Machine input)
{
    // Call tree insertion function
    return (InsertHelper(input, Root));
}

//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::DeleteNode(Node*& Tree)
{
    Node* Temp = Tree;

    // Node has 0 children
    if ((Tree->Left == NULL) && (Tree->Right == NULL))
        Tree = NULL;

    // Node has 1 child
    else if (Tree->Left == NULL)
        Tree = Tree->Right;
    else if (Tree->Right == NULL)
        Tree = Tree->Left;


    // Node has 2 children
    else
    {
        // Find leftmost node in right subtree
        Node* Parent = Tree;
        Temp = Tree->Right;
        while (Temp->Left != NULL)
        {
            Parent = Temp;
            Temp = Parent->Left;
        }

        // Replace deleted data with leftmost value
        if (Parent == Tree)
            Parent->Right = Temp->Right;
        else
            Parent->Left = Temp->Right;
        Tree->input = Temp->input;
        Tree->Count = Temp->Count;
    }

    // Delete node
    delete Temp;
    return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(string UserInput, Node*& Tree)
{
    // Data value not found
    if (Tree == NULL)
    {
        cout << endl << "!No matching machine found!" << endl << endl;
        return false;
    }

    // Data value found and deleted
    else if (Tree->input.getName() == UserInput)
        return (DeleteNode(Tree));

    // Recursively search for node to delete
    else if (Tree->input.getName() > UserInput)
        return (DeleteHelper(UserInput, Tree->Left));
    else if (Tree->input.getName() < UserInput)
        return (DeleteHelper(UserInput, Tree->Right));
    else
        return false;
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(string UserInput)
{
    // Call tree deletion function
    return (DeleteHelper(UserInput, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node* Tree)
{
    // Check terminating condition
    if (Tree != NULL)
    {
        // Print left subtree
        PrintHelper(Tree->Left);

        // Print node value
        cout << Tree->input.getName() << endl << Tree->input.getPublisher() << endl << Tree->input.getType() << endl << Tree->input.getYear() << endl << endl;

        // Print right subtree
        PrintHelper(Tree->Right);
    }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
    // Call tree printing function
    PrintHelper(Root);
}
