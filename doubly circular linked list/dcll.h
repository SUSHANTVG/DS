#ifndef DCLL
#define DCLL

#include<iostream>
#include<cstdlib>

using namespace std;

struct node {
	int data;
	node *next;
	node *prev;
};

class dcll {
	private:
		node *head;
	public:
		dcll();
		
		bool addAtBeg(int);
		bool addBeforePos(int, int);
		bool addAfterPos(int, int);
		bool addAtEnd(int);
		
		int deleteAtBeg();
		int deleteBeforePos(int);
		int deleteAfterPos(int);
		int deleteAtEnd();
		
		int nodeCount();
		
		void display();
};

#endif