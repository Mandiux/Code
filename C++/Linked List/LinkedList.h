// LinkedList.h

#include<string>
using namespace std;

#ifndef LINKEDLIST
#define LINKEDLIST

namespace linked_list
{
	class Node
	{
	public:
		typedef string value_type;
		Node( string i_data = "", Node *i_next = NULL )
			: data(i_data), next(i_next)
		{}
		value_type data;
		Node *next;
	};

	class LinkedList
	{
	public:
		typedef Node::value_type value_type;
		typedef Node *node_ptr;

		LinkedList(void) : head(NULL) {}
		LinkedList(const LinkedList &source);
		~LinkedList();

		void push( Node::value_type value );
		Node::value_type pop(void);

		Node::value_type operator[]( size_t index );

		bool isIn( string value );
		bool kill( string value );

		bool isEmpty(void) { return head == NULL; }
		size_t size(void) { return size( head ); }
		size_t size2(void);

	private:
		Node *head;

		bool kill( string value, node_ptr &np );

		void killList( Node *listHead );
		size_t size( Node *listHead );
	};
}

#endif