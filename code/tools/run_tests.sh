#!/bin/bash

# Ejecuta todos aquellos test localizados en la carpeta correspondiente.

# Desplazarse hasta la carpeta de tests.
if cd ../test; then
  passed=0
  total=0
  # Crea una lista con todos los tests.
  for test in $(ls test*); do
    # Revisa si puede ejecutarse y en tal caso, si tiene éxito.
    if [ -x $test ]; then
      ./$test && passed=$((passed + 1))
      total=$((total + 1))
    fi
  done
  # Imprime el recuento de pruebas superadas con éxito.
  echo -e "\nPruebas superadas correctamente: ${passed}/${total}"
  if [ "$passed" -lt "$total" ]; then
    exit 1
  fi
fi
