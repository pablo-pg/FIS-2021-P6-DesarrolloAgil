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

#include <fstream>
#include <string>

#include "./hash.h"
#include "./product.h"

/// Ruta predeterminada del fichero de datos que contiene los productos.
const std::string kPath2Products = "../data/.products.csv";

/**
 * @brief Almacena los productos y gestiona el acceso a ellos.
 */
class DataBase {
 public:
  /// Criterio de búsqueda o clave para los productos almacenados.
  using SearchKey = std::string;

  /**
   * @brief Instancia la base de datos y carga la información
   *        de los productos desde un medio no volátil.
   */
  DataBase(void);
  /**
   * @brief Destruye la base de datos y guarda la información
   *        de los productos en un medio no volátil.
   */
  ~DataBase();

  /**
   * @brief Insertar un producto en la tabla hash
   * 
   * @param product 
   */
  bool Insert(const Product& product);

  Product& Search(const SearchKey& key);

 private:
  // Carga los productos desde el fichero de datos.
  void Read(void);
  // Guarda los productos en el fichero de datos.
  void Write(void);

  // Estructura de datos interna para almacenar productos.
  HashTable<Product> hash_;
  // Fichero de datos a modo de almacén no volátil.
  std::fstream data_file_;
};

#endif  // DATA_BASE_H_
