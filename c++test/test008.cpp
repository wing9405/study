#include <iostream>

using namespace std;

class C {
public:
    C(int n): m{n} {}
    int f () { return m; }
    int m;
};

int
main()
{
    C c{5};
    int(C::* pf)() { &C::f };
    //int(* cpf)() { & (c.*pf) };   // how can I include a specific object?
    cout << (c.*pf)() << endl;
    cout << c.*pm << endl;
    return EXIT_SUCCESS;
}
