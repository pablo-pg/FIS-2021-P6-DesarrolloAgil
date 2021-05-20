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
#include <queue>
#include <string>

#include "./hash.h"
#include "./product.h"

/// Ruta predeterminada del fichero de datos que contiene los productos.
const std::string kPath2Products = "./data/.products.csv";

/**
 * @brief Almacena los productos en un soporte volátil y eficiente.
 *        Además, gestiona el acceso a ellos.
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
   * @brief Insertar un producto en la base de datos.
   * @param new_product Nuevo producto a insertar.
   */
  void Insert(const Product& new_product);

  /**
   * @brief Elimina el producto de la lista
   *
   * @param product Producto a eliminar
   */
  void Delete(const SearchKey& product);
  /**
   * @brief Busca un producto por clave.
   * @param key Patrón de búsqueda.
   * @return Referencia de lectura/escritura al producto buscado.
   */
  Product& Search(const SearchKey& key);
  /**
   * @brief Búsqueda pero constante.
   */
  const Product& Search(const SearchKey& key) const;
  /**
   * @brief Devuelve todos los registros de productos en la base de datos.
   * @param products Estructura FIFO para guardar los productos.
   */
  void Records(std::queue<Product>& products) const;

 private:
  // Carga los productos desde el fichero de datos.
  void Read(void);
  // Guarda los productos en el fichero de datos.
  void Write(void);

  // Estructura de datos interna para almacenar productos.
  HashTable<SearchKey> hash_;
  // Fichero de datos a modo de almacén no volátil.
  std::fstream data_file_;
};

#endif  // DATA_BASE_H_
