#include"queue.h"

using namespace std;
	
queue::queue() {
	for(int i=0;i<SIZE;i++)
		arr[i] = 0;
	front = INIT;
	rear = INIT;
}

bool queue::isEmpty() {
	return (front == -1 || front == SIZE);
}

bool queue::isFull() {
	return (rear == SIZE-1);
}
	
bool queue::add(int ele) {
	if(isFull()) {
		cout<<"Queue is Full"<<endl;
		return false;
	}
	else {
		rear++;
		arr[rear] = ele;
		if(front == -1)
			front = 0;
		return true;
	}
}

int queue::del() {
	if(isEmpty()) {
		cout<<"Queue is Empty"<<endl;
		return false;
	}
	else {
		int temp = arr[front];
		arr[front] = 0;
		if(front == rear) {
			front = -1;
			rear = -1;
		}
		else
			front++;
	return temp;
	}
}

void queue::peek() {
	int trear, tfront;
	if(isEmpty())
		cout<<"Nothing to display"<<endl;
	else {
		tfront = arr[0];
		for(int i=0;i<=rear;i++)
			trear = arr[i];
		cout<<tfront<<" is at front"<<endl;
		cout<<trear<<" is at rear"<<endl;
	}
}

void queue::display() {
	if(isEmpty())
		cout<<"Nothing to display"<<endl;
	else {
		cout<<"Queue:"<<endl;
		for(int i=0;i<=SIZE-1;i++)
			cout<<arr[i]<<"\t";
		cout<<endl;
	}
}
