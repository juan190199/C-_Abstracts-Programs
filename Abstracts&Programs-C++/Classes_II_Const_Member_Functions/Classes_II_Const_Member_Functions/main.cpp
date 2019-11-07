//
//  main.cpp
//  Classes_II_Const_Member_Functions
//
//  Created by Juan on 17.10.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>

using namespace std;

class MyClass
{
private:
public:
    int _x;
    MyClass(int value) : _x(value) {}
    
    // Overloadding constness
    const int& get() const { return _x; }
    int& get() { return _x; }
};

void print(const MyClass& arg)
{
    cout << arg.get() << '\n';
}


int main(int argc, const char * argv[])
{
    const MyClass foo(100);
    
//    foo._x = 20; // _x cannot be modified
    cout << foo._x << endl;
    
   
    foo.get(); // The member functions of a const object can only be called if they are themselves specified as const members.

    
    MyClass bar(10);
    cout << bar._x << endl;
    bar.get();
    
    print(foo); // If get was not a const member function, the call arg.get() would not be possible
    
    return 0;
}
