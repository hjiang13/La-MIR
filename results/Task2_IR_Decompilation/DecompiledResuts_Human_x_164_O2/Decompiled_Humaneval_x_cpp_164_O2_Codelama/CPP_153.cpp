Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <string>

using namespace std;

class basic_string {
public:
    struct _Alloc_hider {
        char *ptr;
    };

    union {
        struct {
            char *ptr;
            int length;
            int capacity;
        };
        _Alloc_hider alloc_hider;
    };

    basic_string(const char *str) {
        ptr = new char[strlen(str) + 1];
        strcpy(ptr, str);
        length = strlen(str);
        capacity = length + 1;
    }

    basic_string(const basic_string &other) {
        ptr = new char[other.length + 1];
        strcpy(ptr, other.ptr);
        length = other.length;
        capacity = other.capacity;
    }

    ~basic_string() {
        delete[] ptr;
    }

    basic_string &operator=(const basic_string &other) {
        if (this != &other) {
            delete[] ptr;
            ptr = new char[other.length + 1];
            strcpy(ptr, other.ptr);
            length = other.length;
            capacity = other.capacity;
        }
        return *this;
    }

    char &operator[](int index) {
        return ptr[index];
    }

    const char &operator[](int index) const {
        return ptr[index];
    }

    int size() const {
        return length;
    }

    int capacity() const {
        return capacity;
    }

    void clear() {
        delete[] ptr;
        ptr = nullptr;
        length = 0;
        capacity = 0;
    }

    void resize(int new_size) {
        if (new_size > capacity) {
            char *new_ptr = new char[new_size];
            for (int i = 0; i < length; i++) {
                new_ptr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = new_ptr;
            capacity = new_size;
        }
        length = new_size;
    }

    void push_back(char c) {
        if (length == capacity) {
            resize(capacity * 2);
        }
        ptr[length] = c;
        length++;
    }

    void pop_back() {
        if (length > 0) {
            length--;
        }
    }

    basic_string substr(int start, int length) {
        basic_string result;
        for (int i = start; i < start + length; i++) {
            result.push_back(ptr[i]);
        }
        return result;
    }

    void assign(const char *str) {
        delete[] ptr;
        ptr = new char[strlen(str) + 1];
        strcpy(ptr, str);
        length = strlen(str);
        capacity = length + 1;
    }

    void append(const char *str) {
        int new_length = length + strlen(str);
        if (new_length > capacity) {
            resize(new_length * 2);
        }
        strcpy(ptr + length, str);
        length = new_length;
    }

    void replace(int start, int length, const char *str) {
        int new_length = length + strlen(str);
        if (new_length > capacity) {
            resize(new_length * 2);
        }
        for (int i = 0; i < strlen(str); i++) {
            ptr[start + i] = str[i];
        }
        length = new_length;
    }

    void replace(int start, int length, int n, char c) {
        int new_length = length + n;
        if (new_length > capacity) {
            resize(new_length * 2);
        }
        for (int i = 0; i < n; i++) {
            ptr[start + i] = c;
        }
        length = new_length;
    }

    void erase(int start, int length) {
        for (int i = start; i < start + length; i++) {
            ptr[i] = ptr[i + length];
        }
        length -= length;
    }

    void swap(basic_string &other) {
        char *temp_ptr = ptr;
        int temp_length = length;
        int temp_capacity = capacity;
        ptr = other.ptr;
        length = other.length;
        capacity = other.capacity;
        other.ptr = temp_ptr;
        other.length = temp_length;
        other.capacity = temp_capacity;
    }

    friend ostream &operator<<(ostream &out, const basic_string &str) {
        out << str.ptr;
        return out;
    }
};

int main() {
    basic_string str1("Hello, World!");
    basic_string str2(str1);
    basic_string str3("Goodbye, World!");
    str1.assign("Hello, World!");
    str2.assign("Hello, World!");
    str3.assign("Goodbye, World!");
    str1.append("Hello, World!");
    str2.append("Hello, World!");
    str3.append("Goodbye, World!");
    str1.replace(0, 5, "Hello, World!");
    str2.replace(0, 5, "Hello, World!");
    str3.replace(0, 5, "Goodbye, World!");
    str1.replace(0, 5, 5, 'H');
    str2.replace(0, 5, 5, 'H');
    str3.replace(0, 5, 5, 'G');
    str1.erase(0, 5);
    str2.erase(0, 5);
    str3.erase(0, 5);
    str1.swap(str2);
    str2.swap(str3);
    str3.swap(str1);
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should be functionally equivalent.