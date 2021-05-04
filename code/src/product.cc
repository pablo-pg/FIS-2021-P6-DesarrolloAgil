/**
 * @file product.cc
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-04-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/product.h"

const char Product::kCsvDelimiter{','};

void Product::ToCsv(std::fstream& fs) const {
  if (!fs.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  fs << id << kCsvDelimiter
     << name << kCsvDelimiter
     << stock << kCsvDelimiter
     << price << kCsvDelimiter
     << expiration << kCsvDelimiter
     << origin << '\n';
}

void Product::FromCsv(std::fstream& fs) {
  if (!fs.is_open()) {
    throw std::ios_base::failure("El fichero debe estar abierto.");
  }

  std::vector<std::string> split;
  std::string line, field;
  std::getline(fs, line);

  std::stringstream stream_line(line);
  while (std::getline(stream_line, field, kCsvDelimiter)) {
    split.push_back(field);
  }

  id = std::stoul(split[CsvField::kId]);
  name = split[CsvField::kName];
  stock = std::stoul(split[CsvField::kStock]);
  price = std::stof(split[CsvField::kPrice]);
  expiration = std::stol(split[CsvField::kExpiration]);
  origin = split[CsvField::kOrigin];
}
