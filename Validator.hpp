#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP
#include <string>

class Validator{
  public:

    /// Функция проверки строки на принадлежность требуему формату(TOML + поле brand до 16 символов)
    /// \param toml строка, которую необходимо проверить
    /// \throw "Строка не формата TOML" Не совпадает общий формат строки
    /// \throw "Проблема с полем brand" либо поле brand отсутствует, либо значение больше 16 символов
    /// \throw "Проблема с полем owner" поля owner не существует
    /// \throw "Проблема с полем mileage" либо поля mileage не существует, либо значение не число

    static void validate(const std::string& object);
};

#endif
