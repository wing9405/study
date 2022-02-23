#include <iostream>

using namespace std;

class Date {
    int d, m, y;
public:
    Date(int dd = 0, int mm = 0, int yy = 0) {
        d = dd;
        m = mm;
        y = yy;
    }
};

void f(Date d) {
}

int
main() {
    Date d = 1;
    Date d2 = { 1,2 };

    f(7);
    f({1,2,3});

    return EXIT_SUCCESS;
}
