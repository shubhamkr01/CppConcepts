/*
Problem Statement:
=================
Consider the following structure declaration:
struct customer {
string fullname;
double payment;
};
Write a program that adds and removes customer structures from a stack, 
represented by a Stack class declaration. Each time a customer is removed, his or her
payment should be added to a running total, and the running total should be
reported. 
*/


#include <bits/stdc++.h>
using namespace std;

static long double running_total = 0;

struct Customer {
	Customer() {
		fullname = "";
		payment = 0.0;
	}
    string fullname;
    double payment;
};

class Stack {
private:
	static const int MAX = 100;
	Customer customers[MAX];
	int top;
public:
	Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const Customer& c);
	bool pop();
	void topElement(Customer& c);
};

Stack::Stack() { //create an empty stack
    top = -1;
}

bool Stack::isFull() const {
	if(MAX == top) {
		cout << "Stack is Full" << endl;
		return true;
	}
	return false;
}

bool Stack::isEmpty() const {
	if(-1 == top) {
		return true;
	}
	return false;
}

bool Stack::push(const Customer& c) {
	if(isFull()) {
	    return false; 
	}
	customers[++top] = c;
    return true;
}

//function needs error checking mechanism
void Stack::topElement(Customer& c) {
	if(isEmpty()) {
		throw "Stack is empty";
	}
    c = customers[top];	
}

bool Stack::pop() {
	if(top >= 0) {
		top--;
		return true;
	}
	return false;
}


/*
Each time a customer is removed, his or her
payment should be added to a running total, and the running total should be
reported.
*/
bool removeFromStack(Stack& customers_stack) {
	static int i = 0;
	Customer top_element;
	try {
		customers_stack.topElement(top_element);
        cout << "Customer at top of stack: " << top_element.fullname << endl;
    	running_total += top_element.payment;
    	i++;
    	cout <<  i << " Customer removed from stack. Current Total = " << running_total << endl;
	}
	catch(const char* s) {
		cout << "Error: " << s << " Can't remove!" << endl;
	}

	return customers_stack.pop();
}

int main(int argc, char const *argv[]) {
	Stack customers_stack;
	
    Customer one, two, three, four;
    
    one.fullname = "Tim Cook";
    one.payment = 78.8;

    two.fullname = "Richard Martin";
    two.payment = 52.5;

    three.fullname = "Abra ka Dabra";
    three.payment = 75.6;

    four.fullname = "Kumar Sangakara";
    four.payment = 32.9;

    customers_stack.push(one);
    customers_stack.push(two);
    customers_stack.push(three);
    customers_stack.push(four);

    removeFromStack(customers_stack);
    removeFromStack(customers_stack);
    removeFromStack(customers_stack);
    removeFromStack(customers_stack);
    
    removeFromStack(customers_stack);// try to remove from empty stack

	return 0;
}

/*
Output for the above input
==========================
Customer at top of stack: Kumar Sangakara
1 Customer removed from stack. Current Total = 32.9
Customer at top of stack: Abra ka Dabra
2 Customer removed from stack. Current Total = 108.5
Customer at top of stack: Richard Martin
3 Customer removed from stack. Current Total = 161
Customer at top of stack: Tim Cook
4 Customer removed from stack. Current Total = 239.8
Error: Stack is empty Can't remove!
*/
