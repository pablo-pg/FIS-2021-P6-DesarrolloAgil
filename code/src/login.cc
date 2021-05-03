/**
 * @file login.cc
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-05-2
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/login.h"


std::vector<Users> readUsers() {
  std::vector<Users> users;
  users.resize(0);
  std::fstream file;
  file.open("./data/.users.csv", std::ios::in);
  if (file.is_open()) {
    int count = 0;
    std::vector<std::string> row;
    std::string line, word, temp;
    std::getline(file, line);  //< Da igual la primera linea
    while (std::getline(file, line)) {
      row.clear();
      std::stringstream ss_line(line);
      /// Se introduce en el vector todas las palabras de la linea
      while (std::getline(ss_line, word, ',')) {
        row.push_back(word);
      }
      count++;
      Users new_user;
      new_user.username = row[0];
      /// Convierto la contraseña de string a size_t (no hay metodo por defecto)
      std::stringstream sspass(row[1]);
      size_t pass;
      sspass >> pass;
      new_user.password = pass;
      /// Permisos
      for (int i {0}; i < row[3].size(); ++i) {
        if (row[3].at(i) == 'r') {
          new_user.read = 1;
        }
        if (row[3].at(i) == 'w') {
          new_user.write = 1;
        }
        if (row[3].at(i) == 'c') {
          new_user.create = 1;
        }
      }
      users.push_back(new_user);
    }
  }
  return users;
}



bool comparePass(const std::string username, const std::string pass) {
  try {
    std::vector<Users> all_users = readUsers();
    size_t hashed_pass = std::hash<std::string> {} (pass);
    for (auto& user : all_users) {
      if ((user.username == username) && (user.password == hashed_pass)) {
        return true;
      }
    }
    return false;
  }
  catch(...) {
    std::cout << "Ha pasado algo malo" << std::endl;
  }
  return false;
}
