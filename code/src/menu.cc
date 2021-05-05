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
      EntryMode(user);
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

int EntryMode(const Users& user) {
  if (user.read) {
    std::string selection;
    if ((user.create | user.write) == 0) {      //< Comprador
        return BuyerMenu(user);
    } else if (user.write && !user.create) {    //< Vendedor
      bool ok = 0;
      do {
        std::cout << "Seleccione como qué rol quiere entrar:\n\t1. Vendedor"
                  << "\n\t2. Comprador\nSeleccione el rol: ";
        std::cin >> selection;
        if ((selection == "1") || (selection == "2")) {
          ok = 1;
        } else {
          std::cout << "Opción incorrecta." << std::endl << std::endl;
        }
      } while (ok == 0);
      if (selection == "1") {
        return SellerMenu(user);
      } else if (selection == "2") {
        return BuyerMenu(user);
      }
    } else if (user.write && user.create) {     //< Admin con write
      bool ok = 0;
      do {
        std::cout << "Seleccione como qué rol quiere entrar:\n\t1. Vendedor"
                  << "\n\t2. Comprador\n3. Administrador\nSeleccione el rol: ";
        std::cin >> selection;
        if ((selection == "1") || (selection == "2") || (selection == "3")) {
          ok = 1;
        } else {
          std::cout << "Opción incorrecta." << std::endl << std::endl;
        }
      } while (ok == 0);
      if (selection == "1") {
        return SellerMenu(user);
      } else if (selection == "2") {
        return BuyerMenu(user);
      } else if (selection == "3") {
        return AdminWriteMenu(user);
      }
    } else if (!user.write && user.create) {  //< Admin sin write
      bool ok = 0;
      do {
        std::cout << "Seleccione como qué rol quiere entrar:\n\t1. Comprador"
                  << "\n\t2. Administrador\nSeleccione el rol: ";
        std::cin >> selection;
        if ((selection == "1") || (selection == "2")) {
          ok = 1;
        } else {
          std::cout << "Opción incorrecta." << std::endl << std::endl;
        }
      } while (ok == 0);
      if (selection == "1") {
        return SellerMenu(user);
      } else if (selection == "2") {
        return AdminReadMenu(user);
      }
    }
  } else {
    std::cout << "No tiene permisos para ver nada. No puede acceder."
              << std::endl;
  }
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////// MENÚS /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

int BuyerMenu(const Users& user) {
  system("clear");
  DataBase();
  char election;
  bool ok = 0;
  std::string name = user.username;
  name[0] = toupper(name[0]);
  do {
    std::cout << name << ", Bienvenido a El Plátano de Oro.\n\n"
              << "¿Qué desea hacer?\n"
              << "Pulse 1 para ver los datos de un producto.\n"
              << "Pulse 2 para ver todos los productos.\n"
              << "Pulse 3 para comprar un producto.\n"
              << "Pulse q para salir.\n\n"
              << "Introduzca la opción: ";
    std::cin >> election;
    if ((election == '1') || (election == '2') || (election == '3') ||
        (election == 'q')) {
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
      /* code */  //< Esto es modificar stock -1
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


int SellerMenu(const Users& user) {
  system("clear");
  DataBase();
  char election;
  bool ok = 0;
  std::string name = user.username;
  name[0] = toupper(name[0]);
  do {
    std::cout << name << ", Bienvenido a El Plátano de Oro.\n\n"
              << "¿Qué desea hacer?\n"
              << "Pulse 1 para ver los datos de un producto.\n"
              << "Pulse 2 para ver todos los productos.\n"
              << "Pulse 3 para modificar los datos de un producto ya existente."
              << "Pulse q para salir.\n\n"
              << "Introduzca la opción: ";
    std::cin >> election;
    if ((election == '1') || (election == '2') || (election == '3') ||
        (election == 'q')) {
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
    case 'q':
      std::cout << "¡Hasta pronto " << name << "!" << std::endl;
      break;
    default:
      std::cout << "Ha habido algún error inesperado." << std::endl;
      break;
  }
  return 0;
}


int AdminReadMenu(const Users& user) {
  system("clear");
  DataBase();
  char election;
  bool ok = 0;
  std::string name = user.username;
  name[0] = toupper(name[0]);
  do {
    std::cout << name << ", Bienvenido a El Plátano de Oro.\n\n"
              << "¿Qué desea hacer?\n"
              << "Pulse 1 para ver los datos de un producto.\n"
              << "Pulse 2 para ver todos los productos.\n"
              << "Pulse 3 para crear un nuevo producto."
              << "Pulse q para salir.\n\n"
              << "Introduzca la opción: ";
    std::cin >> election;
    if ((election == '1') || (election == '2') || (election == '3') ||
        (election == 'q')) {
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
    case 'q':
      std::cout << "¡Hasta pronto " << name << "!" << std::endl;
      break;
    default:
      std::cout << "Ha habido algún error inesperado." << std::endl;
      break;
  }
  return 0;
}



int AdminWriteMenu(const Users& user) {
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
