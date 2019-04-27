#ifndef link
#define link

#include<iostream>
#include<cstdlib>

using namespace std;

struct node {
	int data;
	struct node *next;
};

class ll {
	private:
		struct node *head;
	public:
		ll();
		bool insertAtBeg(int);
		bool insertAtEnd(int);
		bool insertAtPos(int, int);
		int deleteAtBeg();
		int deleteAtEnd();
		int deleteAtPos(int);
		void display();
};

#endif
