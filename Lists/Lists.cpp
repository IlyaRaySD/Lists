#include <iostream>
#include "Voids.h"
using namespace std;

// main menu
int main() {
	int opt, n, m;
	cout << "Welome";
	link:cout << "\n\nEnter the option:\n1 - Merging lists\n2 - Swap min and max\n3 - Insertion sort\n4 - Stack operations\n0 - Exit\n\nEnter the number: ";
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
		cout << "\nEnter the size of first list: ";
		cin >> n;
		// checking if the entered value is correct
		if (!cin) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\nInput Error";
			goto link;
		}
		cout << "Enter the size of second list: ";
		cin >> m;
		if (!cin) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\nInput Error";
			goto link;
		}
		merge(n, m);
		goto link;
		break;
	case 2:
		cout << "\nEnter the size list: ";
		cin >> n;
		// checking if the entered value is correct
		if (!cin) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\nInput Error";
			goto link;
		}
		minmax(n);
		goto link;
		break;
	case 3:
		cout << "\nEnter the size list: ";
		cin >> n;
		// checking if the entered value is correct
		if (!cin) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\nInput Error";
			goto link;
		}
		sort(n);
		goto link;
		break;
	case 4:
		stack_oper();
		goto link;
		break;
	case 0:
		system("pause");
		break;
	default:
		cout << "\nIncorrect choise.";
		goto link;
		break;
	}
}
