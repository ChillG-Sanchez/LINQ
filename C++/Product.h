#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    int id;
    std::string name;
    double price;
    std::string category;

    Product() : id(0), name(""), price(0.0), category("") {}

    Product(int id, std::string name, double price, std::string category)
        : id(id), name(name), price(price), category(category) {}

    std::string ToString() const {
        return "ID: " + std::to_string(id) + ", Név: " + name + ", Ár: " + std::to_string(price) + ", Kategória: " + category;
    }
};

#endif