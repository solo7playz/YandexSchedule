#include "WebApp.h"

using json = nlohmann::json;
//WebApp::WebApp(){}
//WebApp::WebApp(std::string client, std::string API) {
//    this->cityCodeCli = new httplib::Client(client);
//    this->YA_API_KEY = API;
//}
json WebApp::getResult(std::string& request) {
    return json::parse(this->geoCliRes->Get(request)->body);
}
nlohmann::json WebApp::geoCliFind(std::string& QW_API_KEY) {
    this->request = "/geo/1.0/direct?";
    this->request += "q=" + this->cityNameFrom;
    this->request += "&limit=" + '10';
    this->request += "&appid=" + QW_API_KEY;
    return this->getResult(request);
}
void WebApp::findCoordinate() {
    auto responseFrom = this->geoCli.Get(request);
    if (responseFrom) {
        if (responseFrom->status == 200) {
            this->resultFrom = json::parse(responseFrom->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }
    this->lonFrom = to_string(this->resultFrom[0]["lon"]);
    this->latFrom = to_string(this->resultFrom[0]["lat"]);

    auto responseTo = this->geoCli.Get(request);
    if (responseTo) {
        if (responseTo->status == 200) {
            this->resultTo = json::parse(responseTo->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }
    this->lonTo = to_string(this->resultTo[0]["lon"]);
    this->latTo = to_string(this->resultTo[0]["lat"]);
}
nlohmann::json WebApp::stationsFindFrom(std::string& QW_API_KEY) {
    this->stationReqFrom = "/v3.0/nearest_stations/?apikey=" + QW_API_KEY + "&format=json&lat=" + this->latFrom + "&lng=" + this->lonFrom + "&distance=" + Tools::cinDistance() + "&lang=ru_RU";
    return this->getResult(stationReqFrom);
}
nlohmann::json WebApp::stationsFindTo(std::string& QW_API_KEY) {
    this->stationReqTo = "/v3.0/nearest_stations/?apikey=" + QW_API_KEY + "&format=json&lat=" + this->latTo + "&lng=" + this->lonTo + "&distance=" + Tools::cinDistance() + "&lang=ru_RU";
    return this->getResult(stationReqTo);
}