#!/bin/bash

# Genera la documentación para los ficheros de código fuente C++,
# según lo establecido en un fichero de configuración Doxygen.

# Nombre del fichero de configuración.
FILENAME=".doxygen-config"

# Revisa si Doxygen está instalado en el sistema.
if [ "$(which doxygen)" != "" ]; then
  # Busca un fichero de configuración
  if [ "$(find . -maxdepth 1 -type f -name $FILENAME)" = "" ]; then
    echo "No Doxygen configuration file was found"
    echo -n "Do you want to create one? (y/n) > "
    read generate

    # Pregunta al usuario sobre la creación de un fichero básico.
    if [ "$generate" = "y" ] || [ "$generate" = "Y" ]; then
      doxygen -g $FILENAME 1>/dev/null
    else
      echo "Mandatory: make a Doxygen configuration file to create documentation"
      exit 1
    fi
  fi
  
  # Genera la documentación necesaria.
  if cd ../include; then
    doxygen ../tools/$FILENAME 1>/dev/null
    echo "Documentation for the source code has been generated!!!"
  fi
else
  echo "Mandatory: sudo apt install doxygen"
  exit 1
fi
