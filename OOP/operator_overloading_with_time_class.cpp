/*
Problem Statement:
=================
Implement a Time class. Data members: hours, minutes.
member functions: Contructors, addMinutes(), addHours(), timerReset()
Overload following operators: +, -, *, <<

Note: hours need not be restricted to 24
*/

#include <iostream>
using namespace std;

class Time {
    int hours;
    int minutes;
public:
    //constructors
    Time();
    Time(int h, int m = 0);
    
    //other member functions
    void addMinutes(int m);
    void addHours(int h);
    void timerReset();
    void display() const;
    
    //operator overloading
    Time operator+(const Time& t) const;
    Time operator-(const Time& t) const;
    Time operator*(int a) const;

    friend ostream& operator<<(ostream& os, const Time& t);
};

Time::Time() {
    hours = minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::addMinutes(int m) {
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}

void Time::addHours(int h) {
    hours += h;
}

void Time::timerReset() {
    hours = minutes = 0;
}

Time Time::operator+(const Time& t) const {
    Time sum;
    sum.hours = hours + t.hours;
    sum.minutes = minutes + t.minutes;
    sum.hours += sum.minutes/60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time& t) const {
    Time diff;
    int t1 = hours*60 + minutes;
    int t2 = t.hours*60 + t.minutes;
    diff.minutes = t1 - t2;
    diff.hours = diff.minutes/60;
    diff.minutes %= 60;
    return diff;
}

Time Time::operator*(int a) const {
    Time res;
    int totMinutes = ((hours*60) + minutes) * a;
    res.hours = totMinutes/60;
    res.minutes = totMinutes % 60;
    return res;
}

void Time::display() const {
    cout << hours << ":" << minutes << endl;
}

ostream& operator<<(ostream& os, const Time& t) {
    os << t.hours << ":" << t.minutes;
    return os;
}

int main(int argc, char const *argv[]) {
    
    Time t1;
    Time t2(3);
    Time t3(4,34);
    cout << "t1: " ;
    t1.display();
    cout << "t2: ";
    t2.display();
    cout << "t3: ";
    t3.display();
    
    t1.timerReset();
    cout << "After reset t1: " << t1 << endl;
    
    t2.addMinutes(88);
    cout << "After add min t2: " << t2 << endl;
    
    t2.addHours(3);
    cout << "After add hours t2: " << t2 << endl;
    
    t1 = t2 + t3;
    cout << "After sum t1: " << t1 << endl;

    Time t4 = t1 + t2 + t3;
    cout << "After sum t4: " << t4 << endl;
    
    t4 = t2 - t3;
    cout << "After diff t4: " << t4 << endl;
    
    t4 = t4 * 2;
    cout <<"After mul t4: " << t4 << endl;
    
    return 0;
}


/*
Output for above inputs
=======================
t1: 0:0
t2: 3:0
t3: 4:34
After reset t1: 0:0
After add min t2: 4:28
After add hours t2: 7:28
After sum t1: 12:2
After sum t4: 24:4
After diff t4: 2:54
After mul t4: 5:48
*/
