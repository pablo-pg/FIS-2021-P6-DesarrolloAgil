#!/bin/bash

# Genera la documentación para los ficheros de código fuente C++,
# según lo establecido en un fichero de configuración Doxygen.

# Nombre del fichero de configuración.
FILENAME=".doxygen-config"

# Revisa si Doxygen está instalado en el sistema.
if [ "$(which doxygen)" != "" ]; then
  # Busca un fichero de configuración
  if [ "$(find . -maxdepth 1 -type f -name $FILENAME)" = "" ]; then
    echo "No se encuentra un fichero de configuracion"
    echo -n "Desea crear uno? (s/n) > "
    read generate

    # Pregunta al usuario sobre la creación de un fichero básico.
    if [ "$generate" = "s" ] || [ "$generate" = "S" ]; then
      doxygen -g $FILENAME 1>/dev/null
    else
      echo "Obligatorio: crea un fichero de configuracion"
      exit 1
    fi
  fi
  
  # Genera la documentación necesaria.
  if cd ../include; then
    doxygen ../tools/$FILENAME 1>/dev/null
    echo "Se ha generado la documentacion para el codigo fuente!!!"
  fi
else
  echo "Obligatorio: sudo apt install doxygen"
  exit 1
fi
