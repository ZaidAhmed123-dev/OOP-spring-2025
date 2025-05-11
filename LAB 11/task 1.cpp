#include <iostream>
#include <exception>

using namespace std;

class InvalidValueException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidValueException - Age cannot be negative or exceed 120.";
    }
};

void checkAge(int x) {
    if (x < 0 || x > 120) {
        throw InvalidValueException();
    } else {
        cout << "Age is valid." << endl;
    }
}

int main() {
    int a;
    cout << "Enter age: ";
    cin >> a;

    try {
        checkAge(a);
    } catch (const InvalidValueException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
