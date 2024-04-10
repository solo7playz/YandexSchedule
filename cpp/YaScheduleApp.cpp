#include "YaScheduleApp.h"


using json = nlohmann::json;


YaScheduleApp::YaScheduleApp(std::string openWeatherApiKey, std::string yaScheduleApiKey,
	std::string cityFrom, std::string cityTo) {
	this->openWeatherClient = new httplib::Client("http://api.openweathermap.org");
	this->yandexScheduleClient = new httplib::Client("http://api.rasp.yandex.net");
	this->cityFrom = cityFrom;
	this->cityTo = cityTo;
	this->openWeatherApiKey = openWeatherApiKey;
	this->yaScheduleApiKey = yaScheduleApiKey;
}


json YaScheduleApp::makeRequest(httplib::Client* client, std::string request) {
	if (auto response = client->Get(request)) {
		if (response->status == 200) {
			return json::parse(response->body);
		}
		else {
			std::cout << "Bad request " << response->status << std::endl;
		}
	}
	return *new json;
}


std::vector <std::string> YaScheduleApp::getLatLon(std::string city) {
	std::string request = this->openWeatherRequest;
	request += "q=" + city;
	request += "&appid=" + this->openWeatherApiKey;
	json result = this->makeRequest(this->openWeatherClient, request);
	std::vector <std::string> latLon = { to_string(result["coord"]["lon"]), to_string(result["coord"]["lat"]) };
	return latLon;
}

std::string cinDate() {
	std::string dateYear;
	std::string dateMonth;
	std::string dateDay;
	std::cout << "print Year: ";std::cin >> dateYear;
	std::string date = dateYear + "-";
	std::cout << "print Month: ";std::cin >> dateMonth;
	if (stoi(dateMonth) < 10) {
		date += '0' + dateMonth + "-";
	}
	else {
		date += dateMonth + "-";
	}
	std::cout << "print Day: ";std::cin >> dateDay;
	if (stoi(dateDay) < 10) {
		date += '0' + dateDay;
	}
	else {
		date += dateDay;
	}
	return date;
}

std::string cinTransport() {
	std::string typeOfTransport;
	std::cout << "types of transport: 1.plane\n 2.train\n 3.suburban\n 4.bus\n 5.water\n 6.helicopter\n";
	std::cout << "print type of transport: ";std::cin >> typeOfTransport;
	return typeOfTransport;
}

std::string YaScheduleApp::getCityCode(std::vector <std::string> latLon) {
	std::string request = this->yaCityCodeRequest;
	request += "apikey=" + this->yaScheduleApiKey;
	request += "&lat=" + latLon[1];
	request += "&lng=" + latLon[0];
	std::string code = this->makeRequest(this->yandexScheduleClient, request)["code"].get<std::string>();
	return code;
}


json YaScheduleApp::getScheduleBetweenCities() {
	std::string request = this->yaScheduleRequest;
	request += "apikey=" + this->yaScheduleApiKey;
	request += "&from=" + this->getCityCode(this->getLatLon(this->cityFrom));
	request += "&to=" + this->getCityCode(this->getLatLon(this->cityTo));
	request += "&lang=ru_RU&page=1&date=" + cinDate();
	request += "&transport_types=" + cinTransport();
	return this->makeRequest(this->yandexScheduleClient, request);
}

//json YaScheduleApp::getStationsFrom(std::string city) {
//	std::string request = this->yaScheduleRequest;
//	request += "apikey=" + YA_API_KEY;
//	request += "&format=json&lat=" + YaScheduleApp::getLatLon(city)[0];
//	request += "&lng=" + YaScheduleApp::getLatLon(city)[1];
//	request += "&distance=50&lang=ru_RU";
//	return this->YaScheduleApp::makeRequest(this->yandexScheduleClient, request);
//}
//json YaScheduleApp::getStationsTo(std::string city) {
//	std::string request = this->yaScheduleRequest;
//	request += "apikey=" + YA_API_KEY;
//	request += "&format=json&lat=" + YaScheduleApp::getLatLon(city)[0];
//	request += "&lng=" + YaScheduleApp::getLatLon(city)[1];
//	request += "&distance=50&lang=ru_RU";
//	return this->YaScheduleApp::makeRequest(this->yandexScheduleClient, request);
//}
//
