#include <iostream>
#include <exception>
#include <string>

using namespace std;

class FileException : public exception {
public:
    const char* what() const noexcept override {
        return "FileException - General file error";
    }
};

class FileNotFoundException : public FileException {
public:
    const char* what() const noexcept override {
        return "FileNotFoundException - File not found";
    }
};

class PermissionDeniedException : public FileException {
public:
    const char* what() const noexcept override {
        return "PermissionDeniedException - Access denied!";
    }
};

void readFile(const string& f) {
    if (f == "missing.txt") throw FileNotFoundException();
    if (f == "secret.txt") throw PermissionDeniedException();
    cout << "Reading " << f << " successful" << endl;
}

int main() {
    string name = "secret.txt";
    try {
        readFile(name);
    } catch (const FileException& e) {
        cerr << "Reading '" << name << "': " << e.what() << endl;
    }

    return 0;
}
