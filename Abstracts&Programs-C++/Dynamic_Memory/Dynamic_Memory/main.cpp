//
//  main.cpp
//  Dynamic_Memory
//
//  Created by Juan on 09.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
#include <new>

using namespace std;



int main(int argc, const char * argv[])
{
    int i, n;
    int * p;
    
    cout << "How many numbers would you like to type? ";
    cin >> i;
    
    p= new (nothrow) int[i];
    if (p == nullptr)
    {
        cout << "Error: memory could not be allocated";
    }
    else
    {
        for (n=0; n<i; n++)
        {
            cout << "Enter number: ";
            cin >> p[n];
        }
        
        cout << "You have entered: ";
        for (n=0; n<i; n++)
            cout << p[n] << " ";
        delete[] p;
    }
    
    return 0;
}
