#include "PhoneBook.h"

PhoneBook::PhoneBook() {
    const char defaultName[] = "Unknown";
    const char defaultPhoneNumber[] = "0000000000";
    const char defaultEmail[] = "unknown@example.com";

    // ���������� ��'�
    for (int i = 0; i < 50; ++i) {
        if (i < sizeof(defaultName)) {
            name[i] = defaultName[i];
        }
        else {
            name[i] = '\0';
        }
    }

    // ���������� ����� ��������
    for (int i = 0; i < 15; ++i) {
        if (i < sizeof(defaultPhoneNumber)) {
            phoneNumber[i] = defaultPhoneNumber[i];
        }
        else {
