/**
 * @file test_login.h
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-05-06
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

#include "../include/login.h"


std::pair<Users, bool> TestComparePass(const std::string username,
                                       const std::string pass) {
  std::vector<Users> users = readUsers();
  for (auto& user : users) {
    if ((username == user.username) &&
        (std::hash<std::string>{}(pass) == user.password)) {
      return std::make_pair(user, true);
    }
  }
  return std::make_pair(users.at(0), false);
}


bool TestLogin() {
  bool login1 = 0, login2 = 0, login3 = 0, login4 = 0;
  std::string user = "sfihsjefoishdofi";   //< user y pass no existentes
  std::string pass = "sdflishjflsiejfo";
  if (comparePass(user, pass) == TestComparePass(user, pass)) {
    login1 = 1;
  }
  user = "pepe";                  //< user y pass existentes
  pass = "pepe";
  if (comparePass(user, pass) == TestComparePass(user, pass)) {
    login2 = 1;
  }
  user = "pepe";                  //< user y pass existentes de otros usuarios
  pass = "juan";
  if (comparePass(user, pass) == TestComparePass(user, pass)) {
    login3 = 1;
  }
  user = "pepe";                  //< user existente y pass no
  pass = "srfkosijfghseoif";
  if (comparePass(user, pass) == TestComparePass(user, pass)) {
    login3 = 1;
  }
  user = "sdfsefsefs";                  //< user no existente y pass sí
  pass = "admin";
  if (comparePass(user, pass) == TestComparePass(user, pass)) {
    login3 = 1;
  }
  return (login1 & login2 & login3 & login4);
}


int main() {

  TestLogin();

}
