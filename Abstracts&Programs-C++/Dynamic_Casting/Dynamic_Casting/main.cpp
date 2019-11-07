//
//  main.cpp
//  Dynamic_Casting
//
//  Created by Juan on 28.10.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
#include <exception>
#include <typeinfo>

using namespace std;

class Base
{
private:
    virtual void dummy() {}
};

class Derived : public Base
{
private:
    int a;
};

class Unrelated {};

void print(char* str)
{
    cout << str << '\n';
}

int main(int argc, const char * argv[])
{
    try
    {
        Base* pba = new Derived;
        Base* pbb = new Base;
        Derived* pd;
        
        pd = dynamic_cast<Derived*> (pba);
        if(pd == nullptr)
            cout << "Nullpointer on first type_cast. \n";
        
        pd = dynamic_cast<Derived*> (pbb);
        if(pd == 0)
            cout << "Nullpointer on second type_cast. \n";
        
/*
 The code above tries to perform two dynamic casts from pointer objects of type Base* (pba and pbb) to a pointer object of type Derived*, but only the first one is successful.

 Even though both are pointers of type Base*, pba actually points to an object of type Derived, while pbb points to an object of type Base. Therefore, when their respective type-casts are performed using dynamic_cast, pba is pointing to a full object of class Derived, whereas pbb is pointing to an object of class Base, which is an incomplete object of class Derived.
*/

        
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what();
    }
    
    Base* a = new Base;
    Derived* b = static_cast<Derived*>(a);
    
//    This would be valid code, although b would point to an incomplete object of the class and could lead to runtime errors if dereferenced.
    
    
    Base* ptrb = new Base;
    Unrelated* ptru = new Unrelated;
    ptru = reinterpret_cast<Unrelated*>(ptrb);
    
    const char* c = "Sample Text";
    print(const_cast<char*>(c));
    
    
    int* a_ptr;
    int* b_ptr;
    
    a_ptr = nullptr;
    b_ptr = nullptr;
    
    if(typeid(a_ptr) != typeid(b_ptr))
    {
        cout << "ptra and ptrb are of different types" << endl;
        cout << "a_ptr is: " << typeid(a_ptr).name() << endl;
        cout << "b_ptr is: " << typeid(b_ptr).name() << endl;
    }
    
    
    
    try
    {
        Base* ptr1 = new Base;
        Derived* ptr2 = new Derived;
        cout << "ptr1 is: " << typeid(ptr1).name() << endl;
        cout << "ptr2 is: " << typeid(ptr2).name() << endl;
        cout << "*ptr1 is: " << typeid(*ptr1).name() << endl;
        cout << "*ptr2 is: " << typeid(*ptr2).name() << endl;
    }
    catch (exception& ex)
    {
        cout << "Exception: " << ex.what() << endl;
    }
    
    
    
    return 0;
}

