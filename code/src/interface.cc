/**
 * @file interface.cc
 * @author Equipo m5 FIS
 * @brief Interfaz de la aplicación
 * @version 0.1
 * @date 2021-04-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/interface.h"

void start() {
  bool exit = 0;
  do {
    if (login()) {
      menu();
      exit = 1;
    } else {
      bool ok = 0;
      int election;
      do {
        std::cout << std::endl
                  << "Nombre de usuario o contraseña incorrectos." << std::endl;
        std::cout << std::endl
                  << "¿Desea salir o volver a intentarlo?\n"
                  << "Pulse 0 para volver a intentarlo.\nPulse 1 para salir.\n"
                  << "Introduzca su opción: ";
        std::cin >> election;
        std::cout << std::endl;
        if ((election == 0) || (election == 1)) {
          ok = 1;
        }
      } while (ok == 0);
      if (election == 1) {
        exit = 1;
      }
    }
  } while (exit == 0);
}

bool login() {
  std::string user;
  std::string pass;
  std::cout << "Introduzca su nombre de usuario: ";
  std::cin >> user;
  std::cout << "Introduzca su contraseña: ";
  std::cin >> pass;
  return true;
}

int menu() {
  system("clear");
  DataBase();
  char election;
  bool ok = 0;
  do {
    std::cout << "Bienvenido a El Plátano de Oro.\n\n"
              << "¿Qué desea hacer?\n"
              << "Pulse 1 para añadir un nuevo producto a la base de datos.\n"
              << "Pulse 2 para modificar los datos de un producto ya existente."
              << "\nPulse 3 para eliminar un producto.\n"
              << "Pulse 4 para ver los datos de un producto.\n"
              << "Pulse 5 para ver todos los productos.\n"
              << "Pulse q para salir.\n\n"
              << "Introduzca la opción: ";
    std::cin >> election;
    if ((election == '1') || (election == '2') || (election == '3') ||
        (election == '4') || (election == '5') || (election == 'q')) {
      ok = 1;
    } else {
      std::cout << "Opción incorrecta. Pruebe de nuevo";
    }
  } while (ok == 0);
  switch (election) {
    case '1':
      /* code */
      break;
    case '2':
      /* code */
      break;
    case '3':
      /* code */
      break;
    case '4':
      /* code */
      break;
    case '5':
      /* code */
      break;
    case 'q':
      std::cout << "¡Hasta pronto!" << std::endl;
      break;
    default:
      std::cout << "Ha habido algún error inesperado." << std::endl;
      break;
  }
  return 0;
}
