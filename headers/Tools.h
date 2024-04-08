#pragma once
#include <iostream>
#include <string>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include <map>
#include "YandexSchedules.cpp"
#include "WebApp.h"
namespace Tools {
	void showMenu();
	std::string cinDistance();
	void coutMap(std::map<std::string, std::string> map);
	void stationsFrom(nlohmann::json data);
	void stationsTo(nlohmann::json data);
}