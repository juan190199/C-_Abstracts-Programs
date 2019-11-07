//
//  main.cpp
//  Preprocessor_Directives
//
//  Created by Juan on 29.10.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
using namespace std;

#define TABLE_SIZE 100

int table1[TABLE_SIZE];

#undef TABLE_SIZE

#define TABLE_SIZE 100

int table2[TABLE_SIZE];

#ifdef TABLE_SIZE

int table3[TABLE_SIZE];
// In this case, the line of code int table3[TABLE_SIZE]; is only compiled if TABLE_SIZE was previously defined with #define, independently of its value. If it was not defined, that line will not be included in the program compilation.

#endif

#undef TABLE_SIZE
#ifndef TABLE_SIZE
#define TABLE_SIZE 100
#endif

// In this case, if when arriving at this piece of code, the TABLE_SIZE macro has not been defined yet, it would be defined to a value of 100. If it already existed it would keep its previous value since the #define directive would not be executed.

int table4[TABLE_SIZE];

#if TABLE_SIZE > 200
#undef TABLE_SIZE
#define TABLE_SIZE 200
 
#elif TABLE_SIZE < 50
#undef TABLE_SIZE
#define TABLE_SIZE 50
 
#else
#undef TABLE_SIZE
#define TABLE_SIZE 100

#endif
 
int table[TABLE_SIZE];





#define getMax(a,b) (a)>(b) ? (a) : (b)
#define str(x) #x
#define glue(a, b) a ## b



int main(int argc, const char * argv[])
{
    int x = 5, y;
    y = getMax(x, 2);
    cout << y << endl;
//    cout << getMax(7, x) << endl;
    
    str(test);
    glue(c, out) << "test" << endl;
    
    return 0;
}
