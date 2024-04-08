#include "Tools.h"
using namespace Tools;
//void showMenu() {
//
//}
std::string cinDistance() {
	std::string distance;
	std::cout << "Введите дистанцию в километрах, в которой вы хотите найти станцию: ";
	std::cin >> distance;
	return distance;
}
void coutMap(std::map<std::string, std::string>map, nlohmann::json data) {
	std::cout << map[data["title"]] << std::endl;
}
void stationsFrom(nlohmann::json data) {
	std::string keyFrom = "lat: " + data[0]["lat"];
	keyFrom += " lon: " + data[0]["lng"];
	std::map<std::string, std::string> From;
	From[data[0]["title"]] = keyFrom;
	coutMap(From,data);
}
void stationsTo(nlohmann::json data) {
	std::string keyTo = "lat: " + data[0]["lat"];
	keyTo += " lon: " + data[0]["lng"];
	std::map<std::string, std::string> To;
	To[data[0]["title"]] = keyTo;
	coutMap(To, data);
}


