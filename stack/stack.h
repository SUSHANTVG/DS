#ifndef STACK
#define STACK

#include<iostream>
#include<cstdlib>
#define SIZE 5
#define INIT -1

using namespace std;

class stack {
	private:
		int arr[SIZE];
		int top;
	public:
		stack();
		bool push(int);
		int pop();
		bool isFull();
		bool isEmpty();
		int peek();
		void display();
};

#endif
