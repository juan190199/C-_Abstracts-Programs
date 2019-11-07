//
//  main.cpp
//  Friendship&Inheritance
//
//  Created by Juan on 13.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
using namespace std;

class Square;

class Rectangle
{
private:
    int width, height;
    
public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {}
    int area() { return width * height; }
    void convert(Square a);
    friend Rectangle duplicate (const Rectangle&); // Friend Function: Is not a member of the class
};

Rectangle duplicate (const Rectangle& param)
{
    Rectangle res;
    res.width = param.width * 2;
    res.height = param.height * 2;
    return res;
}

class Square
{
    friend class Rectangle; // Rectangle is a friend of Square
private:
    int side;
public:
    Square (int a) : side(a) {}
};

void Rectangle::convert(Square a) // Accessing private members
{
    width = a.side;
    height = a.side;
}



int main(int argc, const char * argv[])
{
    Rectangle foo;
    Rectangle bar (2,3);
    foo = duplicate (bar);
    cout << foo.area() << '\n';
    
    Rectangle rect;
    Square sqr(4);
    rect.convert(sqr);
    cout << rect.area();
    
    return 0;
}
