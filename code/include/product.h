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

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

struct Product {
  /// Identificador único de producto.
  unsigned long id;
  /// Nombre del producto.
  std::string name;
  /// Cantidad de producto
  unsigned long stock = 0;
  /// Precio del producto.
  float price = 0.0;
  /// Fecha de caducidad (formato UNIX).
  std::time_t expiration = time(NULL);
  /// Origen del producto.
  std::string origin = "";

  /// Delimitador para una entrada de fichero .csv sobre productos.
  static const char kCsvDelimiter;
  /// Posición de un campo para una entrada de fichero .csv sobre productos.
  enum CsvField : std::size_t {
    /// Should be ignored for a product.
    kRecord = 0,
    kId,
    kName,
    kStock,
    kPrice,
    kExpiration,
    kOrigin
  };
  
  /**
   * @brief Imprime el producto en formato .csv.
   * @param fs Fichero de salida.
   */
  void ToCsv(std::fstream& fs) const;
  /**
   * @brief Lee el producto en formato .csv.
   * @param fs Fichero de entrada.
   */
  void FromCsv(std::fstream& fs);
};

#endif  // PRODUCT_H_
