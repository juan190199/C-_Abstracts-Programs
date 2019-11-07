//
//  main.cpp
//  Special_Membes
//
//  Created by Juan on 13.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

/**
 * MyClass fn();            // function returning a MyClass object
 * MyClass foo;            // default constructor
 * MyClass bar = foo;  // copy constructor
 * MyClass baz = fn();  // move constructor
 * foo = bar;                 // copy assignment
 * baz = MyClass();      // move assignment
 **/

// Default Constructor
class Example {
    string data;
public:
    Example (const string& str) : data(str) {}
    Example() {}
    const string& content() const { return data; }
};

// Destructor
class Example1
{
private:
    string* ptr;
public:
    // constructors:
    Example1() : ptr(new string) {}
    Example1(const string& str) : ptr(new string(str)) {}
    // destructor:
    ~Example1() { delete ptr; }
    // access content:
    const string& content() const {return *ptr;}
};


// Copy Constructor
class Example2 {
    string* ptr;
public:
    Example2 (const string& str) : ptr(new string(str)) {}
    ~Example2 () {delete ptr;}
    // copy constructor: deep copy
    Example2 (const Example2& x) : ptr(new string(x.content())) {}
    // access content:
    const string& content() const {return *ptr;}
    // copy assignment:
    Example2& operator= (const Example2& x);
};

// Copy Assignment
Example2& Example2::operator= (const Example2& x)
{
    delete ptr;                      // delete currently pointed string
    ptr = new string (x.content());  // allocate space for new string, and copy
    return *this;
}

// Move Constructor and Move Assignment
class Example3
{
private:
    string* ptr;
    
public:
    Example3 (const string& str) : ptr(new string(str)) {}
    ~Example3 () {delete ptr;}
    // move constructor
    Example3 (Example3&& x) : ptr(x.ptr) { x.ptr = nullptr; }
    // move assignment
    Example3& operator= (Example3&& x)
    {
        delete ptr; // Since we are replacing the content of this class with another one, let's wipe out the current data
        ptr = x.ptr;
        x.ptr = nullptr;
        return *this;
    }
    // access content:
    const string& content() const { return *ptr; }
    // addition:
    Example3 operator+(const Example3& rhs)
    {
        return Example3(content() + rhs.content());
    }
};

class Rectangle
{
private:
    int width, height;
    
public:
    Rectangle (int x, int y) : width(x), height(y) {}
    Rectangle() = default;
    Rectangle(const Rectangle& other) = delete; // Function has been deleted
    int area() { return width * height; }
};



int main ()
{
    Example foo;
    Example bar("Example");
    
    cout << "bar's content: " << bar.content() << '\n';
    
    Example1 foo1;
    Example1 bar1("Example");
    
    cout << "bar's content: " << bar1.content() << '\n';
    
    Example2 foo2 ("Example");
    Example2 bar2 = foo2;
    
    cout << "bar's content: " << bar2.content() << '\n';
    
    Example3 foo3 ("Exam");
    Example3 bar3 = Example3("ple");   // move-construction
    
    foo3 = foo3 + bar3;                  // move-assignment
    
    cout << "foo's content: " << foo3.content() << '\n';
    
    return 0;
}
