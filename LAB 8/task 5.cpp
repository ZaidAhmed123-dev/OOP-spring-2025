#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class Fraction {
    int numerator;
    int denominator;

    int getGCD(int a, int b) const {
        if (b == 0) {
            return a;
        } else {
            return getGCD(b, a % b);
        }
    }

    void simplify() {
        int g = getGCD(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        if (d == 0) {
            denominator = 1;
        } else {
            denominator = d;
        }
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        int n = numerator * other.denominator + other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction operator-(const Fraction& other) const {
        int n = numerator * other.denominator - other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main() {
    Fraction a(2, 3);
    Fraction b(3, 4);

    Fraction sum = a + b;
    Fraction diff = a - b;
    Fraction prod = a * b;
    Fraction quot = a / b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << sum << endl;
    cout << "a - b = " << diff << endl;
    cout << "a * b = " << prod << endl;
    cout << "a / b = " << quot << endl;

    return 0;
}
