/**
 * @file menu.cc
 * @author Equipo m5 FIS
 * @brief Interfaz de la aplicación
 * @version 0.1
 * @date 2021-04-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/menu.h"

void start() {
  bool exit = 0;
  do {
    std::pair<Users, bool> logged = login();
    if (logged.second == true) {
      Users user = logged.first;
      menu(user);
      exit = 1;
    } else {
      bool ok = 0;
      char election;
      do {
        std::cout << std::endl
                  << "Nombre de usuario o contraseña incorrectos." << std::endl;
        std::cout << std::endl
                  << "¿Desea salir o volver a intentarlo?\n"
                  << "Pulse 0 para volver a intentarlo.\nPulse 1 para salir.\n"
                  << "Introduzca su opción: ";
        std::cin >> election;
        std::cout << std::endl;
        if ((election == '0') || (election == '1')) {
          ok = 1;
        }
      } while (ok == 0);
      if (election == 1) {
        exit = 1;
      }
    }
  } while (exit == 0);
}

int AdminMenu(const Users& user) {
  system("clear");
  DataBase();
  char election;
  bool ok = 0;
  std::string name = user.username;
  name[0] = toupper(name[0]);
  do {
    std::cout << name << ", Bienvenido a El Plátano de Oro.\n\n"
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
      std::cout << "¡Hasta pronto " << name << "!" << std::endl;
      break;
    default:
      std::cout << "Ha habido algún error inesperado." << std::endl;
      break;
  }
  return 0;
}
