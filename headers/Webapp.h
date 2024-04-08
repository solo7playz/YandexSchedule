#pragma once
#include <iostream>
#include <string>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include "YandexSchedules.cpp";
#include "Tools.h"
class WebApp {
	httplib::Client* geoCliRes;
	httplib::Client geoCli;
	httplib::Client* cityCodeCli;
	std::string QW_API_KEY;
	std::string YA_API_KEY;
	std::string request;
	std::string stationReqFrom;
	std::string stationReqTo;
	nlohmann::json resultFrom;
	nlohmann::json resultTo;
	nlohmann::json stationResult;
	std::string cityNameFrom;
	std::string cityNameTo;
	nlohmann::json scheduleResult;
	std::string scheduleReq;
	std::string lonFrom;
	std::string latFrom;
	std::string lonTo;
	std::string latTo;
public:
	WebApp();
	WebApp(std::string client, std::string API);
	nlohmann::json getResult(std::string& request);
	nlohmann::json geoCliFind(std::string& QW_API_KEY);
	void findCoordinate();
	nlohmann::json stationsFindFrom(std::string& QW_API_KEY);
	nlohmann::json stationsFindTo(std::string& QW_API_KEY);
};
