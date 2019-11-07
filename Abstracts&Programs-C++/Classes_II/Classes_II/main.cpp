//
//  main.cpp
//  Classes_II
//
//  Created by Juan on 10.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>

using namespace std;

class CVector
{
private:
    double _x, _y;
    static int _n; // Static member or class variable
public:
    CVector() { _n++; };
    CVector(double x, double y) : _x(x), _y(y) { _n++; };
    CVector operator + (const CVector&);
    CVector& operator = (const CVector&);
    
    int get_x () const { return _x; }
    int get_y () const { return _y; }
    void print_Vector();
    void print();
    void print_n();
};

int CVector::_n = 0;

CVector CVector::operator+(const CVector& param)
{
    CVector result;
    result._x = _x + param._x;
    result._y = _y + param._y;
    return result;
}

void CVector::print_Vector()
{
    cout << "Vector: " << _x << ", " << _y << endl;
}

// Const objcts only have accesss to const member functions (get())
void print(const CVector& param)
{
    cout << "Vector: " << param.get_x() << ", " << param.get_y() << endl;
}

void CVector::print_n()
{
    cout << "Number of vectors created: " << _n << endl;
}

//CVector operator+ (const CVector& lhs, const CVector& rhs)
//{
//    CVector result;
//    result._x = lhs._x + rhs._x;
//    result._y = lhs._y + rhs._y;
//}

CVector& CVector::operator=(const CVector& param)
// The function is returning a reference to *this of type CVector
{
    _x = param._x;
    _y = param._y;
    
    return *this;
}


int main(int argc, const char * argv[])
{
    CVector vector1 (10, 10);
    CVector vector2 (10, 10);
    
    CVector result = vector1 + vector2;
    CVector result1 = vector1.operator+(vector2);
    
    result.print_Vector();
    print(result1);
    
    vector1.operator=(result);
    vector1.print_Vector();
    
    vector1.print_n();
    vector2.print_n();
    
    return 0;
}
