/**
 * @file login.h
 * @author Equipo m5 FIS
 * @brief Cabecera de código para el login de usuarios.
 * @version 0.1
 * @date 2021-05-2
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef LOGIN_H_
#define LOGIN_H_

#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief Estructura que define los campos que tiene un usuario.
 * 
 */
struct Users {
  std::string username;     //< Nombre de usuario.
  size_t password;          //< Contraseña cifrada.
  bool read = 1;            //< Bit de permiso de lectura.
  bool write = 0;           //< Bit de permiso de escritura.
  bool admin = 0;           //< Bit de permiso de creación/eliminación.

  Users& operator=(const Users& rhl) {
    username = rhl.username;
    password = rhl.password;
    read = rhl.read;
    write = rhl.write;
    admin = rhl.admin;
    return *this;
  }
};

/**
 * @brief Método encargado de introducir credenciales y gestiona la aprobación
 * o no del usuario.
 * 
 * @return std::pair<Users, bool>. User es el usuario (si no se encuentra es
 * el primer usuario registrado) y bool determina si se encontró o no.
 */
std::pair<Users, bool> login();

/**
 * @brief Comprueba el formato del fichero CSV de usuarios.
 * 
 * @return true en el caso de que el formato esté bien.
 * @return false en el casod e que el formato está mal.
 */
bool niceFormatFile();

/**
 * @brief Se encarga de leer a los usuarios del fichero .csv
 * 
 * @return std::vector<Users> . Es un vector con todos los usuarios del fichero.
 */
std::vector<Users> readUsers();

/**
 * @brief Comprueba si el usuario o contraseña coincide con alguno registrado.
 * 
 * @param user Es el nombre de usuario a comprobar.
 * @param pass Es la contraseña sin cifrar del usuario a comprobar.
 * @return std::pair<Users, bool>. User es el usuario (si no se encuentra es
 * el primer usuario registrado) y bool determina si se encontró o no. 
 */
std::pair<Users, bool> comparePass(const std::string user,
                                   const std::string pass);

#endif  // LOGIN_H_
