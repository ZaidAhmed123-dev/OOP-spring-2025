#include <iostream>
#include <cmath>
#include <exception>
#include <typeinfo>

using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException - Input must be non-negative!";
    }
};

class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};

template <typename T>
T mysqrt(T x) {
    if (typeid(x) == typeid(int) || typeid(x) == typeid(double)) {
        if (x < 0) throw NegativeNumberException();
        return sqrt(x);
    } else {
        throw InvalidTypeException();
    }
}

int main() {
    try {
        cout << mysqrt(-4) << endl;
    } catch (const exception& e) {
        cerr << "sqrt(-4): " << e.what() << endl;
    }

    try {
        cout << mysqrt(string("hello")) << endl;
    } catch (const exception& e) {
        cerr << "sqrt(\"hello\"): " << e.what() << endl;
    }

    return 0;
}
