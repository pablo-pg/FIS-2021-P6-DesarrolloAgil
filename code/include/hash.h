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
#include <vector>

/**
 * @brief Plantillas de la tabla hash
 * 
 * @tparam Key Criterio de búsqueda.
 */
template <class Key>
class HashTable {
 public:
  HashTable() {}
  HashTable(std::vector<std::vector<Key> >, FuncionDispersion<Key>*, FuncionExploracion<Key>*);
  ~HashTable() {}

  void Resize(const unsigned long new_size);
  std::queue<Key> Records(void) const;
  bool Search(const Key&) const;
  bool Insert(const Key&);
  void SetSizeData(int size) {
    assert(size >= 0);  //?????
    size_ = size;
  }
  void SetVecData(std::vector<Producto> data) {
    data_ = data; 
  }
  void SetFunDisp(FuncionDispersion<Key>* fd) {
    fd_ = fd;
  }
  void SetFunExp(FuncionExploracion<Key>* fe) {
    fe_ = fe;
  }
  std::vector<Producto> GetVecData() {
    return data_;
  }
  FuncionDispersion<Key>* GetFunDisp() {
    return fd_;
  }
  FuncionExploracion<Key>* GetFunExp() {
    return fe_;
  }

  unsigned operator()(const Key& k) const;
  
  bool SearchR(const Key &key) const;

  bool isFull();

 private:
  const int size_ = 500;
  std::vector<std::vector<Key>> data_;
  FuncionDispersion<Key>* fd_;
  FuncionExploracion<Key>* fe_;
};

#endif  // HASH_H_
