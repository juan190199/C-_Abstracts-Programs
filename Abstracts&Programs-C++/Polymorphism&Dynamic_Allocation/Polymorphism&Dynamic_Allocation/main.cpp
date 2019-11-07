//
//  main.cpp
//  Polymorphism&Dynamic_Allocation
//
//  Created by Juan on 14.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
using namespace std;

class Polygon
{
protected:
    int _width, _height;
public:
    Polygon(int a, int b) : _width(a), _height(b) {}
    virtual int area() = 0;
    // It is possible for a member of the base abstract class to use the pointer this to access the propper virtual members
    void printarea() { cout << this->area() << '\n'; }
};

class Rectangle : public Polygon
{
public:
    Rectangle(int a, int b) : Polygon(a, b) {}
    int area() { return _width * _height;}
};

class Triangle : public Polygon
{
public:
    Triangle(int a, int b) : Polygon(a, b) {}
    int area() { return _width * _height / 2;}
};



int main(int argc, const char * argv[])
{
    Polygon * ppoly1 = new Rectangle (4,5);
    Polygon * ppoly2 = new Triangle (4,5);
    ppoly1->printarea();
    ppoly2->printarea();
    delete ppoly1;
    delete ppoly2;
    
    return 0;
}
