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

#include "../include/hash.h"

template <class Key>
HashTable<Key>::HashTable(const unsigned int size)
    : size_(size), nrecords_(0), data_(size) {}


template <class Key>
Product& HashTable<Key>::Search(const Key& key) {
  for (Product& p : data_.at(HashFunction(key))) {
    if ((Key)p == key) {
      return p;
    }
  }

  throw std::out_of_range("No existe tal producto.");
}

template <class Key>
const Product& HashTable<Key>::Search(const Key& key) const {
  for (const Product& p : data_.at(HashFunction(key))) {
    if ((Key)p == key) {
      return p;
    }
  }
  throw std::out_of_range("No existe tal producto.");

}

template <class Key>
unsigned int HashTable<Key>::HashFunction(const Key& key) const {
  std::stringstream sspass(key);
  unsigned int uint_key;
  sspass >> uint_key;
  srand(uint_key);
  return (rand() % size_);
}

template <class Key>
void HashTable<Key>::Resize(){
  // Aumenta el tamaño en un cierto margen.
  HashTable<Key> auxData(size_ + kDefaultTableSize);
  for (const std::list<Product>& row : data_) {
    for (const Product& p : row) {
      auxData.Insert(p);
    }
  }
  
  data_.clear();
  data_ = auxData.data_;
  size_ = data_.size();
}


template <class Key>
void HashTable<Key>::Insert(const Product& new_product) {
  if (Full()) {
    Resize();
  }

  try {
    Search(new_product);
    throw std::runtime_error("El producto ya existe.");
  } catch (const std::out_of_range& e) {
    data_.at(HashFunction(new_product)).push_back(new_product);
    nrecords_++;
  } catch (...) {
    throw;
  }
}

template <class Key>
void HashTable<Key>::Records(std::queue<Product>& products) const {
  while (!products.empty()) {
    products.pop();
  }

  for (const std::list<Product>& row : data_) {
    for (const Product& p : row) {
      products.push(p);
    }
  }
}

template <class Key>
void HashTable<Key>::Delete(const Key &key) {

  // get the hash index of key
  unsigned int index = HashFunction(key);

  // find the key in (inex)th list
  std::list<Product>::iterator i;
  for (i = data_[index].begin(); i != data_[index].end(); i++) {
    if ((Key)(*i) == key) {
      data_[index].erase(i);
      nrecords_--;
      return;
    }
  }
  
  throw std::runtime_error("El producto no existe.");  
}