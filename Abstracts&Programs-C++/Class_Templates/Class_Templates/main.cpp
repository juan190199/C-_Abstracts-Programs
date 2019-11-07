//
//  main.cpp
//  Class_Templates
//
//  Created by Juan on 13.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
using namespace std;


template <class T>
class MyPair
{
private:
    T _a, _b;
    
public:
    MyPair(T first, T second) : _a(first), _b(second) {}
    T getmax();
};


template <class T>
T MyPair<T>::getmax() // It specifies that this function's template parameter is also the class template parameter.
{
    T retval;
    retval = _a>_b? _a:_b;
    return retval;
}


// Class Template
template <class T1>
class MyContainer
{
private:
    T1 _element;
public:
    MyContainer (T1 arg) : _element(arg) {}
    T1 increase() { return _element + 1; }
};

// Template Specialization
template <>
class MyContainer <char>
{
private:
    char _element;
public:
    MyContainer(char arg) : _element(arg) {}
    char uppercase()
    {
        if ((_element>='a')&&(_element<='z'))
        {
            _element += 'A' - 'a';
        }
        return _element;
    }
};



int main()
{
    MyPair <int> object (100, 75);
    cout << object.getmax() << endl;
    
    MyContainer<int> myint (9);
    MyContainer<char> mychar ('j');
    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl;
    return 0;
}
