#include "Country.h"

Country::Country() : name(""), capital(""), area(0.0) {}

Country::Country(const std::string& name, const std::string& capital,
    const std::vector<std::string>& cities, float area) {
    this->name = name;
    this->capital = capital;
    this->cities = cities;
    this->area = area;
}

Country::Country(const Country& other) : name(other.name),
capital(other.capital), cities(other.cities), area(other.area) {
}

Country::~Country() {
    cities.clear();
    std::cout << "Декстутор вызван для " << name << std::endl;
}

std::string Country::getName() const { return name; }
std::string Country::getCapital() const { return capital; }
float Country::getArea() const { return area; }
const std::vector<std::string>& Country::getCities() const { return cities; }

void Country::setCapital(const std::string& newCapital) {
    bool valid = true;
    for (char c : newCapital) {
        if (c>16 && c != ' ') {
            valid = false;
            break;
        }
    }
    if (valid && !newCapital.empty()) {
        bool cityExists = false;
        for (const auto& city : cities) {
            if (city == newCapital) {
                cityExists = true;
                break;
            }
        }
        if (!cityExists) {
            cities.push_back(newCapital);
        }
        capital = newCapital;
        std::cout << "Столица изменана на" << capital << std::endl;
    }
    else {
        std::cout << "Ошибка: название столицы должно содержать только буквы и пробелы" << std::endl;
    }
}

void Country::setName(const std::string& n) { name = n; }

void Country::setArea(float a) {
    if (a >= 0) {
        area = a;
    }
    else {
        std::cout << "Ошибка площадь не может быть отрицательной" << std::endl;
    }
}

void Country::setCities(const std::vector<std::string>& newCities) {
    cities = newCities;
}

void Country::displayInfo() const {
    std::cout << "\n==========================" << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Столица: " << capital << std::endl;
    if (!cities.empty()) {
        std::cout << "Города: ";
        for (size_t i = 0; i < cities.size(); i++) {
            std::cout << cities[i];
            if (i < cities.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "Площадь: " << area << " êâ. êì" << std::endl;
    std::cout << "===========================\n" << std::endl;
}

void Country::addArea(float newArea) {
    if (newArea > 0) {
        area += newArea;
        std::cout << "Территория увеличена на " << newArea
            << " кв. км. Новая площадь: " << area << " кв. км" << std::endl;
    }
    else {
        std::cout << "Ошибка площадь должна быть положительной" << std::endl;
    }
}

Country Country::operator=(const Country& other) {
    if (this == &other) {
        return *this;
    }
    name = other.name;
    capital = other.capital;
    cities = other.cities;
    area = other.area;
    return *this;
}

Country Country::operator+=(const Country& other)
{
    this->name = this->name + "-" + other.name;
    if (other.area > this->area) {
        this->capital = other.capital;
    }
    this->area = this->area + other.area;
    for (const auto& cityFromOther : other.cities) {
        bool found = false;
        for (const auto& cityInResult : this->cities) {
            if (cityInResult == cityFromOther) {
                found = true;
                break;
            }
        }
        if (found) {
            this->cities.push_back(cityFromOther + " новый");
        }
        else {
            this->cities.push_back(cityFromOther);
        }
    }
    return *this;
}

Country Country::operator+(const Country& other) const {
    Country result;
    result.name = this->name + "-" + other.name;
    if (this->area >= other.area) {
        result.capital = this->capital;
    }
    else {
        result.capital = other.capital;
    }
    result.area = this->area + other.area;
    result.cities = this->cities;

    for (const auto& cityFromOther : other.cities) {
        bool found = false;
        for (const auto& cityInResult : result.cities) {
            if (cityInResult == cityFromOther) {
                found = true;
                break;
            }
        }
        if (found) {
            result.cities.push_back(cityFromOther + " новый");
        }
        else {
            result.cities.push_back(cityFromOther);
        }
    }
    return result;
}





Country Country::operator*(const Country& other) const {
    Country result;
    result.name = "ïóòü " + this->name + "->" + other.name;
    result.capital = "íåò";
    result.area = (this->area < other.area) ? this->area : other.area;
 
    if (!this->capital.empty()) {
        result.cities.push_back(this->capital);
    }
    if (!other.capital.empty()) {
        if (this->capital == other.capital) {
            result.cities.push_back(other.capital + " новый");
        }
        else {
            result.cities.push_back(other.capital);
        }
    }
    if (!this->cities.empty()) {
        int d = std::rand()%this->cities.size();
        int j;
        for (int i = 0; i < this->cities.size(); i++)
        {
            if (this->cities[i] == this->capital)
            {
                j = i;
                break;
            }
        }
        if (d == j and j != 1)
        {
            d = d - j + 1;
        }
        else {
            if (d == j and j == 1)
            {
                d = d - j;
            }
        }
        std::string firstCity = this->cities[d];
        bool alreadyExists = false;
        if (firstCity==this->capital)
        {   if (d==this->cities.size())
            {
            d = 0;
            }

            std::string firstCity = this->cities[d+1]; 
        }
        for (const auto& existingCity : result.cities) {
            if (existingCity == firstCity ) {
                alreadyExists = true;
                break;
            }
        }
        if (alreadyExists) {
            result.cities.push_back(firstCity + " новый");
        }
        else {
            result.cities.push_back(firstCity);
        }
    }
    if (!other.cities.empty()) {
        int d = std::rand() % other.cities.size();
        int j;
        for (int i=0;i<other.cities.size();i++)
        { if (other.cities[i]==other.capital)
          {
            j = i;
            break;
          }
        }
        if (d==j and j!=1)
        {
            d = d - j + 1;
        }
        else {
            if (d == j and j == 1)
            {
                d = d - j;
            }
        }
        std::string secondCity = other.cities[d];
        bool alreadyExists = false;
       
        for (const auto& existingCity : result.cities) {
            if (existingCity == secondCity) {
                alreadyExists = true;
                break;
            }
        }
        if (alreadyExists) {
            result.cities.push_back(secondCity + " новый");
        }
        else {
            result.cities.push_back(secondCity);
        }
    }
    return result;
}



