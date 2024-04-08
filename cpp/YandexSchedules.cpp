#pragma once
#include "Tools.h"
#include "WebApp.h"
std::string QW_API_KEY = "e7c0bce5516c376f0d980ddc956bb225";
std::string YA_API_KEY = "ec846f28-142d-4543-aba7-ec9a3195a6ff";
int main(){
    using json = nlohmann::json;
    setlocale(LC_ALL, "RUS");

    std::string cityNameFrom;
    std::cout << "Vvedite gorod: ";
    std::cin >> cityNameFrom;
    std::string cityNameTo;
    std::cout << "Vvedite gorod naznacheniya: ";
    std::cin >> cityNameTo;

    httplib::Client geoCli("http://api.openweathermap.org");
    httplib::Client cityCodeCli("http://api.rasp.yandex.net");

    //**********
    //std::string requestFrom = "/geo/1.0/direct?";
    //requestFrom += "q=" + cityNameFrom;
    //requestFrom += "&limit=" + '10';
    //requestFrom += "&appid=" + QW_API_KEY;

    //json resultFrom;
    //auto responseFrom = geoCli.Get(requestFrom);

    //if (responseFrom) {
    //    if (responseFrom->status == 200) {
    //        resultFrom = json::parse(responseFrom->body);
    //    }
    //    else {
    //        std::cout << "Bad request" << std::endl;
    //    }
    //}

    //std::string lonFrom = to_string(resultFrom[0]["lon"]);
    //std::string latFrom = to_string(resultFrom[0]["lat"]);

    //std::cout << lonFrom << " " << latFrom << std::endl;

    //std::string cityNameTo;
    //std::cout << "Vvedite gorod naznacheniya: ";
    //std::cin >> cityNameTo;

    //std::string requestTo = "/geo/1.0/direct?";
    //requestTo += "q=" + cityNameTo;
    //requestTo += "&limit=" + '10';
    //requestTo += "&appid=" + QW_API_KEY;

    //nlohmann::json resultTo;

    //if (auto responseTo = geoCli.Get(requestTo)) {
    //    if (responseTo->status == 200) {
    //        resultTo = nlohmann::json::parse(responseTo->body);
    //    }
    //    else {
    //        std::cout << "Bad request" << std::endl;
    //    }
    //}

    //std::string lonTo = to_string(resultTo[0]["lon"]);
    //std::string latTo = to_string(resultTo[0]["lat"]);

    //std::cout << lonTo << " " << latTo << std::endl;
//******

    WebApp cityCli("http://api.rasp.yandex.net",YA_API_KEY);
    json data;
    data = cityCli.geoCliFind(QW_API_KEY);
    cityCli.findCoordinate();
    Tools::stationsFrom(data);
    Tools::stationsTo(data);
    WebApp::stationsFindFrom(QW_API_KEY);
//******

    json resultCodeFrom;

    std::string cityCodeReqFrom = "/v3.0/nearest_settlement/?";
    cityCodeReqFrom += "apikey=" + YA_API_KEY;
    cityCodeReqFrom += "&lat=" + latFrom;
    cityCodeReqFrom += "&lng=" + lonFrom;

    if (auto responseCodeFrom = cityCodeCli.Get(cityCodeReqFrom)) {
        if (responseCodeFrom->status == 200) {
            resultCodeFrom = json::parse(responseCodeFrom->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }

    std::string codeFrom = resultCodeFrom["code"].get<std::string>();

    json resultCodeTo;

    std::string cityCodeReqTo = "/v3.0/nearest_settlement/?";
    cityCodeReqTo += "apikey=" + YA_API_KEY;
    cityCodeReqTo += "&lat=" + latTo;
    cityCodeReqTo += "&lng=" + lonTo;

    if (auto responseCodeTo = cityCodeCli.Get(cityCodeReqTo)) {
        if (responseCodeTo->status == 200) {
            resultCodeTo = json::parse(responseCodeTo->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }

    std::string codeTo = resultCodeTo["code"].get<std::string>();

    std::cout << codeTo << std::endl;

    json scheduleResult;


    std::string scheduleReq = "/v3.0/search/?";
    scheduleReq += "apikey=" + YA_API_KEY;
    scheduleReq += "&from=" + codeFrom;
    scheduleReq += "&to=" + codeTo;

    if (auto responseSchedule = cityCodeCli.Get(scheduleReq)) {
        if (responseSchedule->status == 200) {
            scheduleResult = json::parse(responseSchedule->body);
        }
        else {
            std::cout << "Bad request" << std::endl;
        }
    }

    std::cout << scheduleResult;
}