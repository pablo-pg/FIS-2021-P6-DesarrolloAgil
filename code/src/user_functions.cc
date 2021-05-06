/**
 * @file user_functions.cc
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/user_functions.h"

// void ShowAllProducts(const DataBase& data_base) {
void ShowAllProducts() {
  std::cout << "ID" << std::cout.width(10) << ' ' + "NAME"
            << std::cout.width(15)
            << "STOCK" << std::cout.width(18) << "PRICE"
            << std::cout.width(20) << "DATE"
            << std::cout.width(40) << "PLACE" << std::endl;
  std::queue<Product> products;
  Product new_prodB { 1234, "manzana", 23, 12.3, std::time(nullptr), "Lamatana"};
  // data_base.Records(products);
  products.push(new_prodB);
  Product new_prod = products.front();
  std::cout << new_prod.id << std::cout.width(10) << new_prod.name
            << std::cout.width(15) << new_prod.stock << std::cout.width(18)
            << new_prod.price << std::cout.width(20)
            << std::asctime(std::localtime(&new_prod.expiration))
            << std::cout.width(40)
            << new_prod.origin << std::endl;
  products.pop();
}