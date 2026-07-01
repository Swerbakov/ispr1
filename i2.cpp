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

    std::string getCity() const {
        return city;
    }

    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }
};

void sort(Address** addresses, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (addresses[j]->getCity() > addresses[j + 1]->getCity()) {
                Address* temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            }
        }
    }
}

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

    sort(addresses, n);

    std::ofstream outputFile("out.txt");
    if (!outputFile.is_open()) {
        return 1;
    }

    outputFile << n << std::endl;

    for (int i = 0; i < n; ++i) {
        outputFile << addresses[i]->getOutputAddress() << std::endl;
    }

    outputFile.close();

    for (int i = 0; i < n; ++i) {
        delete addresses[i];
    }
    delete[] addresses;

    return 0;
}
