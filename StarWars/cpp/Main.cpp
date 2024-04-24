#include "Tools.h"
using namespace Tools;
int main() {
	system("chcp 1251");
	int choice;
	bool flag = true;
	StarWars* app = new StarWars();
	while (flag) {
		showMenu();
		std::cout << "¬ведите вариант: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			showSearch(app->searchRequest());
			showMenu();
			std::cin >> choice;
			break;
		case 2:
			showArr(app->getParametrs(choice));
			break;
		case 5:
			flag = false;
			break;
		}
	}
	return 0;
}