#include <iostream>
using namespace std;

class Shape {
protected:
    int position;
    string color;
    float borderThickness;

public:
    Shape(int pos, string col, float bt) : position(pos), color(col), borderThickness(bt) {}

    virtual void draw() {
        cout << "Rendering a generic shape..." << endl;
    }

    virtual double getArea() {
        cout << "Calculating area for a generic shape..." << endl;
        return 0.0;
    }

    virtual double getPerimeter() {
        cout << "Calculating perimeter for a generic shape..." << endl;
        return 0.0;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(int pos, string col, float bt, float r) : Shape(pos, col, bt), radius(r) {}

    void draw() override {
        cout << "Rendering a Circle with radius " << radius << " and color " << color << endl;
    }

    double getArea() override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape {
private:
    float width, height;

public:
    Rectangle(int pos, string col, float bt, float w, float h) : Shape(pos, col, bt), width(w), height(h) {}

    void draw() override {
        cout << "Rendering a Rectangle (Color: " << color << ") with dimensions " << width << " x " << height << endl;
    }

    double getArea() override {
        return width * height;
    }

    double getPerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    float base, height;

public:
    Triangle(int pos, string col, float bt, float b, float h) : Shape(pos, col, bt), base(b), height(h) {}

    void draw() override {
        cout << "Rendering a Triangle with base " << base << " and height " << height << " in " << color << " color" << endl;
    }

    double getArea() override {
        return 0.5 * base * height;
    }

    double getPerimeter() override {
        return 3 * base;  
    }
};

int main() {
    Circle circle(10, "Red", 2.0, 7.5);
    circle.draw();
    cout << "Circle Area: " << circle.getArea() << endl;
    cout << "Circle Perimeter: " << circle.getPerimeter() << endl << endl;

    Rectangle rect(15, "Blue", 1.8, 5.0, 8.0);
    rect.draw();
    cout << "Rectangle Area: " << rect.getArea() << endl;
    cout << "Rectangle Perimeter: " << rect.getPerimeter() << endl << endl;

    Triangle tri(25, "Green", 2.2, 6.0, 5.0);
    tri.draw();
    cout << "Triangle Area: " << tri.getArea() << endl;
    cout << "Triangle Perimeter: " << tri.getPerimeter() << endl << endl;

    return 0;
}
