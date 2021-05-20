/**
 * @file user_functions.cc
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-05-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/user_functions.h"

void Search(const DataBase& data_base) {
  // void Search() {
  bool exit = 0;
  do {
    system("clear");
    std::string name;
    std::cout << "Introduzca el nombre del producto: ";
    std::cin >> name;
    try {
      const Product p = data_base.Search(name);
      std::queue<Product> data;
      data.push(p);
      Print(data);
      exit = 1;
    } catch (std::out_of_range& e) {
      bool ok = 0;
      std::cout << "\nNo existe el producto introducido.\n\n";
      do {
        std::cout << "  Pulse 1 para volver a intentarlo.\n"
                  << "  Pulse 2 para salir.\n Introduzca la opción: ";
        std::string option;
        std::cin >> option;
        if ((option == "1") || (option == "2")) {
          ok = 1;
        } else {
          system("clear");
          std::cout << "Valor no válido.\n" << std::endl;
        }
        if (option == "2") {
          exit = 1;
        }
      } while (ok == 0);
    }
  } while (exit == 0);
}

void Edit(DataBase& data_base) {
  // void Edit() {
  bool exit = 0;
  system("clear");
  std::string name;
  std::cout << "Introduzca el nombre del producto: ";
  std::cin >> name;
  do {
    system("clear");
    try {
      Product& p = data_base.Search(name);
      std::queue<Product> data;
      data.push(p);  //  Hasta que funcione el search
      Print(data);
      std::string option;
      bool ok = 0;
      do {
        std::cout << "Producto encontrado. Decida qué campo quiere cambiar:\n"
                  << "  1. Nombre\n  2. Stock\n  3. Precio\n"
                  << "  4. Fecha de caducidad\n  5. Origen.\n  6. Salir.\n"
                  << "Introduzca la opción: ";
        std::cin >> option;
        if ((option == "1") || (option == "2") || (option == "3") ||
            (option == "4") || (option == "5") || (option == "6")) {
          ok = 1;
        } else {
          system("clear");
          std::cout << "Opción no válida.\n" << std::endl;
        }
      } while (ok == 0);
      system("clear");
      switch (option.at(0)) {
        case '1': {
          std::string new_name;
          std::cout << "Introduzca el nombre que quiere poner: ";
          std::cin >> new_name;
          if (!new_name.empty()) {
            p.name = new_name;
          } else {
            std::cout << "No se puede cambiar a un nombre vacío. No se harán"
                      << " cambios." << std::endl;
          }
          break;
        }
        case '2': {
          std::string new_stock;
          std::cout << "Introduzca el stock que quiere poner: ";
          std::cin >> new_stock;
          if (!new_stock.empty()) {
            p.stock = std::stoi(new_stock);
          } else {
            std::cout << "No se puede cambiar a un número vacío. No se harán"
                      << " cambios." << std::endl;
          }
          break;
        }
        case '3': {
          std::string new_price;
          std::cout << "Introduzca el precio que quiere poner: ";
          std::cin >> new_price;
          if (!new_price.empty()) {
            p.price = std::stof(new_price);
          } else {
            std::cout << "No se puede cambiar a un costo de 0.0. No se harán"
                      << " cambios." << std::endl;
          }
          break;
        }
        case '4': {
          std::string day, month, year;
          std::cout << "Introduzca el día que quiere poner (2 números): ";
          std::cin >> day;
          std::cout << "Introduzca el mes que quiere poner (2 números): ";
          std::cin >> month;
          std::cout << "Introduzca el año que quiere poner (4 dígitos): ";
          std::cin >> year;
          if ((!day.empty()) && (!month.empty()) && (!year.empty()) &&
              (year.size() == 4) && (day.size() <= 2) && (month.size() <= 2) &&
              (day.size() > 0) && (month.size() > 0)) {
            time_t raw_time;
            struct tm* tm;
            time(&raw_time);
            tm = localtime(&raw_time);
            tm->tm_year = std::stoi(year) - 1900;
            tm->tm_mon = std::stoi(month) - 1;
            tm->tm_mday = std::stoi(day);

            time_t time = mktime(tm);

            p.expiration = time;
          } else {
            std::cout << "El formato de la fecha no es correcto." << std::endl;
          }
          break;
        }
        case '5': {
          std::string new_origin;
          std::cout << "Introduzca el lugar de origen que quiere poner "
                    << "(una palabra): ";
          std::cin >> new_origin;
          if (!new_origin.empty()) {
            p.origin = new_origin;
          } else {
            std::cout << "No se puede cambiar a un numero vacío. No se harán"
                      << " cambios." << std::endl;
          }
          break;
        }
        case '6':
          exit = 1;
          break;
        default:
          std::cout << "Error de opción." << std::endl;
          break;
      }
      std::cout << "¿Desea seguir editando?\n  1. Sí.\n  2. No" << std::endl;
      std::cout << "Introduzca la opción: ";
      std::string exit_op;
      std::cin >> exit_op;
      if (exit_op == "2") {
        exit = 1;
      } else if (exit_op != "1") {
        std::cout << "Opción no válida. Volverá a ls edición";
      }
    } catch (std::out_of_range& e) {
      bool ok = 0;
      std::cout << "\nNo existe el producto introducido.\n\n";
      do {
        std::cout << "  Pulse 1 para volver a intentarlo.\n"
                  << "  Pulse 2 para salir.\n Introduzca la opción: ";
        std::string option;
        std::cin >> option;
        if ((option == "1") || (option == "2")) {
          ok = 1;
        } else {
          system("clear");
          std::cout << "Valor no válido.\n" << std::endl;
        }
        if (option == "2") {
          exit = 1;
        }
      } while (ok == 0);
    }
  } while (exit == 0);
}

void Edit(DataBase& data_base, Product& p) {
  try {
    Product original = data_base.Search(p.name);
    original = p;
  } catch (std::runtime_error& e) {
    std::cout << "Error: " << e.what();
  }
}

void Buy(DataBase& data_base) {
  system("clear");
  std::string name;
  std::cout << "Introduzca el nombre del producto: ";
  std::cin >> name;
  try {
    Product& p = data_base.Search(name);
    std::queue<Product> data;
    data.push(p);
    Print(data);
    std::string option;
    bool ok = 0;
    do {
      std::cout << "Producto encontrado. ¿Desea comprarlo?\n"
                << "  1. Sí\n  2. No.\n"
                << "Introduzca la opción: ";
      std::cin >> option;
      if ((option == "1") || (option == "2")) {
        ok = 1;
      } else {
        system("clear");
        std::cout << "Opción no válida.\n" << std::endl;
      }
    } while (ok == 0);
    if (option == "1") {
      std::string str_cuantity;
      std::cout << "Introduzca cuántos quiere: ";
      std::cin >> str_cuantity;
      unsigned long cuantity = std::stoul(str_cuantity);
      if (cuantity <= p.stock) {
        p.stock -= cuantity;
      } else {
        std::cout << "No hay suficientes productos. Se cancela la compra."
                  << std::endl;
      }
    } else {
      std::cout << "Compra cancelada." << std::endl;
    }
  } catch (std::out_of_range& e) {
    bool ok = 0;
    std::cout << "\nNo existe el producto introducido.\n\n";
    do {
      std::cout << "  Pulse 1 para volver a intentarlo.\n"
                << "  Pulse 2 para salir.\n Introduzca la opción: ";
      std::string option;
      std::cin >> option;
      if ((option == "1") || (option == "2")) {
        ok = 1;
      } else {
        system("clear");
        std::cout << "Valor no válido.\n" << std::endl;
      }
      if (option == "2") {
      }
    } while (ok == 0);
  }
}

void Insert(DataBase& data_base) {
  system("clear");
  Product new_prod;
  bool ok = 0;
  std::string name;
  std::string origin;
  int id;
  int stock;
  float price;
  do {  // ID
    std::cout << "Introduzca el ID: ";
    std::string str_id;
    std::cin >> str_id;
    id = std::stoi(str_id);
    if (id < 0) {
      id = -id;
      std::cout << "Introdució una id negativa, cambiando el signo."
                << std::endl;
    } else if (id == 0) {
      bool ok2 = 0;
      do {
        std::string opt;
        std::cout << "No puede introducir 0 como id\n"
                  << "  Pulse 1 para volver a introducir"
                  << "  Pulse 2 para cancelar.\n\n"
                  << "Introduzca su opción: ";
        std::cin >> opt;
        if ((opt == "1") || (opt == "2")) {
          ok2 = 1;
        }
        if (opt == "2") {
          std::cout << "Inserción cancelada." << std::endl;
          return;
        }
      } while (ok2 == 0);
    } else {
      ok = 1;
    }
  } while (ok == 0);
  ok = 0;
  do {  // NAME
    std::cout << "Introduzca el nombre: ";
    std::cin >> name;
    if (!name.empty()) {
      ok = 1;
    } else {
      bool ok2 = 0;
      do {
        std::string opt;
        std::cout << "No puede introducir una cadena vacía como nombre.\n"
                  << "  Pulse 1 para volver a introducir"
                  << "  Pulse 2 para cancelar.\n\n"
                  << "Introduzca su opción: ";
        std::cin >> opt;
        if ((opt == "1") || (opt == "2")) {
          ok2 = 1;
        }
        if (opt == "2") {
          std::cout << "Inserción cancelada." << std::endl;
          return;
        }
      } while (ok2 == 0);
    }
  } while (ok == 0);
  ok = 0;
  do {  // PRICE
    std::cout << "Introduzca el precio: ";
    std::string str_price;
    std::cin >> str_price;
    price = std::stof(str_price);
    if (price == 0) {
      bool ok2 = 0;
      do {
        std::string opt;
        std::cout << "No puede introducir un precio de 0€.\n"
                  << "  Pulse 1 para volver a introducir"
                  << "  Pulse 2 para cancelar.\n\n"
                  << "Introduzca su opción: ";
        std::cin >> opt;
        if ((opt == "1") || (opt == "2")) {
          ok2 = 1;
        }
        if (opt == "2") {
          std::cout << "Inserción cancelada." << std::endl;
          return;
        }
      } while (ok2 == 0);
    } else if (price < 0.0) {
      price = -price;
      std::cout << "Introdujo un precio negativo. Cambiando el signo."
                << std::endl;
    } else {
      ok = 1;
    }
  } while (ok == 0);
  do {  // STOCK
    std::cout << "Introduzca el stock: ";
    std::string str_stock;
    std::cin >> str_stock;
    stock = std::stoi(str_stock);
    if (stock == 0) {
      bool ok2 = 0;
      do {
        std::string opt;
        std::cout << "No puede introducir una cadena vacía como nombre.\n"
                  << "  Pulse 1 para volver a introducir"
                  << "  Pulse 2 para cancelar.\n\n"
                  << "Introduzca su opción: ";
        std::cin >> opt;
        if ((opt == "1") || (opt == "2")) {
          ok2 = 1;
        }
        if (opt == "2") {
          std::cout << "Inserción cancelada." << std::endl;
          return;
        }
      } while (ok2 == 0);
    } else if (price < 0.0) {
      price = -price;
      std::cout << "Introdujo un precio negativo. Cambiando el signo."
                << std::endl;
    } else {
      ok = 1;
    }
  } while (ok == 0);
  ok = 0;
  do {  // EXPIRATION
    std::string day, month, year;
    std::cout << "Introduzca el día que quiere poner (2 números): ";
    std::cin >> day;
    std::cout << "Introduzca el mes que quiere poner (2 números): ";
    std::cin >> month;
    std::cout << "Introduzca el año que quiere poner (4 dígitos): ";
    std::cin >> year;
    if ((!day.empty()) && (!month.empty()) && (!year.empty()) &&
        (year.size() == 4) && (day.size() <= 2) && (month.size() <= 2) &&
        (day.size() > 0) && (month.size() > 0)) {
      time_t raw_time;
      struct tm* tm;
      time(&raw_time);
      tm = localtime(&raw_time);
      tm->tm_year = std::stoi(year) - 1900;
      tm->tm_mon = std::stoi(month) - 1;
      tm->tm_mday = std::stoi(day);

      time_t time = mktime(tm);

      new_prod.expiration = time;
      ok = 1;
    } else {
      std::cout << "La hora es incorrecta. Vuelva a intentarlo" << std::endl;
    }
  } while (ok == 0);
  ok = 0;
  do {  // ORIGIN
    std::string election;
    std::cout << "¿Desea introducir el lugar de origen?\n  1. Sí.\n  2. No.\n"
              << "Introduzca su opción: ";
    std::cin >> election;
    if (election == "2") {
      ok = 1;
    } else if (election == "1") {
      std::cout << "\nIntroduzca el lugar de origen (una palabra): ";
      std::cin >> origin;
      if (origin.empty()) {
        std::cout << "No se pueden introducir lugares vacíos. Se pondrá uno por"
                  << " defecto." << std::endl;
        origin = "Ninguno";
      }
    }
    ok = 1;
  } while (ok == 0);
  new_prod.id = id;
  new_prod.name = name;
  new_prod.stock = stock;
  new_prod.price = price;
  new_prod.origin = origin;
  data_base.Insert(new_prod);
}

void PrintUser(const Users& user) {
  std::cout << "Nombre de usuario: " << user.username << "\n"
            << "Valoración: " << std::setprecision(3) << user.rating << "\n"
            << "Productos en venta:" << std::endl;
  for (const auto& prod : user.products) {
    std::cout << "  " << prod.name << std::endl;
  }
  std::cout << "Métodos de pago:" << std::endl;
  for (const auto& pay : user.accepted_payment) {
    switch (pay) {
      case PayPal:
        std::cout << "  " << "PayPal" << std::endl;
        break;
      case BankAccount:
        std::cout << "  " << "Transferencia bancaria" << std::endl;
        break;
      case Bizum:
        std::cout << "  " << "Bizum" << std::endl;
        break;
      default:
        std::cout << "Error al imprimir los métodos de pago. Método no aceptado"
                  << std::endl;
        break;
    }
  }
  std::cout << std::endl << std::endl;
}

void Print(std::queue<Product> p_data) {
  std::queue<table_t> data = ProductToTable(p_data);
  table_t headers{{"ID", "NAME", "STOCK", "PRICE", "DATE", "PLACE"}};
  constexpr int id_wid = 7;
  constexpr int name_wid = 20;
  constexpr int stock_id = 7;
  constexpr int price_id = 10;
  constexpr int date_wid = 15;
  constexpr int place_wid = 25;
  auto print_line = [](table_t const& tbl) {
    /// NO CAMBIAR. SON ARGUMENTOS QUE DECLARADOS EN EJEC, NO EN COMPILACIÓN.
    auto const& [ID, NAME, STOCK, PRICE, DATE, PLACE] = tbl;  //< NO SON FALLOS
    std::cout.width(id_wid);
    std::cout << ("| " + ID) << '|';
    std::cout.width(name_wid);
    std::cout << ("| " + NAME) << '|';
    std::cout.width(stock_id);
    std::cout << (' ' + STOCK) << '|';
    std::cout.width(price_id);
    std::cout << (' ' + PRICE) << '|';
    std::cout.width(date_wid);
    std::cout << (' ' + DATE) << '|';
    std::cout.width(place_wid);
    std::cout << (' ' + PLACE) << '|';
    std::cout << '\n';
  };
  constexpr int total_wid = id_wid + name_wid + stock_id + price_id + date_wid +
                            place_wid + column_size;
  auto print_break = [] {
    std::cout.width(total_wid);
    std::cout.fill('-');
    std::cout << "-" << '\n';
    std::cout.fill(' ');
  };
  std::cout.setf(std::ios::left, std::ios::adjustfield);
  print_break();
  print_line(headers);
  print_break();
  while (!data.empty()) {
    auto element = data.front();
    data.pop();
    print_line(element);
    print_break();
  }
}

std::queue<table_t> ProductToTable(std::queue<Product> data) {
  std::queue<table_t> result;
  while (!data.empty()) {
    Product p = data.front();
    std::tm* timeinfo = std::localtime(&p.expiration);
    char buffer[32];
    strftime(buffer, 80, "%d/%m/%Y", timeinfo);
    std::string p_time(buffer);

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << p.price;
    std::string str_price = stream.str();
    table_t element{std::to_string(p.id),
                    p.name,
                    std::to_string(p.stock),
                    str_price,
                    p_time,
                    p.origin};
    data.pop();
    result.push(element);
  }
  return result;
}
