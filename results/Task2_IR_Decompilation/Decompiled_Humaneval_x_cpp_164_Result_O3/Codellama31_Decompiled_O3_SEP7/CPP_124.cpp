Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <string>

using namespace std;

bool valid_date(string date) {
    int year, month, day;
    year = month = day = 0;
    for (int i = 0; i < date.length(); i++) {
        if (date[i] == '/') {
            month = year;
            year = 0;
        } else if (date[i] == '/') {
            day = month;
            month = 0;
        } else {
            int digit = date[i] - '0';
            if (digit >= 0 && digit <= 9) {
                year = year * 10 + digit;
                if (month > 0 && month <= 12) {
                    day = day * 10 + digit;
                    if (day > 0 && day <= 31) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    string date;
    cin >> date;
    if (valid_date(date)) {
        cout << "Valid date" << endl;
    } else {
        cout << "Invalid date" << endl;
    }
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should produce the same output for the same input.