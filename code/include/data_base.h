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

#include <string>

#include "./hash.h"
#include "./product.h"

const std::string products = ".products.csv";

class DataBase {
 public:
  DataBase();

 private:
  HashTable<Product> hash_;
};

#endif  // DATA_BASE_H_