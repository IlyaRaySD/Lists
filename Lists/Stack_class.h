#pragma once

#include <iostream>
using namespace std;

// stack class
template <typename Type>
class Stack {
private:
	// stack node class
	class Stack_node {
	public:
		Type value; // node element value
		Stack_node* next; // pointer to next node

		// constructor
		Stack_node(Type value, Stack_node* next) {
			this->value = value;
			this->next = next;
		}
	};

	Stack_node* head; // stack start node
	int size; // size of stack
public:
	// constructor
	Stack() {}

	// checking for empty stack
	bool empty() {
		return size == 0;
	}

	// adding an element to the stack
	void push(Type value) {
		head = new Stack_node(value, head);
		size++;
	}

	// taking an element from the stack
	Type pop() {
		if (!empty()) {
			Type value = head->value;
			head = head->next;
			size--;
			return value;
		}
		return 0;
	}

	// unimplemented function
	// should have returned the value from the top of the stack without removing it
	Type front() {
		return head->value;
	}

	// input stack to console
	void print_stack() {
		Stack_node* current = head;
		if (!empty()) {
			while (current->next != nullptr) {
				cout << current->value << ' ';
				current = current->next;
			}
			cout << current->value << ' ';
		}
		else
			cout << "Stack is empty";
	}
};