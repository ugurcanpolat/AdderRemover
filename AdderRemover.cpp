/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 29.04.2017
 */

#include "AdderRemover.h"

void AdderRemover::firstAdd(int add) {
	Node* new_node = new Node;
	new_node->data = add;
	
	// If there is no node yet, make the new node head and tail.
	if(nodeCount == 0) {
		new_node->next = new_node->prev = new_node;
		head = tail = new_node;
		return;
	}
	
	// Connect new head which is new node and tail.	
	head->prev = new_node;
	new_node->next = head;
	new_node->prev = tail;
	tail->next = new_node;	
	head = new_node;	
}

void AdderRemover::lastAdd(int add) {
	Node* new_node = new Node;
	new_node->data = add;
	
	// If there is no node yet, make the new node head and tail.
	if(nodeCount == 0) {
		new_node->next = new_node->prev = new_node;
		head = tail = new_node;
		return;
	}
	
	// Connect new tail which is new node and head.
	head->prev = new_node;
	new_node->next = head;
	new_node->prev = tail;
	tail->next = new_node;	
	tail = new_node;	
}

void AdderRemover::firstRemove() {
	// If there is no node, do not do any operations.
	if(nodeCount == 0)
		return;
	
	// If there is only one node, head and tail should be NULL.
	if(nodeCount == 1) {
		delete head;
		head = tail = NULL;
		return;
	}
	
	// Get the node to remove.
	Node *remove = head;
	// Connect new head and tail. 
	head = head->next;
	head->prev = tail;
	tail->next = head;
	delete remove;
}

void AdderRemover::lastRemove() {
	// If there is no node, do not do any operations.
	if(nodeCount == 0)
		return;
	
	// If there is only one node, head and tail should be NULL.
	if(nodeCount == 1) {
		delete tail;
		head = tail = NULL;
		return;
	}
	
	// Get the node to remove.
	Node *remove = tail;
	// Connect head and new tail. 
	tail = tail->prev;
	tail->next = head;
	head->prev = tail;
	delete remove;
}

void AdderRemover::display() const {
	cout << endl << name << " | NodeCount:" << nodeCount << endl;
	cout << "------" << endl;
	
	if (nodeCount == 0) {
		cout << "There is no element to print" << endl;
		return;
	}
	
	Node *print = head;
	for(int i=0; i < nodeCount; i++) {
		cout << print->data << endl;
		print = print->next;
	}	
}

void AdderRemover::removeAll() {
	Node *remove;
	// Delete all nodes starting from head.
	while(nodeCount > 0) {
		remove = head;
		head = head->next;
		delete remove;
		nodeCount--;
	}
	head = tail = NULL;
	
	// If |traverser| is allocated, delete it.
	if(traverser != NULL) {
		delete traverser;
		traverser = NULL;
	}
}

void AdderRemover::traverse() const {
	cout << endl << name << " | NodeCount:" << nodeCount << endl;
	cout << "------" << endl;
	
	if (nodeCount == 0) {
		cout << "There is no element to print" << endl;
		return;
	}	
	
	// |next| function returns the current element while advancing the
	// current node. 
	for(int i=0; i < nodeCount; i++) {
		cout << (traverser->next()).data << endl;
	}
}
