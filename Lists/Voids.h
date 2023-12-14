#pragma once

#include <iostream>
#include "List_class.h"
using namespace std;

void merge(int n, int m) {
	List<int> list1, list2, res;
	int first = 0, second = 0;
	list1.append(1);
	list2.append(1);
	for (int i = 1; i < n; i++)
		list1.append(list1[i - 1] + rand() % 5);

	cout << "\nFirst list:\n";
	list1.print_list();
	cout << endl;

	for (int i = 1; i < m; i++)
		list2.append(list2[i - 1] + rand() % 5);

	cout << "Second list:\n";
	list2.print_list();
	cout << endl;

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
	cout << "Result of merging:\n ";
	res.print_list();

	list1.clear();
	list2.clear();
	res.clear();
}

void minmax(int n) {
	List<int> list;
	for (int i = 0; i < n; i++) {
		list.append(-10 + rand() % 20);
	}
	cout << "Starting list:\n";
	list.print_list();
	cout << "\nFinal list:\n";
	int max = list[0], min = list[0], min_index = 0, max_index = 0;
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

	list.clear();
}

void sort(int n) {
	List<int> list, res;
	for (int i = 0; i < n; i++)
		list.append(-10 + rand() % 20);

	cout << "Start list:\n ";
	list.print_list();

	res.append(list[0]);

	int i = 1;
	bool flag;
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

	cout << "\nSorted list:\n ";
	res.print_list();

	list.clear();
	res.clear();
}