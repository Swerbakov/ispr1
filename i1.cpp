#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }
};

int main() {
    std::ifstream inputFile("in.txt");
    if (!inputFile.is_open()) {
        return 1;
    }

    int n;
    inputFile >> n;

    Address** addresses = new Address*[n];

    for (int i = 0; i < n; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        inputFile >> city;
        inputFile >> street;
        inputFile >> houseNumber;
        inputFile >> apartmentNumber;

        addresses[i] = new Address(city, street, houseNumber, apartmentNumber);
    }

    inputFile.close();

    std::ofstream outputFile("out.txt");
    if (!outputFile.is_open()) {
        return 1;
    }

    outputFile << n << std::endl;

    for (int i = n - 1; i >= 0; --i) {
        outputFile << addresses[i]->getOutputAddress() << std::endl;
    }

    outputFile.close();

    for (int i = 0; i < n; ++i) {
        delete addresses[i];
    }
    delete[] addresses;

    return 0;
}
