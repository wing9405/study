#include <iostream>

using namespace std;

struct { int i, double d }
f() {
    return { 1, 1.1 };
}

int
main()
{

    struct { int i, double d } s = f();
    cout << s.i << endl;
    cout << s.d << endl;

    return EXIT_SUCCESS;
}
