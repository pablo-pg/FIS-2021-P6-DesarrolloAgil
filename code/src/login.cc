/**o
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

std::pair<Users, bool> login() {
  std::string user;
  std::string pass;
  system("clear");
  std::cout << "Introduzca su nombre de usuario: ";
  std::cin >> user;
  std::cout << "Introduzca su contraseña: ";
  std::cin >> pass;
  return comparePass(user, pass);
}

bool niceFormatFile() {
  bool num_comma = 0, row_start = 0, row_middle = 0, row_end = 0,
       permissions = 0, password = 0;
  std::fstream file;
  file.open("./data/.users.csv", std::ios::in);
  if (file.is_open()) {
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
      int comma_count = 0, letter_in_pass = 0;
      if (line.front() != ',') {
        row_start = true;
      }
      if (line.back() != ',') {
        row_end = true;
      }
      for (char character : line) {
        if (character == ',') {
          comma_count++;
        }
      }
      if (comma_count == 2) {
        num_comma = true;
      }
      std::size_t first_comma = line.find(',');
      std::size_t second_comma = line.find(',', first_comma + 1);
      int pass_size = second_comma - first_comma;
      if ((second_comma == std::string::npos) ||
          (first_comma == std::string::npos)) {
        return false;
      } else if (pass_size > 1) {
        row_middle = true;
      }
      for (std::size_t i{first_comma + 1}; i < second_comma; ++i) {
        if (isdigit(line.at(i)) == 0) {
          letter_in_pass++;
        }
      }
      if (letter_in_pass == 0) {
        password = true;
      }
      bool different_permission = 0;
      for (std::size_t i{second_comma + 1}; i < line.size(); ++i) {
        if ((line.at(i) != 'r') && (line.at(i) != 'w') && (line.at(i) != 'c')) {
          different_permission = true;
        }
      }
      if (!different_permission) {
        permissions = true;
      }
    }
  }
  return (num_comma & row_end & row_middle & row_start & permissions &
          password);
}

std::vector<Users> readUsers() {
  std::vector<Users> users;
  users.resize(0);
  std::fstream file;
  file.open("./data/.users.csv", std::ios::in);
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
      for (std::size_t i{0}; i < row[2].size(); ++i) {
        if (row[2].at(i) == 'r') {
          new_user.read = 1;
        }
        if (row[2].at(i) == 'w') {
          new_user.write = 1;
        }
        if (row[2].at(i) == 'c') {
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

std::pair<Users, bool> comparePass(const std::string username,
                                   const std::string pass) {
  std::vector<Users> all_users;
  all_users.resize(1);
  try {
    if (niceFormatFile()) {
      std::vector<Users> all_users = readUsers();
      size_t hashed_pass = std::hash<std::string>{}(pass);
      for (auto& user : all_users) {
        if ((user.username == username) && (user.password == hashed_pass)) {
          return std::make_pair(user, true);
        }
      }
      return std::make_pair(all_users.at(0), false);
    } else {
      std::cout << "El formato del fichero de los usuarios no es correcto\n\n"
                << "Póngase en contacto con la empresa desarrolladora"
                << std::endl;
    }
  } catch (const std::ios_base::failure& fail) {
    std::cerr << "Error (" << fail.code()
              << ") al abrir el archivo: " << fail.what() << std::endl;
    exit(1);
  } catch (...) {
    std::cout << "Error desconocido." << std::endl;
  }
  return std::make_pair(all_users.at(0), false);
}
