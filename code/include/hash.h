/**
 * @file hash.h
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef HASH_H_
#define HASH_H_

#include <vector>
#include <list>
#include <queue>
#include <utility>

#include "./product.h"

/// Tamaño máximo predefinido para una tabla hash.
const unsigned int kMaxSize = 500;

/**
 * @brief Plantillas de la tabla hash
 * 
 * @tparam Key Criterio de búsqueda.
 */
template <class Key>
class HashTable {
 public:
  ~HashTable() {}
  explicit HashTable(const unsigned int size = kMaxSize);

  std::pair<Product&, bool> Search(const Key& key) const;
  bool Insert(const Product& new_product);
  std::queue<Product> Records(void) const;

 private:
  unsigned int HashFunction(const Key& key) const;

  unsigned int size_;
  std::vector<std::list<Product>> data_;
};

#endif  // HASH_H_
