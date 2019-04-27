#include "scll.h"

scll::scll() {
	head = NULL;
}

bool scll::addAtBeg(int ele) {
	node *temp, *t1;
	temp = new node;
	temp->data = ele;
	t1 = head;
	if(head == NULL) {
		head = temp;
		temp->next = temp;
	}
	else {
		temp->next = t1;
		while(t1->next != head)
			t1 = t1->next;
		t1->next = temp;
		head = temp;
	}
	return true;
}

bool scll::addAtEnd(int ele) {
	if(head == NULL)
		addAtBeg(ele);
	else {
		node *temp, *t1;
		temp = new node;
		temp->data = ele;
		t1 = head;
		while(t1->next != head)
			t1 = t1->next;
		t1->next = temp;
		temp->next = head; 
	}
	return true;
}

bool scll::addAtPos(int ele, int pos) {
	int c = nodeCount();
	int i = 1;
	if(head == NULL || pos == 1)
		addAtBeg(ele);
	else if(pos == c+1)
		addAtEnd(ele);
	else {		
		node *temp, *t1;
		temp = new node;
		temp->data = ele;
		t1 = head;
		while(++i < pos)
			t1 = t1->next;
		temp->next = t1->next;
		t1->next = temp;
	}
	return true;
}

int scll::deleteAtBeg() {
	node *t1, *t2;
	int temp;
	t1 = head;
	temp = t1->data;
	if(head == NULL)
		cout<<"Nothing to delete."<<endl;
	else {
		while(t1->next != head) {
			t2 = t1;
			t1 = t1->next;
		}
		t1->next = head->next;
		t2 = head;
		head = head->next;
				
	}
	delete t2;
	return temp;
}

int scll::deleteAtEnd() {
	node *t1, *t2;
	int temp;
	t1 = head;
	if(head == NULL)
		cout<<"Nothing to delete."<<endl;
	else {
		while(t1->next != head) {
			t2 = t1;
			t1 = t1->next;
		}
		temp = t1->data;
		t2->next = head;
	}
	delete t1;
	return temp;
}

int scll::deleteAtPos(int pos) {
	int c, i = 1;
	c = nodeCount();
	if(head == NULL)
		cout<<"Nothing to delete."<<endl;
	else {
		if(pos == 1)
			deleteAtBeg();
		else if(pos == c)
			deleteAtEnd();
		else {
			int temp;
			node *t1, *t2;
			t1 = head;
			while(i++ < pos) {
				t2 = t1;
				t1 = t1->next;
			}
			temp = t1->data;
			t2->next = t1->next;
			delete t1;
			return temp;
		}
	}
}

int scll::nodeCount() {
	node *t1;
	t1 = head;
	int count = 0;
	if(head == NULL)
		return count;
	else {
		while(t1->next != head) {
			count++;
			t1 = t1->next;
		}
	}
	return count+1;
}

void scll::display() {
	node *t1;
	t1 = head;
	if(head == NULL) {
		cout<<"Nothing to display"<<endl;
	}
	else {
		while(t1->next != head) {
			cout<<t1->data<<"---> ";
			t1 = t1->next;
		}
		cout<<t1->data<<"---> "<<head->data;
	}
	cout<<"\n";
}
