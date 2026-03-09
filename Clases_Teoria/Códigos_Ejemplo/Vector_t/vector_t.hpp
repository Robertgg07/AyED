#ifndef VECTOR_T_HPP
#define VECTOR_T_HPP

#include <cassert>
#include <iostream>

using namespace std;

class vector_t {

  public:

    vector_t (const int n = 0);
    ~vector_t();

    int GetSize() const;
    void ReSize(const int n);

    void SetVal(const int i, const double x);
    double GetVal(const int i) const;
    double at(const int i) const;
    void Write(ostream& os = cout);
    void Read(istream& is = cin);

    const double& operator[](const int i) const;
  private:

    double  *v_;
    int size_;
    void build_();
    void destroy_();
};

#endif