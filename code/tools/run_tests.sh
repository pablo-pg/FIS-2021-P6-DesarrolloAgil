#!/bin/bash

# Ejecuta todos aquellos test localizados en la carpeta correspondiente.

# Desplazarse hasta la carpeta de tests.
if cd ../test; then
  passed=0
  total=0
  # Crea una lista con todos los tests.
  for $test in $(ls test*) do;
    # Revisa si puede ejecutarse y en tal caso, si tiene éxito.
    if [ -x $test ] && ./$test; then
      passed=$((passed + 1))
    fi
    total=$((total + 1))
  done
  # Imprime el recuento de pruebas superadas con éxito.
  echo -e "\nTest superados correctamente: ${passed}/${total}"
fi
