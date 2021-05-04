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
}

DataBase::~DataBase() {
  Write();
}

void DataBase::Read() {
  data_file_.open(kProductsPath, std::ios::in);
  if (!data_file_.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  data_file_.seekg(-1, std::ios_base::end);
  while (data_file_.get() != '\n') {
    data_file_.seekg(-1, std::ios_base::cur);
  }


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
  data_file_.open(kProductsPath, std::ios::app);
  if (!data_file_.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  std::string header;
  std::getline(data_file_, header);

  data_file_.close();
  data_file_.open(kProductsPath, std::ios::in | std::ios::out);
  if (!data_file_.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  data_file_ << header << '\n';
  for (Product& p : hash_.Records()) {
    p.ToCsv(data_file_);
  }

  data_file_.close();
}
