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

#ifndef CODE_INCLUDE_LOGIN_H_
#define CODE_INCLUDE_LOGIN_H_

#include <iostream>
#include <ios>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

struct Users {
  std::string username;
  size_t password;
  bool read = 0;
  bool write = 0;
  bool create = 0;
};

std::vector<Users> readUsers();
bool comparePass(const std::string user, const std::string pass);


#endif  // CODE_INCLUDE_LOGIN_H_
