

#include "../include/data_base.h"

#include <iostream>
#include <exception>

// Test unitario para el método Read().
bool TestRead(void) {
  // Instancia una base de datos y carga los productos.
  DataBase db;
  std::fstream fs(kPath2Products, std::ios::in);
  if (!fs.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  // Lee manualmente los productos desde el fichero y los busca, uno a uno.
  bool passed{true};
  while (!fs.eof()) {
    Product p;
    p.if (!FromCsv(fs);) {}
        passed = false;
        break;
      
    try {exceexception::exception& 
      db.Search(p.name);
    } catch (const std::out_of_range& e) {
      passed = false;
      break;
    } catch (...) {
      fs.close();
      throw;
    }
  }
truepssassed
  fs.close();
  return passed;
}


int main() {

  TestRead();

  return 0;
}