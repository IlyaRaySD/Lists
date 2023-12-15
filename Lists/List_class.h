#pragma once

#include <iostream>
using namespace std;

// list class
template <typename Type>
class List {
private:
	// list node class
	class Node {
	public:
		Type value; // node element value
		Node* next; // pointer to next node

		// constructor
		Node(Type value) {
			this->value = value;
			next = nullptr;
		}
	};

	Node* head; // start node
	int length; // length of list
public:
	// constructor
	List() {
		head = nullptr;
		length = 0;
	}

	// returns the length of the list
	int len() { return length; }

	// adding an element to the end of the list
	void append(Type value) {
		if (head == nullptr) {
			head = new Node(value);
			length = 1;
		}
		else {
			Node* current = head;
			while (current->next != nullptr)
				current = current->next;
			current->next = new Node(value);
			length++;
		}

	}

	// adding an element anywhere in the list
	void insert(Type value, int index) {
		if (index == 0) {
			Node* temp = head;
			head = new Node(value);
			head->next = temp;
			length++;
		}
		else {
			Node* current = head;
			for (int i = 0; i < index - 1; i++)
				current = current->next;
			Node* temp = current->next;
			current->next = new Node(value);
			current->next->next = temp;
			length++;
		}
	}

	// removing an element from a list
	void del(int index) {
		Node* current = head;
		for (int i = 0; i < index; i++)
			current = current->next;
		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
		length--;
	}

	// clearing the list
	void clear() {
		for (int i = 0; i < length; i++) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		head = nullptr;
		length = 0;
	}

	// operator redefinition []
	Type operator[](int index) {
		Node* current = head;
		for (int i = 0; i < index; i++)
			current = current->next;
		return current->value;
	}

	// output list to console
	void print_list() {
		Node* current = head;
		while(current->next != nullptr) {
			cout << current->value << ' ';
			current = current->next;
		}
		cout << current->value << ' ';
	}

	// swaps 2 values ​​in a list
	void swap(int index_1, int index_2) {
		Node* first = head;
		Node* second = head;
		for (int i = 0; i < index_1; i++)
			first = first->next;
		for (int i = 0; i < index_2; i++)
			second = second->next;
		Type temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	// distructor
	~List() {
		clear();
	}
};