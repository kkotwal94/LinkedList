// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int value;
	Node* next;

};

Node *head;
Node *tail;

void addNode(int data) {
	Node *newNode = new Node;
	newNode->value = data;
	newNode->next = NULL;
	if (head == NULL) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
}

void deleteNode() {
	Node* cur = head;
	Node* temp;
	if (head == NULL) {
		cout << "There is nothing to delete" << endl;
	}
	else {
		temp = cur->next;
		head = temp;
	}

}

Node* getNode(int position) {
	Node* cur = head;
	for (int x = 0; x < position; x++) {
		cur = cur->next;
	}
	//cout << cur->value << endl;
	return cur;
}

int listSize() {
	Node* search = head;
	int linkedSize = 0;
	if (search == NULL) {
		linkedSize = 0;
		cout << "List is Empty!!!" << linkedSize << endl;
	}
	else {
		while (search != NULL) {
			search = search->next;
			linkedSize = linkedSize + 1;
		}
	}
	cout << "Size of Linked List: " << linkedSize << endl;
	return linkedSize;
}

int maxSize() {
	Node* search = head;
	int linkedSize = 0;
	if (search == NULL) {
		linkedSize = 0;
		}
	else {
		while (search != NULL) {
			search = search->next;
			linkedSize = linkedSize + 1;
		}
	}
	return linkedSize;
}

void insertNode(int position, int data){
	Node* newNode = new Node;
	newNode->value = data; //initialize
	newNode->next = NULL; //initialize
	if (position == 0) {
		addNode(data);
	}
	else if (position > maxSize()) { //TODO: Fix this shit, fixed.
		Node* temp3 = getNode(maxSize()-1);
		temp3->next = newNode;
		newNode->next = NULL;
		tail = newNode;
		//cout << "List size is: " << listSize() << "The position is higher then then number of items in range" << endl;
	}
	else{
		Node* temp = getNode(position);
		Node* temp2 = getNode(position - 1);
		newNode->next = temp; //node points to the one at the position
		temp2->next = newNode; //one before points to it
	}
}

void printList() {
	Node* search = head;
	if (search == NULL) {
		cout << "List is Empty!!!" << endl;
	}
	else {
		while (search != NULL) {
			cout << search->value << endl;
			search = search->next;
		}
		cout << endl;
	}
}

void deleteNode(int position) {
	if (position == 0) {
		deleteNode();
	}
	else if (position >= maxSize()) {
		int position = maxSize()-1; //maxsize should return size + 1 but im a idiot who counts from 0 in size(positioning is like arrays).
		cout << position << endl;
		Node* currentNode = getNode(position);
		Node* temp = getNode(position-1);
		temp->next = NULL;
		delete currentNode;
		
	}
	/*else if (position == maxSize()) {
		cout << position << endl;
		Node* currentNode = getNode(position);
		Node *temp = getNode(position - 1);
		temp->next = NULL;
		delete currentNode;
	}*/
	else {
		Node* currentNode = getNode(position);
		Node *temp = getNode(position - 1);
		Node *temp2 = getNode(position + 1);
		temp->next = temp2;
		delete currentNode;
	}
}

void sortLinkedList() {
	for (int x = 0; x < maxSize(); x++){
		if (getNode(x)->value < getNode(x + 1)->value) {
			cout << "Sorting" << endl;
		}
		else {
			for (int i = 0; i < maxSize(); i++) {
				if (getNode(i)->value < getNode(i + 1)->value) {
					return;
				}
				else if (getNode(i)->value == getNode(i+1)->value){
					return;
				}
				else {
					if (getNode(i)->value > getNode(i+1)->value) {
						Node* temp = getNode(i + 1)->next;
						Node* temp2 = getNode(i - 1);
						Node* node1 = getNode(i);
						Node* node2 = getNode(i + 1);
						node1->next = temp;
						node2->next = node1;
						temp2->next = node2;

					}
					if ((getNode(i)->value > getNode(i + 1)->value) && (head == getNode(i))) {
						Node* temp = getNode(i + 1)->next;
						Node* node1 = getNode(i);
						Node* node2 = getNode(i + 1);
						head = node2;
						node2->next = node1;
						node1->next = temp;
					}
				}
			}
		}
	}
}

// 1 5 6 2 1


void reverseLinkedList() {
	Node* cur = head;
	Node* next;
	Node* prev = NULL;
	while (cur != NULL) {
		next = cur->next; //assign next to the second node
		cur->next = prev; //assign current node to the one before
		prev = cur; //assign previous to that node we did work on
		cur = next; //the current node is now that second node, and repeat.
	}
	head = prev;
}




int _tmain()
{
	int x;
	addNode(22); //worked
	addNode(33); //worked
	addNode(44); //worked
	insertNode(30000, 55); //worked sweet!
	deleteNode(3);
	listSize();
	sortLinkedList();
	//reverseLinkedList(); //ToDo
	//getNode(2); //gets node check //TODO: Shows up on top for some reason
	//deleteNode(); //worked
	//deleteNode(); //worked
	printList(); //list printed
	cin >> x;
}

