/**
 * @file user_functions.h
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-05-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef USER_FUNCTIONS_H_
#define USER_FUNCTIONS_H_

#include <ctype.h>

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <thread>

#include "./data_base.h"
#include "./login.h"

constexpr int column_size = 6;

using table_t = std::array<std::string, column_size>;

/**
 * @brief Buscar un producto en la base de datos.
 *
 * @param data_base Es la base de datos usada.
 */
void Search(const DataBase& data_base);

/**
 * @brief Editar un producto ya insertado.
 *
 * @param data_base Es la base de datos donde está el producto.
 */
void Edit(DataBase& data_base);

/**
 * @brief Editar un producto ya insertado.
 *
 * @param data_base Es la base de datos donde está el producto.
 * @param p Es la nueva versión del producto.
 */
void Edit(DataBase& data_base, Product& p);

/**
 * @brief Comprar un producto existente.
 *
 * @param data_base Es la base de datos donde está el producto.
 */
void Buy(DataBase& data_base);

/**
 * @brief Insertar un nuevo producto a la base de datos.
 *
 * @param data_base Es la base de datos donde se insertará el producto.
 */
void Insert(Users& user, DataBase& data_base);

/**
 * @brief Borra un producto de la base de datos.
 *
 * @param user Es el usuario dueño del producto a borrar.
 * @param data_base Es la base de datos de la cual se borrará el producto.
 */
void Delete(const Users& user, DataBase& data_base);

/**
 * @brief Se registra un nuevo usuario.
 *
 * @param data_base Es la base de datos relacionada a los usuarios.
 */
void RegisterUser(DataBase& data_base);

/**
 * @brief Se borra un usuario existente en la lista de usuarios disponibles.
 *
 * @param username Es el nombre del usuario a borrar.
 */
void DeleteUser(const std::string& username, DataBase& data_base);

/**
 * @brief Imprime el perfil del usuario.
 *
 * @param user Es el usuario del cual se imprimirán los datos.
 */
void PrintUser(const Users& user);

/**
 * @brief Imprime una tabla con los productos de una cola.
 *
 * @param data Es una cola que contiene todos los productos a imprimir.
 */
void Print(std::queue<Product> data);

/**
 * @brief Convierte una cola de productos a una cola que pueda imprimirse.
 *
 * @param data Es la cola de productos.
 * @return std::queue<table_t> Es una tabla con un formato que es compatible
 *          con la función lambda de dentro de @ref Print()
 */
std::queue<table_t> ProductToTable(std::queue<Product> data);

#endif  // USER_FUNCTIONS_H_
