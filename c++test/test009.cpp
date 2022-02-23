#include <iostream>

using namespace std;

void
print_m35(int m[3][5]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

void
print_mx5(int m[][5], int dim1) {

    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < 5; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

/* error!
void
print_mx5(int *m[5], int dim1) {

    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}
 */

/* OK */
void
print_mx5_(int (*m)[5], int dim1) {

    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < 5; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

void
print_mxy(int *m, int dim1, int dim2) {

    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            cout << m[i * dim2 + j] << ' ';
        }
        cout << endl;
    }
}

int
main(int argc, char* argv[]) {
    int v[3][5] = {
        { 1,2,3,4,5},
        { 21,22,23,24,25},
        { 31,32,33,34,35}
    };

    print_m35(v);
    print_mx5(v, 3);
    print_mx5_(v, 3);
    print_mxy(&v[0][0], 3, 5);

    return EXIT_SUCCESS;
}
