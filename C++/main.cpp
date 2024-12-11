#include "Product.h"
#include "Methods.h"
#include <vector>
#include <iostream>
#include <locale>

int main() {

    std::locale::global(std::locale("hu_HU.UTF-8"));
    std::wcout.imbue(std::locale("hu_HU.UTF-8"));
    std::wcin.imbue(std::locale("hu_HU.UTF-8"));

    std::vector<Product> products = {
        Product(1, L"Laptop", 150000, L"elektronikai"),
        Product(2, L"Mikrohullámú sütő", 30000, L"konyhai"),
        Product(3, L"Kanapé", 80000, L"divatbútor"),
        Product(4, L"Toll", 500, L"irodaszer"),
        Product(5, L"Porszívó", 40000, L"háztartás"),
        Product(6, L"Okostelefon", 120000, L"elektronikai"),
        Product(7, L"Kenyérpirító", 10000, L"konyhai"),
        Product(8, L"Íróasztal", 60000, L"divatbútor"),
        Product(9, L"Jegyzetfüzet", 1000, L"irodaszer"),
        Product(10, L"Mosógép", 90000, L"háztartás"),
        Product(11, L"Tablet", 80000, L"elektronikai"),
        Product(12, L"Kávéfőző", 20000, L"konyhai"),
        Product(13, L"Szék", 20000, L"divatbútor"),
        Product(14, L"Ceruza", 299, L"irodaszer"),
        Product(15, L"Hűtőszekrény", 100000, L"háztartás"),
        Product(16, L"Monitor", 50000, L"elektronikai"),
        Product(17, L"Serpenyő", 4990, L"konyhai"),
        Product(18, L"Polc", 15000, L"divatbútor"),
        Product(19, L"Tűzőgép", 2000, L"irodaszer"),
        Product(20, L"Vasaló", 15000, L"háztartás")
    };

    std::wcout << L"1. feladat: Az összes termék kiírása" << std::endl;
    PrintAllProducts(products);
    std::wcout << L"1. feladat: Termékek csoportosítása kategóriák szerint" << std::endl;
    GroupByCategory(products);
    std::wcout << L"1. feladat: Termékek számának meghatározása kategóriánként" << std::endl;
    CountByCategory(products);
    std::wcout << L"2. feladat: Termékek csoportosítása árkategóriák szerint" << std::endl;
    GroupByPriceRange(products);
    std::wcout << L"3. feladat: Legdrágább termék kategóriánként" << std::endl;
    MostExpensiveByCategory(products);
    std::wcout << L"4. feladat: Termékek átlagárának kiszámítása kategóriánként" << std::endl;
    AveragePriceByCategory(products);
    std::wcout << L"5. feladat: Adott kategóriába tartozó termékek keresése" << std::endl;
    SearchByCategory(products, L"elektronikai");
    std::wcout << L"6. feladat: Termékek csoportosítása kezdőbetű szerint" << std::endl;
    GroupByFirstLetter(products);
    std::wcout << L"7. feladat: Termékek csoportosítása árkategóriák szerint és összegzés" << std::endl;
    GroupByPriceRangeAndSum(products);
    std::wcout << L"8. feladat: Legolcsóbb termék kategóriánként" << std::endl;
    CheapestByCategory(products);
    std::wcout << L"9. feladat: Termékek csoportosítása áruk páratlan vagy páros volta szerint" << std::endl;
    GroupByOddEvenPrice(products);
    std::wcout << L"10. feladat: Termékek száma és összértéke kategóriánként" << std::endl;
    CountAndSumByCategory(products);
    std::wcout << L"11. feladat: Termékek dinamikus csoportosítása név szerint" << std::endl;
    GroupByCustom(products, [](const Product& product) { return product.name; });
    std::wcout << L"11. feladat: Termékek dinamikus csoportosítása kategória szerint" << std::endl;
    GroupByCustom(products, [](const Product& product) { return product.category; });
    std::wcout << L"12. feladat: Top 3 termék minden kategóriában ár szerint" << std::endl;
    Top3ProductsByCategory(products);
    std::wcout << L"13. feladat: Az összes termék listázása csoportosítás nélkül" << std::endl;
    ListAllProducts(products);
    std::wcout << L"14. feladat: Legnagyobb és legkisebb ár közötti különbség kategóriánként" << std::endl;
    PriceDifferenceByCategory(products);
    std::wcout << L"15. feladat: Kategóriák, ahol az átlagár meghaladja a 75.000 Ft-ot" << std::endl;
    CategoriesWithAveragePriceAbove(products, 75000);


    return 0;
}