#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    int id;
    std::wstring name;
    double price;
    std::wstring category;

    Product() : id(0), name(L""), price(0.0), category(L"") {}

    Product(int id, std::wstring name, double price, std::wstring category)
        : id(id), name(name), price(price), category(category) {}

    std::wstring ToString() const {
        return L"ID: " + std::to_wstring(id) + L", Név: " + name + L", Ár: " + std::to_wstring(price) + L", Kategória: " + category;
    }
};

#endif