#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;


class Shape 
{
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
};

class Rectangle : public Shape 
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override
    {
        return width * height;
    }
};

class Circle : public Shape 
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override 
    {
        return & radius * radius;
    }
};


void printAllAreas(const vector<unique_ptr<Shape>>& shapes)
{
    for (const auto& shape : shapes) 
    {
        cout << "Area:" << shape->getArea() << endl;
    }
}

int main() 
{
    ifstream inputFile("shapes.txt");
    vector<unique_ptr<Shape>> shapes;

    if (!inputFile) 
    {
        cerr << "Failed to open" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string shapeType;
        ss >> shapeType;

        if (shapeType == "rectangle") 
        {
            double width, height;
            ss >> width >> height;
            shapes.push_back(make_unique<Rectangle>(width, height));
        }
        else if (shapeType == "circle") {
            double radius;
            ss >> radius;
            shapes.push_back(make_unique<Circle>(radius));
        }
    }

    printAllAreas(shapes);

    return 0;
}