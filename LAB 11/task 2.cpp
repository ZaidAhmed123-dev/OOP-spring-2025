#include <iostream>
#include <exception>

using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack {
    T arr[5];
    int top;
public:
    Stack() : top(-1) {}

    void push(T val) {
        if (top == 4) throw StackOverflowException();
        arr[++top] = val;
    }

    T pop() {
        if (top == -1) throw StackUnderflowException();
        return arr[top--];
    }
};

int main() {
    Stack<int> s;
    try {
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.push(6);
    } catch (const exception& e) {
        cerr << "Pushing to a full stack: " << e.what() << endl;
    }

    try {
        for (int i = 0; i < 6; ++i) s.pop();
    } catch (const exception& e) {
        cerr << "Popping from an empty stack: " << e.what() << endl;
    }

    return 0;
}
