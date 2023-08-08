#include <iostream>

class Shape
{
public:
    virtual double area()
    {
        return 0;
    }
    virtual double perimeter()
    {
        return 0;
    }
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double radius)
    {
        this->radius = radius;
    }

    double area() override
    {
        return 3.14 * radius * radius;
    }
    double perimeter() override
    {
        std::cout << "Can't find perimeter of Circle! It doesnt exists clown"<<std::endl;
        return 0;
    }
};

class Triangle : public Shape
{
private:
    double height, side;
public:
    Triangle(double height, double side)
    {
        this->height = height;
        this->side = side;
    }

    double area() override
    {
        return 0.5 * height * side;
    }
    double perimeter() override
    {
        return 3 * side;
    }
};


int main()
{
    Shape* figures[2]{ new Triangle(5,4), new Circle(6) };
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Area of this figure is: " << figures[i]->area() << " Perimeter of this figure is: " << figures[i]->perimeter() << std::endl;
    }
    return 0;
}

