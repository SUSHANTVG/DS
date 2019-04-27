#include "stack.h"

stack::stack() {
	top = INIT;
}

bool stack::isFull() {
	return (top == SIZE-1);
}

bool stack::isEmpty() {
	return (top == -1);
}

bool stack::push(int ele) {
	if(isFull()) {
		cout<<"Stack Overflow"<<endl;
		return false;
	}
	else {
		top++;
		arr[top] = ele;
	}
	return true;
}

int stack::pop() {
	int temp;
	if(isEmpty()) {
		cout<<"Stack Underflow"<<endl;
		return false;
	}
	else {
		temp = arr[top];
		top--;
	}
	return temp;
}

int stack::peek() {
	int temp;
	if(isEmpty()) {
		cout<<"Stack Underflow"<<endl;
		return false;
	}
	else {
		temp = arr[top];
	}
	return temp;
}

void stack::display() {
	if(isEmpty())
		cout<<"Nothing to display"<<endl;
	else {
		cout<<"Stack:"<<endl;
		for(int i=top;i>=0;i--)
			cout<<arr[i]<<"\t";
		cout<<endl;
	}
}
