#include <iostream>

using namespace std;

void f (int) {
    cout<<"f (int) is called"<<endl;
}

void f (bool) {
    cout<<"f (bool) is called"<<endl;
}
void f (void *) {
    cout<<"f (void *) is called"<<endl;
}

int main () {
    f(0);
    // f(NULL) mights not compile, but typically calls f (int). Never calls f (void *).
    // f(NULL);
    f(nullptr);
    return 0;
}
