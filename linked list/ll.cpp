#include "ll.h"

ll::ll() {
	head = NULL;
}

bool ll::insertAtBeg(int ele) {
	struct node *temp;
	temp = new node;
	temp->data = ele;
	if(head == NULL)
		temp->next = NULL;
	temp->next = head;
	head = temp;
	return true;
}

bool ll::insertAtEnd(int ele) {
	struct node *t1;
	t1 = head;
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if(head == NULL)
		head = temp;
	else {
		while(t1->next != NULL)
			t1 = t1->next;
		t1->next = temp;
	}
	return true;
}

bool ll::insertAtPos(int ele, int pos) {
	struct node *t1;
	t1 = head;
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	int i = 1;
	/*if(head == NULL) {
		cout<<"Nothing's here!"<<endl;
		insertAtBeg(ele);
	}*/
	if(pos == 1)
		insertAtBeg(ele);
	else {
		while(++i < pos)
			t1 = t1->next;
		temp->next = t1->next;
		t1->next = temp;
	}
	return true;
}

int ll::deleteAtBeg() {
	struct node *t1;
	t1 = head;
	int temp = t1->data;
	head = t1->next;
	delete t1;
	return temp;
}

int ll::deleteAtEnd() {
	struct node *t1, *t2;
	t1 = head;
	while(t1->next != NULL) {
		t2 = t1;
		t1 = t1->next;
	}
	int temp = t1->data;
	t2->next = NULL;
	delete t1;
	return temp;
}

int ll::deleteAtPos(int pos) {
	struct node *t1, *t2;
	t1 = head;
	int temp, i = 1;
	if(pos == 1)
		deleteAtBeg();
	else {
		while(i++ < pos) {
			t2 = t1;
			t1 = t1->next;
			//i++;
		}
		temp = t1->data;
		t2->next = t1->next;
		delete t1;
	}
	return temp;
}

void ll::display() {
	struct node *t1;
	t1 = head;
	if(head == NULL)
		cout<<"Nothing's here!"<<endl;
	while(t1 != NULL) {
		cout<<t1->data<<"---> ";
		t1 = t1->next;
	}
	cout<<"\n";
}

void ll::reverseDisplay(node *head) {
	if(head == NULL)
		return;
	
	reverseDisplay(head->next);
	
	cout<<head->data<<" -> ";
}
