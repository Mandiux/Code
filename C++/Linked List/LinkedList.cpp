// LinkedList.cpp

#include"LinkedList.h"

namespace linked_list
{
	LinkedList::LinkedList(const LinkedList &source)
	{
		Node *lastAdded = NULL;
		for ( Node *sourcep = source.head
				; sourcep != NULL
				; sourcep = sourcep->next )
		{
			if ( sourcep == source.head )
			{
				head = new Node( sourcep->data, NULL );
				lastAdded = head;
			}
			else
			{
				lastAdded->next = new Node( sourcep->data, NULL );
				lastAdded = lastAdded->next;
			}
			return;

			// alternate ( I prefer over the one above )
			// do first node BEFORE loop
			head = NULL;
			if ( sourcep == NULL ) return;
			head = new Node( sourcep->data, NULL );
			lastAdded = head;
			for ( Node *sourcep = source.head->next
				; sourcep != NULL
				; sourcep = sourcep->next )
			{
				lastAdded->next = new Node( sourcep->data, NULL );
				lastAdded = lastAdded->next;
			}
			return;
			
			// alternate (C-ctyle)
			// in the loop:
			Node **npp = (sourcep == head) ? &head : &(lastAdded->next);
			*npp = new Node( sourcep->data, NULL );
			lastAdded = *npp;

			// alternate (C++ - style)
			// in the loop:
			Node *&npRef = (sourcep == head) ? head : (lastAdded->next);
			npRef = new Node( sourcep->data, NULL );
			lastAdded = npRef;

			// alternate (C++ or C)
			// call a function that takes a pointer or a reference;
		}
	}

	LinkedList::~LinkedList()
	{
		while ( !isEmpty() ) pop();

		// alternate: killList( head );
	}

	void LinkedList::push( Node::value_type value )
	{
		// Node *newNode = new Node;
		// newNode->data = value;
		// newNode->next = head;
		// head = newNode;

		// only one line:
		head = new Node( value, head );
	}

	Node::value_type LinkedList::pop(void)
	{
		if ( isEmpty() )
			// really should throw exception or other error indicator
			return Node::value_type();
		
		Node *firstElement = head;
		head = head->next;
		value_type firstElementValue = firstElement->data;
		delete firstElement;
		return firstElementValue;
	}

	Node::value_type LinkedList::operator[]( size_t index )
	{
		Node *nodep;
		for ( nodep = head
				; index > 0
				; nodep = nodep->next )
			--index;
		return nodep->data;

		for ( Node *nodep = head
				; true
				; nodep = nodep->next )
		{
			if ( index-- == 0 ) return nodep->data;
		}
	}

 	// if ?: operator does not exist
	template<class T>
	T choose( bool b, const T &tv, const T &fv )
	{
		if ( b )
			return tv;
		else
			return fv;
	}

	size_t LinkedList::size2(void)
	{
		size_t count = 0;
		for ( Node *nodep = head
				; nodep != NULL
				; nodep = nodep->next )
			++count;
		return count;
	}

	// inefficient
	size_t LinkedList::size( Node *listHead )
	{
		// recursive
		return ( listHead == NULL )
				? 0
				: 1 + size( listHead->next );
	}
	
	bool LinkedList::isIn( string value )
	{
		// this is O(n)
		for ( Node *nodep = head ; nodep != NULL ; nodep = nodep->next )
			if ( value == nodep->data ) return true;
		return false;

		// this is bad...O(n^2)
		for ( size_t index = 0 ; index < size() ; ++index )
			if ( value == (*this)[index] ) return true;
		return false;
	}

	bool LinkedList::kill( string value )
	{
		return kill( value, head );
	}

	bool LinkedList::kill( string value, node_ptr &np )
	{
		if ( np == NULL ) return false;
		if ( np->data != value )
			return kill( value, np->next );
		Node *target = np;
		np = np->next;
		delete np;
		return true;
	}

	void LinkedList::killList( Node *listHead )
	{
		if ( listHead == NULL ) return;
		killList( listHead->next );
		// killList( (*listHead).next );
		delete listHead;
	}

}