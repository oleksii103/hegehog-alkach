#include <iostream>
#include "PhoneBook.h"

int main() {
    PhoneBook contact;

    char nameBuffer[50];
    char phoneBuffer[15];
    char emailBuffer[50];

    contact.GetName(nameBuffer, sizeof(nameBuffer));
    std::cout << "Name: " << nameBuffer << std::endl;

    contact.GetPhoneNumber(phoneBuffer, sizeof(phoneBuffer));
    std::cout << "Phone Number: " << phoneBuffer << std::endl;

    contact.GetEmail(emailBuffer, sizeof(emailBuffer));
    std::cout << "Email: " << emailBuffer << std::endl;

    contactType type = contact.GetContactType();

    std::cout << "Contact Type: ";
    switch (type) {
    case Family:
        std::cout << "Family" << std::endl;
        break;
    case Friend:
        std::cout << "Friend" << std::endl;
        break;
    case Work:
        std::cout << "Work" << std::endl;
        break;
    case Other:
        std::cout << "Other" << std::endl;
        break;
    }

    return 0;
}
