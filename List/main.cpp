#include <iostream>
#include "List.h"


// Пример с целыми числами
void intList() {
	List<int> list;
	for (int i = 0; i < 256; i += 4) {
		list.append(i);
		list.append(i + 1);
		list.append(i + 2);
		list.append(i + 3);
	}
	list.print();
	std::cout << "Element with index 222 - " << list[222] << std::endl;
}



// Пример со строкой
void stringList() {
	List<std::string> list;
	list.append("Hi");
	list.append("my freind.");
	list.print();
	std::cout << "Element with index 1 - " << list[1] << std::endl;
}


int main() {
	intList();
	stringList();
	return 0;
}