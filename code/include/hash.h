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

#include <list>
#include <queue>
#include <vector>

#include "./product.h"

/// Tamaño máximo predefinido para una tabla hash.
const unsigned int kDefaultTableSize = 500;

/**
 * @brief Plantillas de la tabla hash
 * @tparam Key Criterio de búsqueda.
 */
template <class Key>
class HashTable {
 public:
  /**
   * @brief Instancia una tabla hash sin productos.
   * @param size Tamaño máximo para la tabla.
   */
  explicit HashTable(const unsigned int size = kDefaultTableSize);
  /**
   * @brief Destrutor por defecto
   */
  ~HashTable() {}

  /**
   * @brief Comprueba si la tabla está llena.
   * @return Valor booleano, verdadero si se han insertado demasiados productos.
   */
  bool Full(void) const { return nrecords_ >= size_; }
  /**
   * @brief 
   * 
   */
   *        Lanza una excepción si dicho producto no existe.
   * @param key Patrón de búsqueda para el producto.
   * @return Referencia de lectura/escritura al producto buscado.
   */
  Product& Search(const Key& key);
  /**
   * @brief Búsqueda pero constante.
   */
  const Product& Search(const Key& key) const;
  /**
   * @brief Insertar un producto en la tabla hash, siempre que no esté llena.
   * @param new_product Nuevo producto a insertar.
   */
  void Insert(const Product& new_product);
  
  // 
  void Delete(const Product& product);
  /**
   * @brief Devuelve todos los productos de la tabla.
   * @param products Estructura FIFO para guardar los registros.
   */
  void Records(std::queue<Product>& products) const;

 private:
  // Función de hash pseudo-aleatoria.
  unsigned int HashFunction(const Key& key) const;

  // Tamaño de la tabla, en base al número de entradas.
  unsigned int size_;
  // Número de productos que contiene la tabla actualmente.
  unsigned int nrecords_;
  // Estructura de datos para implementar la dispersión.
  std::vector<std::list<Product>> data_;
};

#include "../src/hash.inl"

#endif  // HASH_H_
