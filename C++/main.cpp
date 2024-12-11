#include "Product.h"
#include "Methods.h"
#include <vector>

int main() {
    std::vector<Product> products = {
        Product(1, "Laptop", 150000, "elektronikai"),
        Product(2, "Mikrohullámú sütő", 30000, "konyhai"),
        Product(3, "Kanapé", 80000, "divatbútor"),
        Product(4, "Toll", 500, "irodaszer"),
        Product(5, "Porszívó", 40000, "háztartás"),
        Product(6, "Okostelefon", 120000, "elektronikai"),
        Product(7, "Kenyérpirító", 10000, "konyhai"),
        Product(8, "Íróasztal", 60000, "divatbútor"),
        Product(9, "Jegyzetfüzet", 1000, "irodaszer"),
        Product(10, "Mosógép", 90000, "háztartás"),
        Product(11, "Tablet", 80000, "elektronikai"),
        Product(12, "Kávéfőző", 20000, "konyhai"),
        Product(13, "Szék", 20000, "divatbútor"),
        Product(14, "Ceruza", 300, "irodaszer"),
        Product(15, "Hűtőszekrény", 100000, "háztartás"),
        Product(16, "Monitor", 50000, "elektronikai"),
        Product(17, "Serpenyő", 5000, "konyhai"),
        Product(18, "Polc", 15000, "divatbútor"),
        Product(19, "Tűzőgép", 2000, "irodaszer"),
        Product(20, "Vasaló", 15000, "háztartás")
    };

    std::cout << "1. feladat: Az összes termék kiírása" << std::endl;
    PrintAllProducts(products);
    std::cout << "1. feladat: A termékek csoportosítása" << std::endl;
    GroupByCategory(products);
    std::cout << "1. feladat: A termékek csoportonkénti számlálása" << std::endl;
    CountByCategory(products);
    std::cout << "2. feladat: Termékek csoportosítása árkategóriák szerint" << std::endl;
    GroupByPriceRange(products);
    std::cout << "3. feladat: Legdrágább termék kategóriánként" << std::endl;
    MostExpensiveByCategory(products);
    std::cout << "4. feladat: Termékek átlagárának kiszámítása kategóriánként" << std::endl;
    AveragePriceByCategory(products);

    return 0;
}