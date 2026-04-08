#include <iostream>
#include <vector>
using namespace std;

int sum_pair(const int *v, const size_t sz){

    int sum{0};
        for( size_t i{0}; i < sz; i += 2){
            if( v[i] % 2 == 0){
                sum += v[i];
            } else {

            }
        }

}