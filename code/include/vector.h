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
  Key* pointer_;
  unsigned valueCounter_;
  bool full;

 public:
  Vector() : valueCounter(0), size_(0) {}
  Vector(int size = 0) : size_(size), pointer_(NULL), valueCouter_(0) {}
  ~Vector() : size_(0) {}
  void SetSize(int size) {
      size_ = size;
  }
  void SetPointer(Key* pointer) {
    pointer_ = pointer;
  }
  void SetValueCounter(unsigned valuePointer) {
    valuePointer_ = valuePointer;
  }
  int GetSize() {
    return size_;
  }
  Key* GetPointer() {
    return pointer_;
  }
  unsigned GetValueCounter() {
    return valueCounter_;
  }
  void build();
  bool SearchR(const Key &key) const;
  bool Insert(const key &key);

  bool IsFull();

  Vector<Key>& operator=(const Vector<Key>&);
};

template <class Key>
void Vector<Key>::build() {
  SetPointer(NULL);
  pointer_ = new Key[size_];
}

template <class Key>
bool Vector<Key>::SearchR(const Key &key) const {
  for (auto &ele : pointer_) {
    if (key == ele) {
      return true;
    }
  }
  return false;
}

template <class key>
bool Vector<Key>::Insert(const Key &key) {
  const int kZERO = 0;

  if (!isFull()) {
    for (int i = kZERO; i < size_; i++) {
      if (valueCounter_ == i) {
        pointer_[i] = key;
        valueCounter_++;
        return true; 
      } 
    }
  }

  return false; 
}

template <class Key>
Vector<Key>& Vector<Key>::operator=(const Vector<Key>& vector) {
  const int kZERO = 0;

  for (int i = kZERO; i < size_; i++) {
    pointer_[i] = vector[i];
  }
  return *this;
}

template <class Key>
bool Vector<Key>::IsFull(){
  return full;
}

#endif  // VECTOR_H_
