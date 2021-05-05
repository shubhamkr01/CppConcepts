#include <iostream>
#include <thread>
using namespace std;

void threadFunc() {
    cout << "Executing threadFunc";
}

int main() {
    thread t(threadFunc);
    t.join();
    return 0;
}
