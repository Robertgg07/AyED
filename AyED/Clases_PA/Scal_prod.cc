#include <iostream>
using namespace std;

int scalprod( const int *v1, const int *v2, const size_t sz){ // size_t es un entero sin signo

    int prod{0};
    for(size_t i{0}; i < sz; i++){
        prod += v1[i] * v2[i]; //va leyendo cada array del vector
    }
        return prod;
}