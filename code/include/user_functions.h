/**
 * @file user_functions.h
 * @author Equipo m5 FIS
 * @brief Base de datos para El Plátano de Oro.
 * @version 0.1
 * @date 2021-05-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef USER_FUNCTIONS_H_
#define USER_FUNCTIONS_H_

#include <queue>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "./data_base.h"

constexpr int column_size = 6;

using table_t = std::array<std::string, column_size>;

void Search(const DataBase& data_base);
void Edit(DataBase& data_base);
void Edit(DataBase& data_base, Product& p);
void Buy(DataBase& data_base);
void Insert(DataBase& data_base);
void Search();            //< test;
void Edit();              //< test;
void Insert();            //< test;

void Print(std::queue<Product> data);
std::queue<table_t> ProductToTable(std::queue<Product> data);


#endif  // USER_FUNCTIONS_H_
