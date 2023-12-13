#include <iostream>
using namespace std;
#pragma once

template <typename Type>
class List {
private:
	class Node {
	public:
		Type value;
		Node* next;

		Node(int value) {
			this->value = value;
			next = nullptr;
		}
	};

	Node* head;
	int length;
public:
	List() {
		head = nullptr;
		length = 0;
	}

	int len() { return length; }

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

	void del(int index) {
		Node* current = head;
		for (int i = 0; i < index; i++)
			current = current->next;
		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
		length--;
	}

	void clear() {
		for (int i = 0; i < length; i++) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		head = nullptr;
		length = 0;
	}

	Type operator[](int index) {
		Node* current = head;
		for (int i = 0; i < index; i++)
			current = current->next;
		return current->value;
	}

	void print_list() {
		Node* current = head;
		while(current->next != nullptr) {
			cout << current->value << ' ';
			current = current->next;
		}
		cout << current->value << ' ';
	}

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

	/*void sort() {
		Node* last = head;
		Node* current;
		int sorted = 0;
		while (last != nullptr) {
			current = head;
			last = last->next;
			sorted++;
			for (int i = 0; i < sorted; i++) {
				current = current->next;
				if (current->value > last->value)
					swap(sorted, i);
			}
		}

	}*/

	~List() {
		clear();
	}
};