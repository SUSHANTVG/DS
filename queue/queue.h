#ifndef QUEUE
#define QUEUE

#include<iostream>
#include<cstdlib>
#define SIZE 5
#define INIT -1

using namespace std;

class queue {
	private :
		 int arr[SIZE];
		 int front;
		 int rear;
	public :
		queue();
		bool isFull();
		bool isEmpty();
		bool add(int);
		int del();
		//int peek();
		void display();
};

#endif
