#ifndef DLL
#define DLL

#include<iostream>
#include<cstdlib>

using namespace std;

struct node {
	int data;
	node *next;
	node *prev;
};

class dll {
	private:
		node *head;
	public:
		dll();

		bool addAtBeg(int);
		bool addAtEnd(int);
		bool addBeforePos(int, int);
		bool addAfterPos(int, int);

		int deleteAtBeg();
		int deleteBeforePos(int);
		int deleteAfterPos(int);
		int deleteAtEnd();

		int nodeCount();

		void display();
};

#endif
