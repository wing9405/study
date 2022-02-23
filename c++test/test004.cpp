#include <iostream>

using namespace std;

class C {
public:
    C(int i) {
        cout << "hi " << i << endl;
    };
};

int
main() {
    C c(1);
    return EXIT_SUCCESS;
}


