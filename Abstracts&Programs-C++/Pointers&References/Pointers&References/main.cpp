//
//  main.cpp
//  Pointers&References
//
//  Created by Juan on 09.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
using namespace std;


void sum1(int &x)
{
    x = x + 1;
    cout << "Result: " << x << endl;
}

void increment_all(int *start, int *stop)
{
    int *current = start;
    while(current != stop)
    {
        ++(*current);  // increment value pointed
        ++current;     // increment pointer
    }
}

void print_all(const int *start, const int *stop)
{
    const int * current = start;
    while(current != stop)
    {
        cout << *current << " ";
        ++current;     // increment pointer
    }
}


// Pointer to functions
int addition(int a, int b)
{
    return a + b;
}

int substraction(int a, int b)
{
    return a - b;
}

int operation(int x, int y, int (* functocall) (int, int))
{
    int g;
    g = (*functocall)(x, y);
    return g;
}



int main(int argc, const char * argv[])
{
    int x = 7;
    
    int& ref = x; // ref is a reference to x
    
    
    ref = 10; // Value of x is now changed to 10
    cout << "x: " << x << endl ;
    
    x = 100; // Value of x is now changed to 100
    cout << "ref: " << ref << endl ;
    
    cout << endl;
    
    sum1(ref); //Value passed by reference
    cout << "x: " << x << endl; // Side effect
    
    cout << endl;
    
    int firstvalue, secondvalue;
    int *ptr1, *ptr2;
    
    ptr1 = &firstvalue; // ptr1 = address of firstvalue
    ptr2 = &secondvalue; // ptr2 = address of firstvalue
    
    *ptr1 = 7; // Dereference operator: value pointed to by ptr1 = 7
    *ptr2 = 100; // Dereference operator: value pointed to by ptr2 = 100
    
    cout << "firstvalue: " << firstvalue << endl;
    cout << "prt1: " << "value of ptr1: " << ptr1 << ";    value pointed to by ptr1: " << *ptr1 << endl;
    cout << "secondvalue: " << secondvalue << endl;
    cout << "prt2: " << "value of ptr2: " << ptr2 << ";    value pointed to by ptr2: " << *ptr2 << endl;
    
    cout << endl;
    
    *ptr2 = *ptr1; // Value pointed to by ptr2 = value pointed to by ptr1
    ptr2 = ptr1; // Value ptr2 = value ptr1
    
    cout << "secondvalue: " << secondvalue << endl;
    cout << "prt2: " << "value of ptr2: " << ptr2 << ";    value pointed to by ptr2: " << *ptr2 << endl;
    
    cout << endl;
    
    *ptr1 = 0; // Value pointed to by ptr1 = 0
    
    cout << "firstvalue: " << firstvalue << endl;
    cout << "prt1: " << "value of ptr1: " << ptr1 << ";    value pointed to by ptr1: " << *ptr1 << endl;
    
    cout << endl;
    
    int numbers[5];
    int *ptr3;
    
    ptr3 = numbers; // Pointers and Arrays
//    numbers = ptr3 (operation not valid)
    *ptr3 = 1;
    
    cout << "First index of array numbers(value pointed to by ptr3): " << *ptr3 << ";   Value of ptr3: " << ptr3 << endl;
    
    ptr3++;
    *ptr3 = 2;
    
    cout << "Second index of array numbers(value pointed to by ptr3): " << *ptr3 << ";   Value of ptr3: " << ptr3 << endl;
    
    ptr3 = &numbers[2];
    *ptr3 = 3;
    
    cout << "Third index of array numbers(value pointed to by ptr3): " << *ptr3 << ";   Value of ptr3: " << ptr3 << endl;
    
    ptr3 = numbers + 3;
    *ptr3 = 4;
    
    cout << "Fourth index of array numbers(value pointed to by ptr3): " << *ptr3 << ";   Value of ptr3: " << ptr3 << endl;
    
    ptr3 = numbers;
    *(ptr3 + 4) = 5;
    
    cout << "Fifth index of array numbers(value pointed to by ptr3): " << *(ptr3 + 4) << ";   Value of ptr3: " << ptr3 << endl;
    
    cout << endl;
    
    int numbers1[] = {10,20,30};
    
    print_all (numbers1, numbers1 + 3);
    
    increment_all (numbers1, numbers1 + 3);
    
    cout << endl;
    
    print_all (numbers1, numbers1 + 3);
    
    cout << endl;
    
    int m, n;
    int (* minus)(int, int) = substraction;
    
    m = operation(7, 5, addition);
    n = operation(20, m, minus);
    
    cout << n << endl;
    
    
    return 0;
}
