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

enum Mode { client, seller };

struct Users {
  std::string username;
  size_t password;
  bool read = 1;
  bool write = 0;
  bool create = 0;
  Users& operator=(const Users& rhl) {
    username = rhl.username;
    password = rhl.password;
    read = rhl.read;
    write = rhl.write;
    create = rhl.create;
    return *this;
  }
};

std::pair<Users, bool> login();
std::vector<Users> readUsers();
std::pair<Users, bool> comparePass(const std::string user,
                                   const std::string pass);

#endif  // LOGIN_H_
