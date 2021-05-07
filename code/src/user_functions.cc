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


// void Search(const DataBase& data_base) {
void Search() {
  bool exit = 0;
  do {
    system("clear");
    std::string name;
    std::cout << "Introduzca el nombre del producto: ";
    std::cin >> name;
    try {
    // const Product p = data_base.Search(name);
      std::queue<Product> data;
      // data.push(p);
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


void Edit(const DataBase& data_base) {
// void Edit() {
  bool exit = 0;
  do {
    system("clear");
    std::string name;
    std::cout << "Introduzca el nombre del producto: ";
    std::cin >> name;
    try {
      Product p = data_base.Search(name);
      std::queue<Product> data;
      // data.push(p);
      Print(data);
      std::string option;
      bool ok = 0;
      do {
        std::cout << "Producto encontrado. Decida qué campo quiere cambiar:\n"
                  << "  1. Nombre\n  2. Stock\n  3. Precio\n"
                  << "  4. Fecha de caducidad\n  5. Origen.\n  6. Cancelar.\n"
                  << "Introduzca la opción: ";
        std::cin >> option;
        if ((option == "1") || (option == "2") || (option == "3")
         || (option == "4") || (option == "5") || (option == "6")) {
           ok = 1;
        } else {
          system("clear");
          std::cout << "Opcioón no válida.\n" << std::endl;
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
          break; }
        case '2': {
          std::string new_stock;
          std::cout << "Introduzca el nombre que quiere poner: ";
          std::cin >> new_stock;
          if (!new_stock.empty()) {
            p.stock = std::stoi(new_stock);
          } else {
            std::cout << "No se puede cambiar a un numero vacío. No se harán"
                      << " cambios." << std::endl;
          }
          break; }
        case '3': {
          std::string new_price;
          std::cout << "Introduzca el precio que quiere poner: ";
          std::cin >> new_price;
          if (!new_price.empty()) {
            p.price = std::stof(new_price);
          } else {
            std::cout << "No se puede cambiar a un numero vacío. No se harán"
                      << " cambios." << std::endl;
          }
          break; }
        case '4': {
          std::string day, month, year;
          std::cout << "Introduzca el día que quiere poner (número): ";
          std::cin >> day;
          std::cout << "Introduzca el mes que quiere poner (número): ";
          std::cin >> month;
          std::cout << "Introduzca el año que quiere poner (número): ";
          std::cin >> year;
          if ((!day.empty()) && (!day.empty()) && (!day.empty())) {
            struct tm tm;
            std::stringstream ss;
            ss << day << '/' << month << '/' << year;
            strptime(ss.str().data(), "%d/%m/%y", &tm);
            time_t new_time = mktime(&tm);
            p.expiration = new_time;
          } else {
            std::cout << "No se puede cambiar a un numero vacío. No se harán"
                      << " cambios." << std::endl;
          }
          break; }
        case '5': {
          std::string new_origin;
          std::cout << "Introduzca el lugar de origen que quiere poner: ";
          std::cin >> new_origin;
          if (!new_origin.empty()) {
            p.origin = new_origin;
          } else {
            std::cout << "No se puede cambiar a un numero vacío. No se harán"
                      << " cambios." << std::endl;
          }
          break; }
        case '6':
          exit = 1;
          break;
      default: std::cout << "Error de opción." << std::endl;
        break;
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


// void Insert(const DataBase& data_base) {
void Insert() {
  system("clear");
  // std::cout << 
}




/// Método test
void TestPrint() {
  Product p { 1234, "manzana", 23, 2.3, std::time(nullptr), "Lamatana"};
  std::queue<Product> test;
  test.push(p);
  Print(test);
}

void Print(std::queue<Product> p_data) {
  std::queue<table_t> data = ProductToTable(p_data);
  table_t headers{ { "ID", "NAME", "STOCK", "PRICE", "DATE", "PLACE" } };
  constexpr int id_wid  = 7;
  constexpr int name_wid = 20;
  constexpr int stock_id = 7;
  constexpr int price_id = 15;
  constexpr int date_wid = 30;
  constexpr int place_wid  = 18;
  auto print_line = [](table_t const &tbl) {
    /// NO CAMBIAR. SON ARGUMENTOS QUE DECLARADOS EN EJEC, NO EN COMPILACIÓN.
    auto const &[ID, NAME, STOCK, PRICE, DATE, PLACE] = tbl;  //< NO SON FALLOS
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
    std::tm * timeinfo = std::localtime(&p.expiration);
    char buffer[32];
    strftime(buffer, 80, "%d/%m/%y", timeinfo);
    std::string p_time(buffer);

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << p.price;
    std::string str_price = stream.str();
    table_t element {std::to_string(p.id), p.name, std::to_string(p.stock),
                    str_price, p_time, p.origin};
    data.pop();
    result.push(element);
  }
  return result;
}
