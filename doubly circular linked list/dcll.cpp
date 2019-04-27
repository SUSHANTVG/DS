#include "dcll.h"

dcll::dcll() {
	head = NULL;
}

bool dcll::addAtBeg(int ele) {
	node *temp, *t1;
	t1 = head;
	temp = new node;
	temp->data = ele;
	if(head == NULL) {
		temp->next = temp;
		temp->prev = temp;
	}
	else {
		temp->next = t1;
		t1->prev = temp;
		while(t1->next!=head)
			t1 = t1->next;
		t1->next = temp;
		temp->prev = t1;
	}
	head = temp;
	return true;
}

bool dcll::addBeforePos(int ele, int pos) {
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

bool dcll::addAfterPos(int ele, int pos) {
	int i = 1;
	if(head == NULL)
		addAtBeg(ele);
	else {
		node *temp, *t1;
		temp = new node;
		temp->data = ele;
		t1 = head;
		while(i++ < pos)
			t1 = t1->next;
		temp->prev = t1;
		temp->next = t1->next;
		(t1->next)->prev = temp;
		t1->next = temp;
	}
	return true;
}

bool dcll::addAtEnd(int ele) {
	if(head == NULL)
		addAtBeg(ele);
	else {
		node *temp, *t1;
		t1 = head;
		temp = new node;
		temp->data = ele;
		temp->next = t1;
		t1->prev = temp;
		while(t1->next!=head)
			t1 = t1->next;
		t1->next = temp;
		temp->prev = t1;
	}
	return true;
}

int dcll::deleteAtBeg() {
	node *t1;
	t1 = head;
	int temp;
	if(head == NULL)
		cout<<"Nothing to delete!"<<endl;
	else if(t1->next == t1 && t1->prev == t1) {
		temp = t1->data;
		head = NULL;
	}
	else {
		temp = t1->data;
		(t1->next)->prev = t1->prev;
		(t1->prev)->next = t1->next;
		head = t1->next;
	}
	delete t1;
	return temp;
}

int dcll::deleteBeforePos(int pos) {
	int i = 1;
	if(head == NULL) {
		cout<<"Nothing to delete!"<<endl;
		return 0;
	}
	else {
		if(pos == 1) {
			deleteAtEnd();
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

int dcll::deleteAfterPos(int pos) {
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
			deleteAtBeg();
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

int dcll::deleteAtEnd() {
	node *t1, *t2;
	t1 = head;
	int temp;
	if(head == NULL)
		cout<<"Nothing to delete!"<<endl;
	else if(t1->prev == t1 && t1->next == t1) {
		temp = t1->data;
		head = NULL;
	}
	else {
		while(t1->next != head) {
			t2 = t1;
			t1 = t1->next;
		}
		temp = t1->data;
		t2->next = t1->next;
		(t1->next)->prev = t2;
	}
	delete t1;
	return temp;
}

int dcll::nodeCount() {
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

void dcll::display() {
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