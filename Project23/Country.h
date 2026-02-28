#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Country {
private:
    std::string name;
    std::string capital;
    std::vector<std::string> cities;

protected:
    float area;

public:
    Country();
    Country(const std::string& name, const std::string& capital,
        const std::vector<std::string>& cities, float area);
    Country(const Country& other);

    ~Country();

    std::string getName() const;
    std::string getCapital() const;
    float getArea() const;
    const std::vector<std::string>& getCities() const;

    void setCapital(const std::string& newCapital);
    void setName(const std::string& n);
    void setArea(float a);
    void setCities(const std::vector<std::string>& newCities);

    void displayInfo() const;
    void addArea(float newArea);

    Country operator=(const Country& other);
    Country& operator+=(const Country& other);
    Country operator+(const Country& other) const;
    Country operator*(const Country& other) const;
};

