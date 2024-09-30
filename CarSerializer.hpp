#ifndef CARSERIALIZER_HPP
#define CARSERIALIZER_HPP
#include "Car.hpp"

class Serializer{
  public:

    /// Функция удаления символов из начала и конца строки
    /// \param obj строка, из которой необходимо удалить символы

    static void trim(std::string& obj);

    /// Функция перевода из (const char*) в структуру Car
    /// \param toml с-строка, которую надо перевести
    /// \return объект класса Car

    static Car transform(const char* object);

    /// Функция перевода из (const char*) в структуру Car
    /// \param toml с-строка, которую надо перевести
    /// \param length длина этой строки
    /// \return объект класса Car

    static Car transform(const char* object, size_t size);

    /// Функция перевода из строки в структуру Car
    /// \param toml строка, которую надо перевести
    /// \return объект класса Car

    static Car transform(const std::string& object);

    /// Функция перевода из Car в строку формата toml
    /// \param car объект класса Car
    /// \return требуемая строка формата toml

    static std::string transform_car(const Car& object);
};

#endif
