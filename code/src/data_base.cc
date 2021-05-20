/**
 * @file data_base.cc
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/data_base.h"

DataBase::DataBase() : hash_(), data_file_() {
  Read();
  // Si se añade código, hacerlo a partir de aquí.
  // ...
}

DataBase::~DataBase() {
  // Si se añade código, hacerlo a partir de aquí.
  // ...
  Write();
}

void DataBase::Insert(const Product& new_product) { hash_.Insert(new_product); }

Product& DataBase::Search(const SearchKey& key) { return hash_.Search(key); }

void DataBase::Delete(const SearchKey& product) { hash_.Delete(product); }

const Product& DataBase::Search(const SearchKey& key) const {
  return hash_.Search(key);
}

void DataBase::Records(std::queue<Product>& products) const {
  hash_.Records(products);
}

void DataBase::Read() {
  data_file_.open(kPath2Products, std::ios::in);
  if (!data_file_.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  // Ignora la cabecera.
  std::string header;
  std::getline(data_file_, header);

  while (!data_file_.eof()) {
    Product p;
    p.FromCsv(data_file_);
    Insert(p);
  }

  data_file_.close();
}

void DataBase::Write() {
  data_file_.open(kPath2Products, std::ios::in);
  if (!data_file_.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  // Respalda la cabecera ante el borrado del fichero.
  std::string header;
  std::getline(data_file_, header);
  data_file_.close();

  // Abrir el fichero y guardar la información de la tabla hash.
  data_file_.open(kPath2Products, std::ios::out);
  if (!data_file_.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  // Recupera la cabecera.
  data_file_ << header;
  // Extrae todos los productos de la tabla hash como una cola FIFO.
  std::queue<Product> products;
  hash_.Records(products);
  std::size_t counter{1};
  while (!products.empty()) {
    data_file_ << '\n' << counter << Product::kCsvDelimiter;
    counter++;
    products.front().ToCsv(data_file_);
    products.pop();
  }

  data_file_.close();
}
