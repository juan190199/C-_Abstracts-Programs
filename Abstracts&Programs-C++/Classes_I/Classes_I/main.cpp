//
//  main.cpp
//  Classes_I
//
//  Created by Juan on 10.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
#define PI 3.14159265359

using namespace std;

class Rectangle
{
private:
    int _height, _width;
public:
//    Constructors
    Rectangle(int, int);
    Rectangle(); // Default Constructor
    
    int area() { return _height * _width; }
    
};

Rectangle::Rectangle (int height, int width)
{
    _height = height;
    _width = width;
}

Rectangle::Rectangle()
{
    _width = 5;
    _height = 5;
}

class Circle
{
private:
    double _radius;
public:
//    Constructors
    Circle(double r) : _radius(r) {}
    Circle() { _radius = 5; }
    
    double area() { return _radius * _radius * PI; }
};

class Cylinder
{
private:
    Circle _base;
    double _height;
public:
//    Constructors
    Cylinder(double r, double height) : _base(r) { _height = height; }
    Cylinder() : _base(), _height(5) {}
    
    double volume() { return _base.area() * _height; }
};



int main(int argc, const char * argv[])
{
    Rectangle rect(5, 5); // Functional form
    Rectangle rect1;
    
    cout << "Area: " << rect.area() << endl;
    
    Circle circ = 5; // Assignment init.
    Circle circ1 {5}; // Uniform init.
    Circle circ2;
    
    cout << "Area: " << circ1.area() << endl;
    
    Cylinder cylind = {5, 5}; // POD-like
    Cylinder cylind1;

    cout << "Volume: " << cylind1.volume() << endl;

    Rectangle *ptr, *ptr1, *ptr2;
    
    ptr = &rect;
    
    ptr1 = new Rectangle {5, 5};
    ptr2 = new Rectangle[2] {{5,5}, {10,10}};
    
    cout << "Area: " << ptr->area() << endl;
    cout << "Area: " << (*ptr1).area() << endl;
    cout << "Area: " << ptr2[0].area() << endl;
    cout << "Area: " << (ptr2+1)->area() << endl;
    
    
    delete ptr1;
    delete[] ptr2;
    
    return 0;
}
