#pragma once

enum contactType {
    Family, Friend, Work, Other
};

class PhoneBook {
public:
    PhoneBook();

    void GetName(char* buffer, int bufferSize);
    void GetPhoneNumber(char* buffer, int bufferSize);
    void GetEmail(char* buffer, int bufferSize);
    contactType GetContactType();

private:
    char name[50];
    char phoneNumber[15];
    char email[50];
    contactType typeOfContact;
};
#pragma once

enum contactType {
    Family, Friend, Work, Other
};

class PhoneBook {
public:
    PhoneBook();

    void GetName(char* buffer, int bufferSize);
    void GetPhoneNumber(char* buffer, int bufferSize);
    void GetEmail(char* buffer, int bufferSize);
    contactType GetContactType();

private:
    char name[50];
    char phoneNumber[15];
    char email[50];
    contactType typeOfContact;
};
