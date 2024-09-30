#include "./heads/CarSerializer.hpp"
#include "./heads/Validator.hpp"
#include <string>
#include <sstream>

void Serializer::trim(std::string& obj){
    size_t last = obj.find_last_not_of(" \t\n");
    size_t first = obj.find_first_not_of(" \t\n");
    obj.erase((obj.begin() + last + 1), obj.end());
    obj.erase(obj.begin(), (obj.begin() + first));
}

Car Serializer::transform(const char* toml){
    return transform(std::string(toml));
}

Car Serializer::transform(const char* toml, size_t length){
    return transform(std::string(toml, length));
}

Car Serializer::transform(const std::string& toml){
    Validator::validate(toml);
    std::istringstream sstoml(toml);
    std::string token, owner, brand;
    double mileage;

    while (getline(sstoml, token, '\n')){
        if (token.find("=") != std::string::npos){
            std::istringstream sstoken(token);

            std::string key;
            getline(sstoken, key, '=');
            trim(key);

            std::string value;
            getline(sstoken, value, '=');
            trim(value);

            if (key == "owner")
                owner = value;
            if (key == "brand")
                brand = value;
            if (key == "mileage")
                mileage = std::stod(value);
        }
    }

    owner.erase(owner.begin(), std::next(owner.begin()));
    owner.erase(std::prev(owner.end()), owner.end());

    brand.erase(brand.begin(), std::next(brand.begin()));
    brand.erase(std::prev(brand.end()), brand.end());

    return Car(brand, owner, mileage);
}

std::string Serializer::transform_car(const Car& object){
    std::string toml("[car]\n");
    toml += "brand = \"" + object.get_brand() + "\"\n";
    toml += "owner = \"" + object.get_owner() + "\"\n";
    toml += "mileage = " + std::to_string(object.get_mileage());
    return toml;
}
