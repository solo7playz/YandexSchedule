#include "YaScheduleApp.h"


std::string OW_API_KEY = "e7c0bce5516c376f0d980ddc956bb225";
std::string YA_API_KEY = "ec846f28-142d-4543-aba7-ec9a3195a6ff";

int main() {
	system("chcp 65001");
	std::cout << "������� ����� �����������: ";
	std::string cityFrom; std::cin >> cityFrom;
	std::cout << "������� ����� ����������: ";
	std::string cityTo; std::cin >> cityTo;
	YaScheduleApp* app = new YaScheduleApp(OW_API_KEY, YA_API_KEY, cityFrom, cityTo);
	std::cout << app->getScheduleBetweenCities();
	return 0;
}