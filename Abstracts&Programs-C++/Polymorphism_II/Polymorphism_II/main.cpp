//
//  main.cpp
//  Polymorphism_II
//
//  Created by Juan on 14.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
using namespace std;

// Abstact Class
class Polygon
{
protected:
    int width, height;
public:
    void set_values (int a, int b)
    { width = a; height = b; }
    virtual int area() = 0; // Pure Virtual Member Function
//    virtual int area() { return 0; }

};

class Rectangle: public Polygon
{
public:
    int area ()
    { return width * height; }
};

class Triangle: public Polygon
{
public:
    int area ()
    { return (width * height / 2); }
};



int main(int argc, const char * argv[])
{
    Rectangle rect;
    Triangle trgl;
//    Polygon poly; This is not possible because Polygon is an Abstract Base Class
    Rectangle rect1;
    Triangle trgl1;
    
    Polygon *ppoly1 = &rect;
    Polygon *ppoly2 = &trgl;
//    Polygon * ppoly3 = &poly;
    ppoly1->set_values (4,5);
    ppoly2->set_values (4,5);
//    ppoly3->set_values (4,5);
    
    // Can be accessed through a reference of the base class
    cout << ppoly1->area() << '\n';
    cout << ppoly2->area() << '\n';
//    cout << ppoly3->area() << '\n';
    
    Polygon *ppoly3 = &rect1;
    Polygon *ppoly4 = &trgl1;
    ppoly3->set_values(4, 5);
    ppoly4->set_values(4, 5);

    cout << ppoly3->area() << '\n';
    cout << ppoly4->area() << '\n';
    
    
    return 0;
}
