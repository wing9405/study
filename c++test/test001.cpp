#include <iostream>

using namespace std;

class Vector {
public:
    Vector(int s): elem{new double[s]}, sz{s} {}
    double& operator[](int i) const { return elem[i]; } // NOTE: this const is not 'my deeply const'
    int size() const { return sz; }
private:
    double* elem;
    int sz;
};

int
main() {
    const int N = 6;
    Vector v(N);

    for (int i = 0; i != N; i++) {
        cout << "elem " << i << " = " << v[i] << endl;
    }

    for (int i = 0; i != N; i++) {
        v[i] = 3.3;
    }

    for (int i = 0; i != N; i++) {
        cout << "elem " << i << " = " << v[i] << endl;
    }
}
