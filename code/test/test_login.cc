/**
 * @file test_login.h
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-05-06
 * @copyright Copyright (c) 2021
 *
 */

// #include <iostream>

#include <utility>
#include <string>

#include "../src/login.cc"


std::vector<Users> CopyreadUsersfor() {
  std::vector<Users> users;
  users.resize(0);
  std::fstream file;
  file.open("../data/.users.csv", std::ios::in);
  if (file.is_open()) {
    int count = 0;
    std::vector<std::string> row;
    std::string line, word;
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
      /// Convierto la contraseña de string a size_t (no hay cast por defecto)
      std::stringstream sspass(row[1]);
      size_t pass;
      sspass >> pass;
      new_user.password = pass;
      /// Permisos
      for (std::size_t i{0}; i < row[3].size(); ++i) {
        if (row[3].at(i) == 'r') {
          new_user.read = 1;
        }
        if (row[3].at(i) == 'w') {
          new_user.write = 1;
        }
        if (row[3].at(i) == 'c') {
          new_user.admin = 1;
        }
      }
      users.push_back(new_user);
    }
  } else {
    file.exceptions(std::fstream::failbit);
  }
  return users;
}

std::pair<Users, bool> TestComparePass(const std::string username,
                                       const std::string pass) {
  std::vector<Users> users = CopyreadUsersfor();
  for (auto& user : users) {
    if ((username == user.username) &&
        (std::hash<std::string>{}(pass) == user.password)) {
      return std::make_pair(user, true);
    }
  }
  return std::make_pair(users.at(0), false);
}


std::pair<Users, bool> CopyComparePass(const std::string username,
                                   const std::string pass) {
  std::vector<Users> all_users;
  all_users.resize(1);
  try {
    // if (niceFormatFile()) {
      std::vector<Users> all_users = CopyreadUsersfor();
      size_t hashed_pass = std::hash<std::string>{}(pass);
      for (auto& user : all_users) {
        if ((user.username == username) && (user.password == hashed_pass)) {
          return std::make_pair(user, true);
        }
      }
      return std::make_pair(all_users.at(0), false);
    // } else {
    //   std::cout << "El formato del fichero de los usuarios no es correcto\n\n"
    //             << "Póngase en contacto con la empresa desarrolladora"
    //             << std::endl;
    // }
  } catch (const std::ios_base::failure& fail) {
    std::cerr << "Error (" << fail.code()
              << ") al abrir el archivo: " << fail.what() << std::endl;
    exit(1);
  } catch (...) {
    std::cout << "Error desconocido." << std::endl;
  }
  return std::make_pair(all_users.at(0), false);
}


bool TestLogin() {
  bool login1 = 0, login2 = 0, login3 = 0, login4 = 0;
  std::string user = "sfihsjefoishdofi";   //< user y pass no existentes
  std::string pass = "sdflishjflsiejfo";
  if (CopyComparePass(user, pass) == TestComparePass(user, pass)) {
    login1 = 1;
  }
  user = "pepe";                  //< user y pass existentes
  pass = "pepe";
  if (CopyComparePass(user, pass) == TestComparePass(user, pass)) {
    login2 = 1;
  }
  user = "pepe";                  //< user y pass existentes de otros usuarios
  pass = "juan";
  if (CopyComparePass(user, pass) == TestComparePass(user, pass)) {
    login3 = 1;
  }
  user = "pepe";                  //< user existente y pass no
  pass = "srfkosijfghseoif";
  if (CopyComparePass(user, pass) == TestComparePass(user, pass)) {
    login3 = 1;
  }
  user = "sdfsefsefs";                  //< user no existente y pass sí
  pass = "admin";
  if (CopyComparePass(user, pass) == TestComparePass(user, pass)) {
    login3 = 1;
  }
  return (login1 & login2 & login3 & login4);
}


int main() {
  if (TestLogin())
    std::cout << "TEST LOGIN: ACEPTADO." << std::endl;
  else
      std::cout << "TEST LOGIN: RECHAZADO." << std::endl;
}
