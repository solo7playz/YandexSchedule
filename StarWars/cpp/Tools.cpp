#include "Tools.h"

void Tools::showMenu() {
	std::cout << "1 - вывести список персонажей по кодам" << std::endl;
	std::cout << "2 - ввести код персонажа" << std::endl;
	std::cout << "3 - ввести код планеты" << std::endl;
	std::cout << "4 - ввести код фильма" << std::endl;
	std::cout << "5 - выход" << std::endl;
}
void Tools::showArr(std::vector<std::map<std::string, std::string>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i]["Name"] << " ";
		std::cout << arr[i]["Height"] << " ";
		std::cout << arr[i]["Gender"] << " ";
		std::cout << arr[i]["Planet"] << " ";
		//for (int c = 0; c < arr[i]["Films"].size(); c++) {
		//	std::cout << arr[i]["Films"][c] << std::endl;
		//}

	}
}
void Tools::showSearch(std::vector<std::map<std::string, std::string>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i]["count"] << " ";
	}
}