/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 29.04.2017
 */

#ifndef adderremover_h 
#define adderremover_h 

#include <iostream>
#include <string> 

using namespace std;

class Node {
  public: 
	Node() {data = 0; next = prev = NULL;};
	int data;
	Node* next;
	Node* prev;
};

class ARTraverser {
  public:
	Node* current;
	ARTraverser() {current = NULL;};
	// Destructor is virtual so that AdderRemover class can call the
	// destructor of derived classes while deleting abstract base class
	// pointer.
	virtual ~ARTraverser() {}; 
	virtual bool hasNode() const = 0;
	virtual const Node& next() = 0; 
};

class ARTF : public ARTraverser {
	public:
	ARTF() : ARTraverser() {};
	~ARTF() {};
	// If |current| is not NULL, list has node. 
	bool hasNode() const {return current != NULL;};
	// Advance current and return current node.
	const Node& next() {
		current = current->next; return *current->prev;
	};
};

class ARTL : public ARTraverser {
	public:
	ARTL() : ARTraverser() {};
	~ARTL() {};
	// If |current| is not NULL, list has node. 
	bool hasNode() const {return current != NULL;};
	// Advance current, and return current node.
	const Node& next() {
		current = current->prev; return *current->next;
	};
};

class AdderRemover {
  protected:
	Node* head;
	Node* tail;
	string name;
	int nodeCount;
	ARTraverser* traverser;
	// These functions will be used in |add| functions of the derived 
	// classes. In this way, |add| functions of the derived classes does
	// not contain same code. They are protected members of the base
	// class so that only members of derived classes can call them.
	void firstAdd(int);
	void lastAdd(int);
	void firstRemove();
	void lastRemove();
	
  public:
	AdderRemover() {head = tail = NULL; traverser = NULL; nodeCount = 0;};
	// Destructor is virtual so that |main| function can call the
	// destructor of derived classes while deleting abstract base class
	// pointer.
	virtual ~AdderRemover() {removeAll();};
	virtual void add(int) = 0;
	virtual void remove() = 0;
	virtual void setTraverser() = 0;
	void display() const;
	void removeAll();
	void traverse() const;
};

class FAFR : public AdderRemover {
  public:
	FAFR() : AdderRemover() {name = "FAFR";};
	~FAFR() {};
	void add(int add) {firstAdd(add); nodeCount++;};
	void remove() {firstRemove(); nodeCount--;};
	void setTraverser() { // Initialize |traverser|.
		traverser = new ARTF; traverser->current = head;
	};
};

class FALR : public AdderRemover {
  public:
	FALR() : AdderRemover() {name = "FALR";};
	~FALR() {};
	void add(int add) {firstAdd(add); nodeCount++;};
	void remove() {lastRemove(); nodeCount--;};
	void setTraverser() { // Initialize |traverser|.
		traverser = new ARTF; traverser->current = head;
	};
};

class LAFR : public AdderRemover {
  public:
	LAFR() : AdderRemover() {name = "LAFR";};
	~LAFR() {};
	void add(int add) {lastAdd(add); nodeCount++;};
	void remove() {firstRemove(); nodeCount--;};
	void setTraverser() { // Initialize |traverser|.
		traverser = new ARTL; traverser->current = tail; 
	};
};

class LALR : public AdderRemover {
  public:
	LALR() : AdderRemover() {name = "LALR";};
	~LALR() {};
	void add(int add) {lastAdd(add); nodeCount++;};
	void remove() {lastRemove(); nodeCount--;};
	void setTraverser() { 
		traverser = new ARTL; traverser->current = tail; 
	};
};

#endif
