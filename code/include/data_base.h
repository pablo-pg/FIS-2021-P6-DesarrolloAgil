/**
 * @file data_base.h
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef DATA_BASE_H_
#define DATA_BASE_H_

#include <fstream>
#include <string>

#include "./hash.h"
#include "./product.h"

const std::string kProductsPath = "../data/.products.csv";

class DataBase {
 public:
  DataBase(void);
  ~DataBase();

  void Insert(const Product& product);
  Product& Search(const std::string& key);

 private:
  void Read(void);
  void Write(void);

  /// Estructura de datos interna para almacenar productos.
  HashTable<Product> hash_;
  /// Fichero de datos a modo de almacén no volátil.
  std::fstream data_file_;
};

#endif  // DATA_BASE_H_