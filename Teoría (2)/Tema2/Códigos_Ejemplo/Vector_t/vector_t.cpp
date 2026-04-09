#include "vector_t.hpp"

vector_t::vector_t(const int n = 0) {

  assert(n >= 0);
  size_ = n;
  build_();
}

vector_t::~vector_t() {

  destroy_();
}

int vector_t::GetSize() const {

  return size_;
}

void vector_t::ReSize(const int n) {

  assert (n > 0);
  destroy_();
  size_ = n;
  build_();
}

void vector_t::SetVal(const int i, const double x) {

  assert(i >= 0 && i < GetSize());
  v_[i] = x;
}

double vector_t::GetVal(const int i) const {

  assert (i >= 0 && i < GetSize());
  return v_[i];
}

ostream& vector_t::Write(ostream& os = cout) const  {

  os << GetSize() << ":\t";

  for (int i{}; i < GetSize(); i++) {

    os << GetVal(i) << "\t";
    os << endl;
  }
}

void vector_t::Read(istream& is = cin) {

  is >> size_;

  for (int i {}; i < size_; i++) {

    double x{};
    is >> x;
    SetVal(i,x);
  }
}

void vector_t::build_() {

  v_ = NULL;
  
  if (size_ > 0) {

    v_ = new double [size_];
    assert(v_ != NULL);
  }
}

void vector_t::destroy_() {

  if (v_ != NULL) {

    delete[] v_;
    v_ = NULL;
  }

  size_ = 0;
}

const double& vector_t::at(const int i) const {

  assert(i >= 0 && i < GetSize());
  return v_[i];
}

double& vector_t::operator[](const int i){

  return at(i);
}

void ostream& operator <<(ostream& os, const vector_t& v){
  return Write(os);
}