//
//  main.cpp
//  Friendship&Inheritance_II
//
//  Created by Juan on 13.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
using namespace std;

class Polygon
{
protected:
    int _width, _height;
    
public:
    void set_values(int a, int b) { _width = a; _height = b; }
};


class Triangle : public Polygon
{
private:
public:
    int area();
};

int Triangle::area()
{
    return _width * _height / 2;
}
    

class Rectangle : public Polygon
{
private:
public:
    int area();
};

int Rectangle::area()
{
    return _width * _height;
}




class Mother
{
public:
    Mother ()
    { cout << "Mother: no parameters\n"; }
    Mother (int a)
    { cout << "Mother: int parameter\n"; }
};

class Daughter : public Mother
{
public:
    Daughter (int a)
    { cout << "Daughter: int parameter\n\n"; }
};

class Son : public Mother
{
public:
    Son (int a) : Mother (a)
    { cout << "Son: int parameter\n\n"; }
};




int main(int argc, const char * argv[])
{
    Rectangle rect;
    Triangle trgl;
    rect.set_values (4,5);
    trgl.set_values (4,5);
    cout << rect.area() << '\n';
    cout << trgl.area() << '\n';
    
    
    Daughter Vic(0);
    Son Juan(0);
    
    
    
    return 0;
}
