#ifndef CAR_HPP
#define CAR_HPP
#include <string>

class Car{
        std::string brand;
        std::string owner;
        double mileage;
    public:

        /// Обычный конструктор с одним параметром по умолчанию, если машина новая(пробег 0)

        Car(std::string brand, std::string owner, double mileage = 0.0):
            brand(brand), owner(owner), mileage(mileage) {}

        /// Функция просмотра поля brand
        /// \return поле brand

        std::string get_brand() const;

        /// Функция просмотра поля owner
        /// return поле owner

        std::string get_owner() const;

        /// Функция просмотра поля mileage
        /// \return поле mileage

        double get_mileage() const;

        /// Функция заполнения поля brand с проверкой на длину строки
        /// \param brand Новый бренд

        void set_brand(std::string brand);

        /// Функция заполнения поля owner
        /// \param owner Новый владелец

        void set_owner(std::string owner);

        /// Функция заполнения поля mileage
        /// \param mileage Новый пробег

        void set_mileage(double mileage);
};

#endif
