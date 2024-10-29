#include <stdio.h>
#include <iostream>
#include <type_traits>

// クラステンプレート
template <typename T, typename U>
class Minlator
{

public:
    T min(T a, U b) {
        return (a < b) ? a : b;
    }

};

int main() {


    Minlator<int, int> intInt;
    Minlator<int, float> intFloat;
    Minlator<int, double> intDouble;
    Minlator<float, float> floatFloat;
    Minlator<float, double> floatDouble;
    Minlator<double, double> doubleDouble;


    printf("int, int: %d\n", intInt.min(3, 5));
    printf("int, float: %.1f\n", intFloat.min(3, 5.5f));
    printf("int, double: %.1f\n", intDouble.min(3, 5.5));
    printf("float, float: %.1f\n", floatFloat.min(3.3f, 5.5f));
    printf("float, double: %.1f\n", floatDouble.min(3.3f, 5.5));
    printf("double, double: %.1f\n", doubleDouble.min(3.3, 5.5));

    return 0;
}
