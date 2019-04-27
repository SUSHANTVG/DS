#include "dll.h"

dll::dll() {
	head = NULL;
}

bool dll::addAtBeg(int ele) {
	node *temp, *t1;
	temp = new node;
	temp->data = ele;
	temp->prev = NULL;
	t1 = head;
	if(head == NULL)
		temp->next = NULL;
	else {
		temp->next = t1;
		t1->prev = temp;
	}
	head = temp;
	return true;
}

bool dll::addBeforePos(int ele, int pos) {
	int i = 1;
	if(head == NULL || pos == 1)
		addAtBeg(ele);
	else {	
		node *temp, *t1;
		temp = new node;
		temp->data = ele;
		t1 = head;
		while(++i < pos)
			t1 = t1->next;
		temp->prev = t1;
		temp->next = t1->next;
		(t1->next)->prev = temp;
		t1->next = temp;
	}
	return true;
}

bool dll::addAfterPos(int ele, int pos) {
	int i = 1;
	if(head == NULL || pos == 1)
		addAtEnd(ele);
	else {
		node *temp, *t1;
		temp = new node;
		temp->data = ele;
		t1 = head;
		while(i++ < pos)
			t1 = t1->next;
		temp->prev = t1;
		temp->next = t1->next;
		t1->next = temp;
		(t1->next)->prev = temp;
	}
	return true;
}

bool dll::addAtEnd(int ele) {
	node *temp, *t1;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	t1= head;
	if(head == NULL) {
		temp->prev = NULL;
		head = temp;
	}
	else {
		while(t1->next != NULL)
			t1 = t1->next;
		t1->next = temp;
		temp->prev = t1;
	}
	return true;
}

int dll::deleteAtBeg() {
	node *t1;
	t1 = head;
	int temp;
	if(head == NULL)
		cout<<"Nothing to delete!"<<endl;
	else if(t1->next == NULL && t1->prev == NULL) {
		temp = t1->data;
		head = NULL;
	}
	else {
		temp = t1->data;
		(t1->next)->prev = NULL;
		head = t1->next;
	}
	delete t1;
	return temp;
}

int dll::deleteBeforePos(int pos) {
	int i = 1;
	if(head == NULL) {
		cout<<"Nothing to delete!"<<endl;
		return 0;
	}
	else {
		if(pos == 1) {
			cout<<"Can't delete #0 node."<<endl;
			return 0;
		}
		else if(pos == 2)
			deleteAtBeg();
		else {
			node *t1, *t2;
			t1 = head;
			int temp;
			while(++i < pos) {
				t2 = t1;
				t1 = t1->next;
			}
			temp = t1->data;
			t2->next = t1->next;
			(t1->next)->prev = t2;
			delete t1;
			return temp;
		}
	}
}

int dll::deleteAfterPos(int pos) {
	int i = 1;
	int c = nodeCount();
	if(head == NULL) {
		cout<<"Nothing to delete!"<<endl;
		return 0;
	}
	else if(pos == c-1)
		deleteAtEnd();
	else {
		if(pos >= c) {
			cout<<"Can't delete #"<<c+1<<" element"<<endl;
			return 0;
		}
		node *t1, *t2;
		t1 = head;
		int temp;
		while(i++ <= pos) {
			t2 = t1;
			t1 = t1->next;
		}
		temp = t1->data;
		t2->next = t1->next;
		(t1->next)->prev = t2;
		delete t1;
		return temp;
	}
}

int dll::deleteAtEnd() {
	node *t1, *t2;
	t1 = head;
	int temp;
	if(head == NULL)
		cout<<"Nothing to delete!"<<endl;
	else if(t1->prev == NULL && t1->next == NULL) {
		temp = t1->data;
		head = NULL;
		
	}
	else {
		while(t1->next != NULL) {
			t2 = t1;
			t1 = t1->next;
		}
		temp = t1->data;
		t2->next = NULL;
	}
	delete t1;
	return temp;
}

int dll::nodeCount() {
	node *t1;
	t1 = head;
	int count = 0;
	while(t1 != NULL) {
		count++;
		t1 = t1->next;
	}
	return count;
}

void dll::display() {
	node *t1;
	t1 = head;
	if(head == NULL)
		cout<<"Nothing's here!"<<endl;
	cout<<"\n";
	while(t1 != NULL) {
		cout<<t1->data<<"<---> ";
		t1 = t1->next;
	}
	cout<<"\n";
}
