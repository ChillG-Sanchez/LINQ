#ifndef METHODS_H
#define METHODS_H

#include "Product.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

void PrintAllProducts(const std::vector<Product>& products) {
    for (const auto& product : products) {
        std::wcout << product.ToString() << std::endl;
    }
}

void GroupByCategory(const std::vector<Product>& products) {
    std::map<std::wstring, std::vector<Product> > groupedProducts;

    for (const auto& product : products) {
        groupedProducts[product.category].push_back(product);
    }

    for (const auto& pair : groupedProducts) {
        std::wcout << L"Kategória: " << pair.first << std::endl;
        for (const auto& product : pair.second) {
            std::wcout << L"  " << product.ToString() << std::endl;
        }
    }
}

void CountByCategory(const std::vector<Product>& products) {
    std::map<std::wstring, int> categoryCounts;

    for (const auto& product : products) {
        categoryCounts[product.category]++;
    }

    for (const auto& pair : categoryCounts) {
        std::wcout << L"Kategória: " << pair.first << L", Termékek száma: " << pair.second << std::endl;
    }
}

void GroupByPriceRange(const std::vector<Product>& products) {
    std::map<std::wstring, std::vector<Product>> priceRanges = {
        {L"0–50.000 Ft", {}},
        {L"50.001–100.000 Ft", {}},
        {L"100.001 Ft felett", {}}
    };

    for (const auto& product : products) {
        if (product.price <= 50000) {
            priceRanges[L"0–50.000 Ft"].push_back(product);
        } else if (product.price <= 100000) {
            priceRanges[L"50.001–100.000 Ft"].push_back(product);
        } else {
            priceRanges[L"100.001 Ft felett"].push_back(product);
        }
    }

    for (const auto& pair : priceRanges) {
        std::wcout << L"Árkategória: " << pair.first << std::endl;
        for (const auto& product : pair.second) {
            std::wcout << L"  " << product.ToString() << std::endl;
        }
    }
}

void MostExpensiveByCategory(const std::vector<Product>& products) {
    std::map<std::wstring, Product> mostExpensiveProducts;

    for (const auto& product : products) {
        if (mostExpensiveProducts.find(product.category) == mostExpensiveProducts.end() || 
            product.price > mostExpensiveProducts[product.category].price) {
            mostExpensiveProducts[product.category] = product;
        }
    }

    for (const auto& pair : mostExpensiveProducts) {
        std::wcout << L"Kategória: " << pair.first << L", Legdrágább termék: " << pair.second.ToString() << std::endl;
    }
}

void AveragePriceByCategory(const std::vector<Product>& products) {
    std::map<std::wstring, std::vector<Product>> groupedProducts;

    for (const auto& product : products) {
        groupedProducts[product.category].push_back(product);
    }

    for (const auto& pair : groupedProducts) {
        double total = std::accumulate(pair.second.begin(), pair.second.end(), 0.0, 
            [](double sum, const Product& product) { return sum + product.price; });
        double average = total / pair.second.size();
        std::wcout << L"Kategória: " << pair.first << L", Átlagár: " << average << L" Ft" << std::endl;
    }
}

void SearchByCategory(const std::vector<Product>& products, const std::wstring& category) {
    std::wcout << L"Keresés kategória szerint: " << category << std::endl;
    for (const auto& product : products) {
        if (product.category == category) {
            std::wcout << product.ToString() << std::endl;
        }
    }
}

void GroupByFirstLetter(const std::vector<Product>& products) {
    std::map<wchar_t, std::vector<Product>> groupedProducts;

    for (const auto& product : products) {
        wchar_t firstLetter = product.name[0];
        groupedProducts[firstLetter].push_back(product);
    }

    for (const auto& pair : groupedProducts) {
        std::wcout << L"Betű: " << pair.first << std::endl;
        for (const auto& product : pair.second) {
            std::wcout << L"  " << product.ToString() << std::endl;
        }
    }
}

void GroupByPriceRangeAndSum(const std::vector<Product>& products) {
    std::map<std::wstring, std::vector<Product>> priceRanges = {
        {L"0–50.000 Ft", {}},
        {L"50.001–100.000 Ft", {}},
        {L"100.001 Ft felett", {}}
    };

    for (const auto& product : products) {
        if (product.price <= 50000) {
            priceRanges[L"0–50.000 Ft"].push_back(product);
        } else if (product.price <= 100000) {
            priceRanges[L"50.001–100.000 Ft"].push_back(product);
        } else {
            priceRanges[L"100.001 Ft felett"].push_back(product);
        }
    }

    for (const auto& pair : priceRanges) {
        double total = std::accumulate(pair.second.begin(), pair.second.end(), 0.0, 
            [](double sum, const Product& product) { return sum + product.price; });
        std::wcout << L"Árkategória: " << pair.first << L", Összesített érték: " << total << L" Ft" << std::endl;
    }
}

