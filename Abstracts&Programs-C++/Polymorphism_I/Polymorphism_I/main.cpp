//
//  main.cpp
//  Polymorphism
//
//  Created by Juan on 14.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
using namespace std;

class Polygon
{
protected:
    int width, height;
public:
    void set_values (int a, int b)
    { width = a; height = b; }
};

class Rectangle: public Polygon
{
public:
    int area()
    { return width * height; }
};

class Triangle: public Polygon
{
public:
    int area()
    { return width * height/2; }
};


int main ()
{
    Rectangle rect;
    Triangle trgl;
    
    // Pointers point to address of Base Class: only the members inherited from Base Class can be accessed
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    ppoly1->set_values (4,5);
    ppoly2->set_values (4,5);
    
    // Function area() cannot be accessed through pointers ppoly1 and ppoly2
    cout << rect.area() << '\n';
    cout << trgl.area() << '\n';
    
    return 0;
}
