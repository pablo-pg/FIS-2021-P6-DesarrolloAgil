/**
 * @file hash.inl
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "hash.h"

using namespace std;

template <class Key>
HashTable<Key>::HashTable(std::vector<std::vector<Key> > data, FuncionDispersion<Key>* fd, FuncionEkeyploracion<Key>* fe) {
  SetVecData(data);
  SetFunDisp(fd);
  SetFunEkeyp(fe);
}

template <class Key>
void HashTable<Key>::Resize(const unsigned long new_size) {}

template <class Key>
std::queue<Key> HashTable<Key>::Records(void) const {}

template <class Key>
bool HashTable<Key>::Search(const Key& key) const {
  const int kONE = 1;
  bool result;
  int attempt;
  
  if (data_.at(fd_->operator()(key)).SearchR(key)) {
    return true;
  } else if (!data_.at(fd_->operator()(key)).SearchR(key)){
    do {
      result = data_.at((fd_->operator()(key) + fe_->operator()(key, attempt)) % size_).SearchR(key);
      attempt++;
    } while ((!result) && (i == size_ - kONE));
  } 
  return result;
}

template <class Key>
unsigned HashTable<Key>::operator()(const Key& key) const {
  srand(key); // inicio num ale
  return (rand() % size_);
}

template <class Key>
bool HashTable<Key>::Insert(const Key& key) {
  bool result;
  int attempt;
  
  if (Search(key) && IsFull(attempt)){
    return false;
  } else if ((!data_.at(fd_->operator()(key)).estaLleno()) && (data_.at(fd_->operator()(key)).insertarL(key))) {
    return true;
  } else if ((data_.at(fd_->operator()(key)).estaLleno()) && (!data_.at(fd_->operator()(key)).insertarL(key))){
    do {
      result = data_.at((fd_->operator()(key) + fe_->operator()(key, attempt)) % size_).insertarL(key);
      attempt++;
    } while ((!result) && (attempt == size_ - 1));
  } 
  return resultado;
}

template <class Key>
bool HashTable<Key>::isFull(const Key& key) {
  return (key > size_)
}

