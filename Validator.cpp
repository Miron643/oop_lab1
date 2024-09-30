#include "./heads/Validator.hpp"
#include <iostream>
#include <string>
#include <regex>

void Validator::validate(const std::string& toml){
    std::regex regular1("([ \n]*(.[a-zA-Z_]+.)?[ \n]*)([a-zA-Z_]+ *= *[a-zA-Z0-9._\"]+[ \n]*)+");
    if (!std::regex_match(toml, regular1))
        throw std::string("Строка не формата TOML");

    std::regex regular2("brand *= *\"([a-zA-Z _]{1,16})\"");
    if (!std::regex_search(toml, regular2))
        throw std::string("Проблема с полем brand");
    
    std::regex regular3("owner *= *\"([a-zA-Z]+)\"");
    if (!std::regex_search(toml, regular3))
        throw std::string("Проблема с полем owner");

    std::regex regular4("mileage *= *([0-9]+).?([0-9]*)");
    if (!std::regex_search(toml, regular4))
        throw std::string("Проблема с полем mileage");
}
