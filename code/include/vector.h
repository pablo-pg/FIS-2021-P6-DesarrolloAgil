/**
 * @file vector.h
 * @author Equipo m5 FIS
 * @brief Clase vector para implementarse en la tabla de hash
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef VECTOR_H_
#define VECTOR_H_

template <class Key>
class Vector {
 private:
  int size_;
  Key 
 public:
  Vector(/* args */);
  ~Vector();
};

Vector::Vector() {
}

Vector::~Vector()
{
}


template <class Key>
bool Vector<Key>::SearchR(const Key &key) const{
  for(auto &ele : data_) {
    if (key == ele) {
      return true;
    }
  }
  return false;
}




#endif  // VECTOR_H_
