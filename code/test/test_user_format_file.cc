/**
 * @file test_user_format_file.cc
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

#include "../include/login.h"

/**
 * @brief Método copiado pero quitando toda la parte de los archivos.
 * 
 * @param line es la linea que leería desde el archivo;
 */
bool NiceFormatFileCopy(const std::string& line) {
  bool num_comma = 0, row_start = 0, row_middle = 0, row_end = 0,
       permissions = 0, password = 0;
  int comma_count = 0, nums_in_pass = 0;
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
  if (second_comma == std::string::npos) {
    return false;
  } else if ((second_comma - first_comma) > 1) {
    row_middle = true;
  }
  for (std::size_t i {first_comma}; i < second_comma; ++i) {
    if (isdigit(line.at(i)) == 0) {
      nums_in_pass++;
    }
  }
  if (nums_in_pass == 0) {
    password = true;
  }
  bool different_permission = 0;
  for (std::size_t i {second_comma}; i < line.size(); ++i) {
    if ((line.at(i) != 'r') || (line.at(i) != 'w') || (line.at(i) != 'c')) {
      different_permission = true;
    }
  }
  if (!different_permission) {
    permissions = true;
  }
  return (num_comma & row_end & row_middle & row_start & permissions, & password);
}

bool TestNiceFormatFile() {
  int correct_test = 0;
  bool result = 0, test;
  // Todas deben salir 0
  std::string test_line = "";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = ",";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = ",,";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = ",,,";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "us,";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,13854";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,a13854,rwc";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,13854a,rwc";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,138a54,rwc";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,138 54,rwc";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,13854,a";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,13854,ra";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,13854,rrwc";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,13854,rwcc";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,13854,1";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,13854,rw2c";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  std::string test_line = "user,13854,rwc0";
  test = NiceFormatFileCopy(test_line);
  if (test == 0) {
    correct_test++;
  }
  // Debe salir 1
  std::string test_line = "user,13854,crw";
  test = NiceFormatFileCopy(test_line);
  if (test == 1) {
    correct_test++;
  }
  std::string test_line = "user,13854,rwc";
  test = NiceFormatFileCopy(test_line);
  if (test == 1) {
    correct_test++;
  }
  ///////////////// FIN SUBTESTS ///////////////////
  if (correct_test == 19) {
    result  = true;
  }
  return result;
}


int main() {

  TestNiceFormatFile();

}
