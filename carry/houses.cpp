#include <iostream>
#include <cstring>

using namespace std;

class Person {
    char* name;
public:
    Person(const char* name = "Unknown") {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Person(const Person& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

    Person& operator=(const Person& other) {
        if (this == &other) return *this;

        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        return *this;
    }

    ~Person() {
        delete[] name;
    }

    void print() const {
        cout << "Person: " << name << endl;
    }
};

class Apartment {
    Person* people;
    int number_of_people;

public:
    Apartment(int num_people = 1) : number_of_people(num_people) {
        people = new Person[number_of_people];
    }

    Apartment(const Apartment& other) : number_of_people(other.number_of_people) {
        people = new Person[number_of_people];
        for (int i = 0; i < number_of_people; i++) {
            people[i] = other.people[i];
        }
    }

    Apartment& operator=(const Apartment& other) {
        if (this == &other) return *this;

        delete[] people;
        number_of_people = other.number_of_people;
        people = new Person[number_of_people];
        for (int i = 0; i < number_of_people; i++) {
            people[i] = other.people[i];
        }

        return *this;
    }

    ~Apartment() {
        delete[] people;
    }

    void print() const {
        cout << "Apartment with " << number_of_people << " people:\n";
        for (int i = 0; i < number_of_people; i++) {
            people[i].print();
        }
    }
};

class House {
    Apartment* apartments;
    int number_of_apartments;

public:
    House(int num_apartments = 1) : number_of_apartments(num_apartments) {
        apartments = new Apartment[number_of_apartments];
    }

    House(const House& other) : number_of_apartments(other.number_of_apartments) {
        apartments = new Apartment[number_of_apartments];
        for (int i = 0; i < number_of_apartments; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    House& operator=(const House& other) {
        if (this == &other) return *this;

        delete[] apartments;
        number_of_apartments = other.number_of_apartments;
        apartments = new Apartment[number_of_apartments];
        for (int i = 0; i < number_of_apartments; i++) {
            apartments[i] = other.apartments[i];
        }

        return *this;
    }

    ~House() {
        delete[] apartments;
    }

    void print() const {
        cout << "House with " << number_of_apartments << " apartments:\n";
        for (int i = 0; i < number_of_apartments; i++) {
            apartments[i].print();
        }
    }
};

int main() {
    House house(2);
    house.print();

    return 0;
}