void CheapestByCategory(const std::vector<Product>& products) {
    std::map<std::wstring, Product> cheapestProducts;

    for (const auto& product : products) {
        if (cheapestProducts.find(product.category) == cheapestProducts.end() || 
            product.price < cheapestProducts[product.category].price) {
            cheapestProducts[product.category] = product;
        }
    }

    for (const auto& pair : cheapestProducts) {
        std::wcout << L"Kategória: " << pair.first << L", Legolcsóbb termék: " << pair.second.ToString() << std::endl;
    }
}

void GroupByOddEvenPrice(const std::vector<Product>& products) {
    std::map<std::wstring, std::vector<Product>> groupedProducts = {
        {L"Páros ár", {}},
        {L"Páratlan ár", {}}
    };

    for (const auto& product : products) {
        if (static_cast<int>(product.price) % 2 == 0) {
            groupedProducts[L"Páros ár"].push_back(product);
        } else {
            groupedProducts[L"Páratlan ár"].push_back(product);
        }
    }

    for (const auto& pair : groupedProducts) {
        std::wcout << L"Csoport: " << pair.first << std::endl;
        for (const auto& product : pair.second) {
            std::wcout << L"  " << product.ToString() << std::endl;
        }
    }
}

void CountAndSumByCategory(const std::vector<Product>& products) {
    std::map<std::wstring, std::vector<Product>> groupedProducts;

    for (const auto& product : products) {
        groupedProducts[product.category].push_back(product);
    }

    for (const auto& pair : groupedProducts) {
        int count = pair.second.size();
        double total = std::accumulate(pair.second.begin(), pair.second.end(), 0.0, 
            [](double sum, const Product& product) { return sum + product.price; });
        std::wcout << L"Kategória: " << pair.first << L", Termékek száma: " << count << L", Összesített érték: " << total << L" Ft" << std::endl;
    }
}

template<typename Func>
void GroupByCustom(const std::vector<Product>& products, Func func) {
    std::map<std::wstring, std::vector<Product>> groupedProducts;

    for (const auto& product : products) {
        groupedProducts[func(product)].push_back(product);
    }

    for (const auto& pair : groupedProducts) {
        std::wcout << L"Csoport: " << pair.first << std::endl;
        for (const auto& product : pair.second) {
            std::wcout << L"  " << product.ToString() << std::endl;
        }
    }
}

void Top3ProductsByCategory(const std::vector<Product>& products) {
    std::map<std::wstring, std::vector<Product>> groupedProducts;

    for (const auto& product : products) {
        groupedProducts[product.category].push_back(product);
    }

    for (auto& pair : groupedProducts) {
        std::sort(pair.second.begin(), pair.second.end(), [](const Product& a, const Product& b) {
            return a.price > b.price;
        });

        std::wcout << L"Kategória: " << pair.first << std::endl;
        for (size_t i = 0; i < pair.second.size() && i < 3; ++i) {
            std::wcout << L"  " << pair.second[i].ToString() << std::endl;
        }
    }
}

void ListAllProducts(const std::vector<Product>& products) {
    std::wcout << L"Összes termék:" << std::endl;
    for (const auto& product : products) {
        std::wcout << product.ToString() << std::endl;
    }
}

void PriceDifferenceByCategory(const std::vector<Product>& products) {
    std::map<std::wstring, std::vector<Product>> groupedProducts;

    for (const auto& product : products) {
        groupedProducts[product.category].push_back(product);
    }

    for (const auto& pair : groupedProducts) {
        if (!pair.second.empty()) {
            auto minmax = std::minmax_element(pair.second.begin(), pair.second.end(), [](const Product& a, const Product& b) {
                return a.price < b.price;
            });
            double difference = minmax.second->price - minmax.first->price;
            std::wcout << L"Kategória: " << pair.first << L", Ár különbség: " << difference << L" Ft" << std::endl;
        }
    }
}

void CategoriesWithAveragePriceAbove(const std::vector<Product>& products, double threshold) {
    std::map<std::wstring, std::vector<Product>> groupedProducts;

    for (const auto& product : products) {
        groupedProducts[product.category].push_back(product);
    }

    for (const auto& pair : groupedProducts) {
        double total = std::accumulate(pair.second.begin(), pair.second.end(), 0.0, 
            [](double sum, const Product& product) { return sum + product.price; });
        double average = total / pair.second.size();
        if (average > threshold) {
            std::wcout << L"Kategória: " << pair.first << L", Átlagár: " << average << L" Ft" << std::endl;
        }
    }
}

#endif