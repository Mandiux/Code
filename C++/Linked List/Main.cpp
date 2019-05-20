// Main.cpp
// Armando Fernandez.
// The purpose of this program was to create linked list. HW assignment.

#include"LinkedList.h"
#include"Tools.h"
using namespace tools;
#include<iostream>
using namespace std;
using namespace linked_list;

void printList(Node *np);

void firstFunction(void);

int main(void)
{
	LinkedList list;
	while (true)
	{
		string userInput = getLine("Enter a string or ENTER to quit: ");
		if ( userInput == "" ) break;
		list.push( userInput );
	}

	while ( list.size() > 0 )
	{
		cout << list.pop() << endl;
	}

	cout << endl;
	pause("Press ENTER to finish...");
	return 0;
}

void firstFunction(void)
{
	Node *head = new Node("hi",NULL);

	// inserting a node using constructor
	head = new Node("hi2",head);

	// inserting a node without explicit constructors (the "C" way)
	{
		Node *newNode = new Node;
		newNode->data = "hi3";
		newNode->next = head;
		head = newNode;
	}
	
	// traversing a list in a language that thinks for-loops
	// are only for numbers
	{
		Node *nodep = head;
		while (  nodep != NULL  )
		{
			cout << nodep->data << endl;
			nodep = nodep->next;
		}
	}

	// traversing a list in a language that has a generalized for-loop
	for ( Node *nodep = head ; nodep != NULL ; nodep = nodep->next )
		cout << nodep->data << endl;

	// traversing a list recursively
	printList(head);
}

void printList(Node *np)
{
	if ( np == NULL ) return;
	cout << np->data << endl;	// "head"
	printList( np->next );		// "tail"
}

