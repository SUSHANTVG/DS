#ifndef sclink
#define sclink

#include<iostream>
#include<cstdlib>

using namespace std;

struct node {
	int data;
	struct node *next;
};

class scll {
	private:
		struct node *head;
	public:
		scll();
		bool addAtBeg(int);
		bool addAtEnd(int);
		bool addAtPos(int, int);
		int deleteAtBeg();
		int deleteAtEnd();
		int deleteAtPos(int);
		int nodeCount();
		void display();
};

#endif
