#include "SatrWars.h"
using json = nlohmann::json;
StarWars::StarWars() {
	this->swClient = new httplib::Client("http://swapi.dev");
}
json StarWars::makeRequest(httplib::Client* swClient, std::string request) {
	if (auto response = swClient->Get(request)) {
		if (response->status == 200) {
			return json::parse(response->body);
		}
		else {
			std::cout << "Bad request " << response->status << std::endl;
		}
	}
	return *new json;
}
std::vector<std::map<std::string, std::string>> StarWars::getParametrs(int& choice) {
	std::vector<std::map<std::string, std::string>> arr;
	std::string request = this->nameRequest;
	request += std::to_string(choice) + '/';
	std::string planetRequest = this->planetRequest + std::to_string(choice) + '/';
	std::string filmRequest = this->filmRequest + '/';
	json result = this->makeRequest(this->swClient, request);
	for (int i = 0; i < result.size(); i++) {
		std::map<std::string, std::string> name;
		name["Name"] = result[i]["name"].get<std::string>();
		arr.push_back(name);
		std::map<std::string, std::string> height;
		height["Height"] = result[i]["height"].get<std::string>();
		arr.push_back(height);
		std::map<std::string, std::string> gender;
		gender["Gender"] = result[i]["gender"].get<std::string>();
		arr.push_back(gender);
		std::map<std::string, std::string> planet;
		planet["Planet"] = this->makeRequest(this->swClient, planetRequest).get<std::string>();
		arr.push_back(planet);
		std::vector<std::string> mapV;
		for (int j = 0; j < 9; j++) {
			mapV.push_back(this->makeRequest(this->swClient, this->makeRequest(this->swClient, filmRequest)[i][j]["title"]).get<std::string>());
		}
		std::map<std::string, std::vector<std::string>> film;
		film["Films"] = mapV;
	}
	return arr;
}

std::vector<std::map<std::string, std::string>> StarWars::searchRequest() {
	json result = this->makeRequest(this->swClient, this->searchReq);
	std::vector<std::map<std::string, std::string>> search;
	for (int i = 0; i < 10; i++) {
		std::map<std::string, std::string> map;
		map[result[i]["uid"].get<std::string>()] = result[i]["name"].get<std::string>();
		search.push_back(map);
	}
	return search;
}