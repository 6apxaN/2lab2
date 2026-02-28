#include "Country.h"

int main() {
    setlocale(LC_ALL, "RUS");
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<std::string> cities1 = { "Бор", "Сырный", "Алергия" };
    Country country1("Империя", "Алергия", cities1, 150.32);

    std::vector<std::string> cities2 = { "Морс", "Вектор", "Бор" };
    Country country2("Республика", "Вектор", cities2, 100.12);

    country1.displayInfo();
    country2.displayInfo();

    Country plus = country1 + country2;
    plus.displayInfo();

    Country mult = country1 * country2;
    mult.displayInfo();

    country1 += country2;
    country1.displayInfo();

    return 0;
}
