#include <iostream>
#include "Voids.h"
using namespace std;

int main() {
	int opt, n, m;
	cout << "Welome";
	link:cout << "\n\nEnter the option:\n1 - Merging lists\n2 - Swap min and max\n3 - Insertion sort\n\nEnter the number: ";
	cin >> opt;
	switch (opt) {
	case 1:
		cout << "\nEnter the size of first list: ";
		cin >> n;
		cout << "Enter the size of second list: ";
		cin >> m;
		merge(n, m);
		goto link;
		break;
	case 2:
		cout << "\nEnter the size list: ";
		cin >> n;
		minmax(n);
		goto link;
		break;
	case 3:
		cout << "\nEnter the size list: ";
		cin >> n;
		sort(n);
		goto link;
		break;
	}
}
