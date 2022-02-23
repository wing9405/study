#include <iostream>
#include <stdlib.h>

using namespace std;

struct Vector {
    int sz;
    double* elem;
};

void vector_init(Vector& v, int size) {
    v.elem = new double[size];
    for (int i = 0; i != size; i++) {
        v.elem[i] = 7.7;
    }
    v.sz = size;
}

int
main() {
    const int N = 5;
    Vector v;
    vector_init(v, N);

    int i;
    for (i = 0; i != N; i++) {
        cin >> v.elem[i];
        cout << "i = " << i << endl;
    }
    cout << "final i = " << i << endl;

    double sum = 0;
    for (i = 0; i != N; i++) {
        cout << "elem " << i << " = " << v.elem[i] << endl;
        sum += v.elem[i];
    }
    cout << "sum = " << sum << endl;

    return EXIT_SUCCESS;
}
