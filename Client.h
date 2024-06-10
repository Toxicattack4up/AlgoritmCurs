#pragma once
#include <string>

class Client 
{
private:
    int id;
    std::string name;
    std::string rental_info;

public:
    // Конструкторы
    Client();
    Client(int id, const std::string& name, const std::string& rental_info);

    // Методы доступа
    int getId() const;
    void setId(int id);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getRentalInfo() const;
    void setRentalInfo(const std::string& rental_info);
};