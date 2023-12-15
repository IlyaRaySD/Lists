#pragma once

#include <iostream>
#include "List_class.h"
#include "Stack_class.h"
using namespace std;

// merging algorithm
void merge(int n, int m) {
	List<int> list1, list2, res;
	int first = 0, second = 0;
	list1.append(1);
	list2.append(1);
	// randomly fills an ordered list
	for (int i = 1; i < n; i++)
		list1.append(list1[i - 1] + rand() % 5);

	cout << "\nFirst list: ";
	list1.print_list();
	cout << endl;

	// randomly fills an ordered list
	for (int i = 1; i < m; i++)
		list2.append(list2[i - 1] + rand() % 5);

	cout << "Second list: ";
	list2.print_list();
	cout << endl;

	// filling the resulting list (merging 2 lists)
	while (first < list1.len() and second < list2.len()) {
		if (list1[first] <= list2[second]) {
			res.append(list1[first]);
			first++;
		}
		else {
			res.append(list2[second]);
			second++;
		}
	}
	if (first < list1.len())
		for (int i = first; i < list1.len(); i++)
			res.append(list1[i]);
	if (second < list2.len())
		for (int i = second; i < list2.len(); i++)
			res.append(list2[i]);

	cout << "Result of merging: ";
	res.print_list();
	cout << endl;

	list1.clear();
	list2.clear();
	res.clear();
}

// swap max and min element in list
void minmax(int n) {
	List<int> list;
	for (int i = 0; i < n; i++) {
		list.append(-10 + rand() % 20);
	}

	cout << "Starting list: ";
	list.print_list();
	cout << endl;

	cout << "\nFinal list: ";

	int max = list[0], min = list[0], min_index = 0, max_index = 0;
	// finding indexes of max and min elements
	for (int i = 1; i < list.len(); i++) {
		if (list[i] >= max) {
			max = list[i];
			max_index = i;
		}
		if (list[i] <= min) {
			min = list[i];
			min_index = i;
		}
	}

	list.swap(max_index, min_index);
	list.print_list();
	cout << endl;

	list.clear();
}

// insertion sort algorithm
void sort(int n) {
	List<int> list, res;
	for (int i = 0; i < n; i++)
		list.append(-10 + rand() % 20);

	cout << "Start list: ";
	list.print_list();
	cout << endl;

	res.append(list[0]);

	int i = 1;
	bool flag;
	// list elements will be added to the resulting list one element at a time
	while (i < list.len()) {
		flag = 0;
		for (int j = 0; j < res.len(); j++) {
			if (list[i] <= res[j]) {
				res.insert(list[i], j);
				flag = 1;
				break;
			}
		}
		if (!flag)
			res.append(list[i]);
		i++;
	}

	cout << "\nSorted list: ";
	res.print_list();
	cout << endl;

	list.clear();
	res.clear();
}

// stack operations menu
void stack_oper() {
	Stack<int> stack;
	int opt;
	cout << "\nStack commands:\n1 - add element on tho top\n2 - take element on the top\n0 - return to main menu";
link:cout << "\n\nEnter the option : ";
	cin >> opt;
	// checking if the entered value is correct
	if (!cin) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "\nInput Error";
		goto link;
	}
	switch (opt) {
	case 1:
		int el;
		cout << "\nElement to add: ";
		cin >> el;
		// checking if the entered value is correct
		if (!cin) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\nInput Error";
			goto link;
		}
		stack.push(el);
		cout << "\nStack state: ";
		stack.print_stack();
		cout << endl;
		goto link;
		break;
	case 2:
		cout << "\n\nElement was taken: " << stack.pop();
		cout << "\nStack state: ";
		stack.print_stack();
		cout << endl;
		goto link;
		break;
	case 0:
		break;
	default:
		cout << "\nIncorrect choise.";
		goto link;
		break;
	}
}