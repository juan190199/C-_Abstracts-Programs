//
//  main.cpp
//  Exception
//
//  Created by Juan on 18.10.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[])
{
    try
    {
        throw 20;
    }
    catch(int param)
    {
        cout << "Int exception Nr.: " << param << '\n';
    }
    catch(char param)
    {
        cout << "Char exception: " << param << '\n';
    }
    catch(...)
    {
        cout << "Default exception" << '\n';
    }
    
    return 0;
}
