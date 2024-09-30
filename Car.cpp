#include <iostream>
#include "./heads/Car.hpp"
#include <string>


std::string Car::get_brand() const { return brand;}

std::string Car::get_owner() const { return owner;}

double Car::get_mileage() const { return mileage;}

void Car::set_brand(std::string brand) {
    if (brand.size() <= 16)
	this->brand = brand;
}

void Car::set_owner(std::string owner) { this->owner = owner;}

void Car::set_mileage(double mileage) { this->mileage = mileage;}
