#include <iostream>

using namespace std;

void
foo(int& ri) {
    cout << ri << endl;
    ri++;
}

int
main(int argc, char** argv) {

    // int& i = 4;  error
    // foo(3);      error

    int var = 3;
    foo(var);
    cout << var << endl;

    // int& ira[3] = { var, var, var };  error

    return EXIT_SUCCESS;
}

