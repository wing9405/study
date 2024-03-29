#include <iostream>

using namespace std;

enum class Traffic_light { green, yellow, red };

Traffic_light& operator++(Traffic_light& t)
{
    switch (t) {
    case Traffic_light::green: return t = Traffic_light::yellow;
    case Traffic_light::yellow: return t = Traffic_light::red;
    case Traffic_light::red: return t = Traffic_light::green;
    }

    return t = Traffic_light::green;
}

int
main() {
    Traffic_light l = Traffic_light::red;
    ++l;
    cout << (l == Traffic_light::green ? "yes" : "no") << endl;
    return EXIT_SUCCESS;
}
