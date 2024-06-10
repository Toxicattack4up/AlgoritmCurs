#include "Client.h"

// Конструкторы
Client::Client() : id(0), name(""), rental_info("") {}

Client::Client(int id, const std::string& name, const std::string& rental_info)
    : id(id), name(name), rental_info(rental_info) {}

// Методы доступа
int Client::getId() const 
{
    return id;
}

void Client::setId(int id) 
{
    this->id = id;
}

std::string Client::getName() const 
{
    return name;
}

void Client::setName(const std::string& name) 
{
    this->name = name;
}

std::string Client::getRentalInfo() const 
{
    return rental_info;
}

void Client::setRentalInfo(const std::string& rental_info) 
{
    this->rental_info = rental_info;
}