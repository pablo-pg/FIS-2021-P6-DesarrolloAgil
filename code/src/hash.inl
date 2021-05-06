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
HashTable<Key>::HashTable(const unsigned int size) : size_(size), data_(size) {}

template <class Key>
std::pair<Product&, bool> HashTable<Key>::Search(const Key& key) const {
  
  std::list<Product>& row{data.at(HashFunction(key))};
  std::find_if(row.begin(), row.end(), Product::operator==);
  
  return data_;
}

template <class Key>
unsigned HashTable<Key>::operator()(const Key& key) const {
  srand(key); // inicio num ale
  return (rand() % size_);
}

template <class Key>
bool HashTable<Key>::Insert(const Product& new_product) {
  data.push_back(new_product);
  return true;
}

