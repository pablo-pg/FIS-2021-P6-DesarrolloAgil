/**
 * @file product.h
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
#include <string>

class Product {
 public:
  Product();

 private:
  int amount_;
  std::string name_product_;
  float price_;
  int code_product_;
};

#endif  // PRODUCT_H_
