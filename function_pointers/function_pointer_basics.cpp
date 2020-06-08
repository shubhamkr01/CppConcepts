#include <iostream>

using namespace std;

int foo (int a, int b) {
    
    cout << a + b << endl;
    return 0;
}

int bar (int a, int b) {
	cout << b - a << endl;
	return 0;
}


int main() {

    int (*fxnPtr)(int, int) {foo}; // assignment type 1
    (*fxnPtr)(3, 7); //calling type 1: explicit dereference
    
    fxnPtr = bar; // assignment type 2
    fxnPtr(3, 7); //calling type 2: implicit dereference 

	return 0;
}