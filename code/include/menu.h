/**
 * @file menu.h
 * @author Equipo m5 FIS
 * @brief Interfaz de la aplicación
 * @version 0.1
 * @date 2021-04-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef MENU_H_
#define MENU_H_

#include "../include/login.h"
#include "../include/user_functions.h"

/**
 * @brief Método que inicializa el programa.
 */
void start();

/**
 * @brief Control de acceso según los permisos del usuario.
 * @param user es el usuario que inicia sesión.
 * @return int es el código de retorno
 */
int EntryMode(Users& user, DataBase& data_base);

/**
 * @brief Menú para usuarios que tienen activos r
 *
 * @param user es el usuario que inicia sesión.
 * @return int es el código de retorno
 */
int BuyerMenu(Users& user, DataBase& data_base);

/**
 * @brief Menú para usuarios que tienen activos rw
 *
 * @param user es el usuario que inicia sesión.
 * @return int es el código de retorno
 */
int SellerMenu(Users& user, DataBase& data_base);

/**
 * @brief Menú para usuarios que tienen activos rc
 *
 * @param user es el usuario que inicia sesión.
 * @return int es el código de retorno
 */
int AdminReadMenu(Users& user, DataBase& data_base);

/**
 * @brief Menú para usuarios que tienen activos rwc
 *
 * @param user es el usuario que inicia sesión.
 * @return int es el código de retorno
 */
int AdminWriteMenu(Users& user, DataBase& data_base);

#endif  // MENU_H_
