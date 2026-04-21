#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual double Area() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override
    {
        return length * width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override
    {
        return M_PI * radius * radius;
    }
};

int main()
{
    vector<Shape*> shapes;
    shapes.push_back(new Rectangle(5.0, 3.0));
    shapes.push_back(new Circle(4.0));
    for (const auto& shape : shapes)
    {
        cout << "Area: " << shape->Area() << endl;
    }

    for (auto& shape : shapes)
    {
        delete shape;
    }
    shapes.clear();

    return 0;
}
