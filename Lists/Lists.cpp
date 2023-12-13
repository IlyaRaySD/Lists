#include <iostream>
#include "List_class.h"
using namespace std;

int main() {
	int n = 5;
	List<int> list_1, list_2;

	for (int i = 0; i < n; i++) {
		list_1.append(i + 1);
		cout << list_1[i] << ' ';
	}

	cout << endl;

	for (int i = 2; i < n + 2; i++) {
		list_2.append(i + 1);
		cout << list_2[i - 2] << ' ';
	}

	cout << endl;
}
