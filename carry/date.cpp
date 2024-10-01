#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth(int month, int year) const {
        switch (month) {
        case 2: return isLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
        }
    }

    void normalize() {
        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        while (day <= 0) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day += daysInMonth(month, year);
        }
    }

public:
    // ������������
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {
        normalize();
    }

    // �������� << (���������)
    friend ostream& operator<<(ostream& out, const Date& date) {
        out << date.day << "/" << date.month << "/" << date.year;
        return out;
    }

    // �������� >> (��������)
    friend istream& operator>>(istream& in, Date& date) {
        in >> date.day >> date.month >> date.year;
        date.normalize();
        return in;
    }

    // �������� == (��������� �� ������)
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // �������� != (��������� �� ��������)
    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    // �������� < (�����)
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    // �������� > (�����)
    bool operator>(const Date& other) const {
        return other < *this;
    }

    // �������� ++ (��������� �����)
    Date& operator++() {
        day++;
        normalize();
        return *this;
    }

    // �������� ++ (���������� �����)
    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    // �������� -- (��������� �����)
    Date& operator--() {
        day--;
        normalize();
        return *this;
    }

    // �������� -- (���������� �����)
    Date operator--(int) {
        Date temp = *this;
        --(*this);
        return temp;
    }

    // �������� +=
    Date& operator+=(int days) {
        day += days;
        normalize();
        return *this;
    }

    // �������� -=
    Date& operator-=(int days) {
        day -= days;
        normalize();
        return *this;
    }

    // �������� ���������
    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    // �������� ������� ()
    void operator()() const {
        cout << "����: " << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    Date date1(28, 2, 2020);
    Date date2;

    cout << "��������� ����: " << date1 << endl;
    ++date1;
    cout << "�i��� ��i������� �� 1 ����: " << date1 << endl;

    date1 += 5;
    cout << "�i��� ��������� 5 ��i�: " << date1 << endl;

    date1();

    if (date1 != date2) {
        cout << "���� �i��i." << endl;
    }

    return 0;
}

