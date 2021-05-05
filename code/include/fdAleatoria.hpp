////////////////////////////////////////////////////////////////////////////////
// Copyright 2021
// Universidad de La Laguna
// Escuela superior de Ingeniería y Tecnología
// Grado en igeniería Informática
// Computablidad y Algoritmia
// Autor: Ana Virginia Giambona Díaz
// Correo: alu0101322650@ull.edu.es
// Fecha: 07/04/2021
// Práctica: Tabla Hash
// 
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <stdlib.h>

#include "funcionDispersion.hpp"

template<class Clave>
class fdAleatoria : public FuncionDispersion<Clave> {
  public:
  fdAleatoria(){}
  ~fdAleatoria(){}

  fdAleatoria(const unsigned n): nDatos(n){}
  
  unsigned operator()(const Clave& k) const {
    srand(k); // inicio num ale
    return (rand() % nDatos);
  }
 private:
  unsigned nDatos;
};

