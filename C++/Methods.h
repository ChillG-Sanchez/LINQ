#ifndef METHODS_H
#define METHODS_H

#include "Product.h"
#include <vector>
#include <map>
#include <iostream>
#include <numeric>


void PrintAllProducts(const std::vector<Product>& products) {
    for (const auto& product : products) {
        std::cout << product.ToString() << std::endl;
    }
}

void GroupByCategory(const std::vector<Product>& products) {
    std::map<std::string, std::vector<Product> > groupedProducts;

    for (const auto& product : products) {
        groupedProducts[product.category].push_back(product);
    }

    for (const auto& pair : groupedProducts) {
        std::cout << "Kategória: " << pair.first << std::endl;
        for (const auto& product : pair.second) {
            std::cout << "  " << product.ToString() << std::endl;
        }
    }
}

void CountByCategory(const std::vector<Product>& products) {
    std::map<std::string, int> categoryCounts;

    for (const auto& product : products) {
        categoryCounts[product.category]++;
    }

    for (const auto& pair : categoryCounts) {
        std::cout << "Kategória: " << pair.first << ", Termékek száma: " << pair.second << std::endl;
    }
}

void GroupByPriceRange(const std::vector<Product>& products) {
    std::map<std::string, std::vector<Product>> priceRanges = {
        {"0–50.000 Ft", {}},
        {"50.001–100.000 Ft", {}},
        {"100.001 Ft felett", {}}
    };

    for (const auto& product : products) {
        if (product.price <= 50000) {
            priceRanges["0–50.000 Ft"].push_back(product);
        } else if (product.price <= 100000) {
            priceRanges["50.001–100.000 Ft"].push_back(product);
        } else {
            priceRanges["100.001 Ft felett"].push_back(product);
        }
    }

    for (const auto& pair : priceRanges) {
        std::cout << "Árkategória: " << pair.first << std::endl;
        for (const auto& product : pair.second) {
            std::cout << "  " << product.ToString() << std::endl;
        }
    }
}

void MostExpensiveByCategory(const std::vector<Product>& products) {
    std::map<std::string, Product> mostExpensiveProducts;

    for (const auto& product : products) {
        if (mostExpensiveProducts.find(product.category) == mostExpensiveProducts.end() || 
            product.price > mostExpensiveProducts[product.category].price) {
            mostExpensiveProducts[product.category] = product;
        }
    }

    for (const auto& pair : mostExpensiveProducts) {
        std::cout << "Kategória: " << pair.first << ", Legdrágább termék: " << pair.second.ToString() << std::endl;
    }
}

void AveragePriceByCategory(const std::vector<Product>& products) {
    std::map<std::string, std::vector<Product>> groupedProducts;

    for (const auto& product : products) {
        groupedProducts[product.category].push_back(product);
    }

    for (const auto& pair : groupedProducts) {
        double total = std::accumulate(pair.second.begin(), pair.second.end(), 0.0, 
            [](double sum, const Product& product) { return sum + product.price; });
        double average = total / pair.second.size();
        std::cout << "Kategória: " << pair.first << ", Átlagár: " << average << " Ft" << std::endl;
    }
}


#endif // METHODS_H