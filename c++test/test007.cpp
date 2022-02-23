#include <iostream>

using namespace std;

class C {
public:
    static int factorial(int n) {
        return (n > 0 ? n * factorial(n - 1) : 1);
    }
};

int
main()
{
    C c;
    cout << C::factorial(4) << endl;
    return EXIT_SUCCESS;
}
