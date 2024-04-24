#pragma once
#include <iostream>
#include <string>
#include <map>
#include <nlohmann/json.hpp>
#include <httplib.h>
class StarWars {
	httplib::Client* swClient;
	std::string filmRequest = "/api/films/";
	std::string nameRequest = "/api/people/";
	std::string planetRequest = "/api/planets/";
	std::string searchReq = "/api/people/?search=r2";
public:
	StarWars();
	std::vector<std::map<std::string, std::string>> searchRequest();
	std::vector<std::map<std::string, std::string>> getParametrs(int& choice);
private:
	nlohmann::json makeRequest(httplib::Client* swClient, std::string request);

};