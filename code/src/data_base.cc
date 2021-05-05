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
  /* Code */
}

DataBase::~DataBase() {
  /* Code */
  Write();
}

void DataBase::Read() {
  data_file_.open(kPath2Products, std::ios::in);
  if (!data_file_.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  // Desplazarse hasta el final del fichero (antes de EOF).
  data_file_.seekg(-1, std::ios_base::end);
  // Desplazarse hasta el principio de la última línea,
  // importante la presencia de una cabecera.
  while (!data_file_.fail() && data_file_.get() != '\n') {
    data_file_.seekg(-1, std::ios_base::cur);
  }

  // Lee el último índice (primer campo de la última fila).
  std::string last_index;
  std::getline(data_file_, last_index, Product::kCsvDelimiter);
  // Revisa si el fichero no contiene productos.
  for (const char& c : last_index) {
    if (!std::isdigit(c)) {
      // El fichero sólo contiene una línea de cabecera.
      last_index = "0";
      break;
    }
  }

  // Ajusta el tamaño de la tabla hash en consecuencia.
  const unsigned long kTableSize{std::stoul(last_index)};
  hash_.Resize(kTableSize);

  // Vuelve al principio del fichero.
  data_file_.seekg(0, std::ios_base::beg);
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

bool Insert(const Product& product) {
  const int kZero = 0;
  int attempt = kZero;
  
  

  return (attempt < vData.size());
}

Product& DataBase::Search(const SearchKey& key) {

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
  data_file_ << header << '\n';
  // Extrae todos los productos de la tabla hash como una cola FIFO.
  std::queue<Product> products(hash_.Records());
  while (!products.empty()) {
    products.front().ToCsv(data_file_);
    products.pop();
  }

  data_file_.close();
}
