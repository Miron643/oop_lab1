#include "./heads/Car.hpp"
#include "./heads/CarSerializer.hpp"
#include "./heads/Validator.hpp"
#include <iostream>
#include <fstream>

int main(){
    Car car("","",0);
    std::ifstream f("file.txt");
    std::string str, token;
    getline(f, str);
    while (getline(f, token))
        str += "\n" + token;

    try{
        car = Serializer::transform(str);
    }
    catch (const std::string& err_message){
        std::cout << err_message << std::endl;
        return 0;
    }

    std::cout << "str -> car: " << std::endl << std::endl;
    std::cout << "brand: " << car.get_brand() << std::endl;
    std::cout << "owner: " << car.get_owner() << std::endl;
    std::cout << "mileage: " << car.get_mileage() << std::endl << std::endl;

    str = Serializer::transform_car(car);

    std::cout << "car->str:" << std::endl << std::endl;
    std::cout << str << std::endl << std::endl;

    car = Serializer::transform(str.c_str());
    car = Serializer::transform(str.c_str(), str.size());

    std::cout << "const char* (+size_t) -> car" << std::endl << std::endl;
    std::cout << "brand: " << car.get_brand() << std::endl;
    std::cout << "owner: " << car.get_owner() << std::endl;
    std::cout << "mileage: " << car.get_mileage() << std::endl << std::endl;

    return 0;
}

