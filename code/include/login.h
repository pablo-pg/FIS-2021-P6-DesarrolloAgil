/**
 * @file login.h
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
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
#include <vector>

enum Mode { client, seller };

struct Users {
  std::string username;
  size_t password;
  bool read = 1;
  bool write = 0;
  bool create = 0;
};

std::vector<Users> readUsers();
bool comparePass(const std::string user, const std::string pass);

#endif  // LOGIN_H_
