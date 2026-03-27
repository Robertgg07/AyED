 #include <vector>
 #include <iostream>
 #include <cmath>

 size_t count_eq(const double *v, const size_t sz, const double val, const double tol){
    size_t cnt{0};

        for( size_t i{0}; i < sz; i++)
            if(equal(v[i], val, tol) == true){
                cnt++;
            }
}

bool equal( const double a, const double b, const double tol){
    bool eq{false};
    if( fabs(a-b) < tol ){
        eq = true;
    }
return eq;
}

int main(void) {

    // double v1{0.9, 0.99, 0.999, 0.9999, 1.0, 1.0001, 1.001, 1.01, 1.1}

    


    return 0;
}