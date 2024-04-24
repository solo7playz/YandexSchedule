#include "Tools.h"


void Tools::showMenu() {
	std::cout << "1 - Получить полное расписание между городами" << std::endl;
	std::cout << "2 - Получить полное расписание между городами опреденного траспорта" << std::endl;
	std::cout << "3 - Выход" << std::endl << std::endl;
}


void Tools::showSchedule(std::vector <std::vector <std::map <std::string, std::string>>> schedule) {
	system("chcp 65001");
	for (int i = 0; i < schedule.size(); i++) {
		for (int j = 0; j < schedule[i].size(); j++) {
			std::cout << schedule[i][j]["Race Title"] << " ";
			std::cout << schedule[i][j]["Race Number"] << " ";
			std::cout << schedule[i][j]["Departure Station Title"] << " ";
			std::cout << schedule[i][j]["Departure Station Code"] << " ";
			std::cout << schedule[i][j]["Arrival Station Title"] << " ";
			std::cout << schedule[i][j]["Arrival Station Code"] << " ";
			std::cout << schedule[i][j]["Transport Type"] << " ";
			std::cout << schedule[i][j]["Departure Date"] << " ";
			std::cout << schedule[i][j]["Arrival Date"] << " ";
			std::cout << schedule[i][j]["Transport Company Code"] << " ";
			std::cout << schedule[i][j]["Price"] << std::endl << std::endl;
		}
	}
	system("chcp 1251");
}

std::string cinDate() {
	std::string dateYear;
	std::string dateMonth;
	std::string dateDay;
	std::cout << "print Year: ";std::cin >> dateYear;
	std::string date = dateYear + '-';
	std::cout << "print Month: ";std::cin >> dateMonth;
	if (dateMonth.size() < 2) {
		date += '0' + dateMonth + '-';
	}
	else {
		date += dateMonth + '-';
	}
	std::cout << "print Day: ";std::cin >> dateDay;
	if (dateDay.size() < 2) {
		date += '0' + dateDay;
	}
	else {
		date += dateDay;
	}
	return date;
}

std::string Tools::askAboutDate() {
	std::string date;
	std::cout << "Вы хотите добавить дату поездки? [y/n]: ";
	std::string answer; std::cin >> answer;
	if (answer == "y") {
		cinDate();
	}
	return "null";
}

