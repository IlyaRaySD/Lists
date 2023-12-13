#include <iostream>
#include "List_class.h"
using namespace std;

int main() {
	List<int> list;
	for (int i = 0; i < 8; i++)
		list.append(1 + rand() % 9);
	list.print_list();
	cout << endl;
	list.sort();
	list.print_list();
}
