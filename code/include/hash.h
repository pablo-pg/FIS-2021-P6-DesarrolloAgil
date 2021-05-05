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

#include <queue>

template <class T>
class HashTable {
 public:
  void Resize(const unsigned long new_size);
  std::queue<T> Records(void) const;


};

#endif  // HASH_H_
