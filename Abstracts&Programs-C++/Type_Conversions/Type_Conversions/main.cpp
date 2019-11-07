//
//  main.cpp
//  Type_Conversions
//
//  Created by Juan on 28.10.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class A {};

class B
{
public:
    // Conversion from A (constructor)
    explicit B(const A& x) {}
    // Conversion from A (assignment)
    B& operator= (const A& x) {return *this;}
    // Conversion to A (type-cast operator)
    operator A() {return A();}
};

class C
{
private:
    string _str;
    int _integer;
public:
    C(const string& str) : _str(str), _integer(-1) {}
    explicit C(int integer) : _integer(integer), _str("Unknown") {}
};

void printC(const C& c)
{
    // Printing
}

void func(const B&) {}

int main(int argc, const char * argv[])
{
    A foo;
//    B bar = foo; // calls constructor
    B bar(foo); // calls constructor
    bar = foo; // calls assignment
    foo = bar; // calls type-cast operator
    

    func(bar);
//    func(foo); // Not allowed because B objects construct is explicit
    
//    B pie = foo; // Not allowed because B objects construct is explicit
    
    
//    printC(22); // Only allowed if constructor is not explicit
//    printC("Juan"); // "Juan" is a char[]. Only one conversion is permitted
    printC(C("Juan"));
    
//    C a = 22; // Only allowed if constructor is not explicit
    C a = C(22);
    // C b = "Juan"; Not allowed
    
    
    double x = 10.3;
    int y;
    y = int(x); // Functional notation
    y = (int) x; // C-like cast notation
    
    
    return 0;
}
