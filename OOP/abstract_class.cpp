/*
Following code contains implementation of an abstract class.
An abstract class is one in which at least one virtual method is pure.
A pure virtual function is a virtual function in C++ for which we need 
not to write any function definition and only we have to declare it. 
It is declared by assigning 0 in the declaration.
*/
#include <bits/stdc++.h>
using namespace std;

class Shape {
    double lenght;
    double width;
public:
    virtual void area() = 0;
};

int main() {
    return 0;
}
