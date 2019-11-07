//
//  main.cpp
//  Data_Structures
//
//  Created by Juan on 09.04.19.
//  Copyright © 2019 Juan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct student
{
    string name;
    int matriculation_number;
    string subject;
} stud1, stud2;


int main(int argc, const char * argv[])
{
    stud1 = {"Juan", 3530344, "Maths & Computer Sc."};
    
    string name2;
    cout << "Name: " << endl;
    cin >> name2;
    stud2.name = name2;
    
    cout << "Matriculation number: " << endl;
    cin >> stud2.matriculation_number;
    
    cout << "Subject: " << endl;
    cin >> stud2.subject;
    
    student stud[3];
    
    for (int i = 0; i < 3; i++)
    {
        cout << "Name: " << endl;
        cin >> stud[i].name;
        cout << "Matriculation number: " << endl;
        cin >> stud[i].matriculation_number;
        cout << "Subject: " << endl;
        cin >> stud[i].subject;
    }
    
    student stud3;
    student *ptr_stud = &stud3;
    
    cout << "Name: " << endl;
    cin >> ptr_stud->name;
    cout << "Matriculation number: " << endl;
    cin >> (*ptr_stud).matriculation_number;
    cout << "Subject: " << endl;
    cin >> ptr_stud->subject;
    
    
    
    return 0;
}
