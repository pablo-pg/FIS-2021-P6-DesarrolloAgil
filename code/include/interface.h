/**
 * @file interface.h
 * @author Equipo m5 FIS
 * @brief Interfaz de la aplicación
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CODE_INCLUDE_INTERFACE_H_
#define CODE_INCLUDE_INTERFACE_H_


#include "../include/data_base.h"

enum Mode {client, seller};

void start();
bool login();
int menu();


#endif  // CODE_INCLUDE_INTERFACE_H_
