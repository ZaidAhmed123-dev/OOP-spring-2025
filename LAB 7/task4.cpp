#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name, id, address, phonenumber, email;

    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phonenumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << " | ID: " << id << " | Address: " << address
             << " | Phone: " << phonenumber << " | Email: " << email << endl;
    }

    void updateInfo(string n, string addr, string phone, string mail) {
        name = n; address = addr; phonenumber = phone; email = mail;
        cout << "Info updated!" << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
public:
    int coursesEnrolled, enrollYear;
    float gpa;

    Student(string n, string i, string addr, string phone, string mail, int ce, float g, int ey)
        : Person(n, i, addr, phone, mail), coursesEnrolled(ce), gpa(g), enrollYear(ey) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses: " << coursesEnrolled << " | GPA: " << gpa << " | Year: " << enrollYear << endl;
    }
};

class Professor : public Person {
public:
    int coursesTaught;
    double salary;
    string department;

    Professor(string n, string i, string addr, string phone, string mail, int ct, double sal, string dept)
        : Person(n, i, addr, phone, mail), coursesTaught(ct), salary(sal), department(dept) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Taught: " << coursesTaught << " | Salary: " << salary << " | Department: " << department << endl;
    }
};

class Staff : public Person {
public:
    string department, position;
    float salary;

    Staff(string n, string i, string addr, string phone, string mail, string dept, float sal, string pos)
        : Person(n, i, addr, phone, mail), department(dept), salary(sal), position(pos) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << " | Salary: " << salary << " | Position: " << position << endl;
    }
};

class Course {
private:
    string courseId, courseName;
    int credits, studentCount;
    Professor* instructor;
    Student* students[10];  

public:
    Course(string id, string name, int cr, Professor* prof)
        : courseId(id), courseName(name), credits(cr), instructor(prof), studentCount(0) {}

    void enrollStudent(Student* student) {
        if (studentCount < 10) {
            students[studentCount++] = student;
            cout << student->id << " joined " << courseName << "!" << endl;
        } else {
            cout << "Sorry, " << courseName << " is full." << endl;
        }
    }

    void displayCourseInfo() {
        cout << "\n[Course] " << courseName << " (" << courseId << ") | Credits: " << credits << endl;
        cout << "Prof: " << instructor->name << " (ID: " << instructor->id << ")" << endl;
        cout << "Students Enrolled: " << studentCount << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << students[i]->name << " (ID: " << students[i]->id << ")" << endl;
        }
    }
};

int main() {
    Professor* prof = new Professor("Dr. Ahmed Khan", "03232", "College Rd", "0300-1234567", "ahmed.khan@univ.edu", 3, 90000.0, "Computer Science");
    Student* stu1 = new Student("Ali Raza", "5324", "Mall Rd", "0301-9876543", "ali.raza@univ.edu", 4, 3.8, 2024);
    Student* stu2 = new Student("Fatima Noor", "6478", "78 Gulberg", "0302-7654321", "fatima.noor@univ.edu", 5, 3.9, 2023);

    Course* course = new Course("Cs123", "Data Structures", 4, prof);
    course->enrollStudent(stu1);
    course->enrollStudent(stu2);
    course->displayCourseInfo();

    delete prof;
    delete stu1;
    delete stu2;
    delete course;

    return 0;
}
