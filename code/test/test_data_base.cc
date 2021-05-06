/**
 * @file test_data_base.h
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/data_base.h"

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

// Test unitario para el método Read().
bool TestRead(void) {
  // Instancia una base de datos y carga los productos.
  DataBase db;
  std::fstream fs(kPath2Products, std::ios::in);
  if (!fs.is_open()) {
    throw std::ios_base::failure("TestRead: El fichero debe estar abierto.");
  }

  std::string header;
  std::getline(fs, header);

  // Lee manualmente los productos desde el fichero y los busca, uno a uno.
  bool passed{true};
  while (!fs.eof()) {
    Product p;
    p.FromCsv(fs);
    try {
      db.Search(p.name);
    } catch (const std::exception& e) {
      passed = false;
      std::cout << "TestRead: " << e.what() << std::endl;
      break;
    }
  }

  fs.close();
  return passed;
}


int main() {

  TestRead();

  return 0;
}
