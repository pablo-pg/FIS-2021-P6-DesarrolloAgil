#!/bin/bash

# Aplica formato a todos los ficheros de código fuente C++,
# según lo establecido en un archivo de configuración.

# Guía de estilos predeterminada para archivos de configuración,
STYLE=google

# Revisa si clang-format está instalado en el sistema.
if [ "$(which clang-format)" != "" ]; then
  # Busca un fichero de configuración.
  if [ "$(find . -maxdepth 1 -type f -name ".clang-format")" = "" ]; then
    echo "No se encuentra un fichero de configuracion"
    echo -n "Desea crear uno (estilo=${STYLE})? (s/n) > "
    read generate

    # Pregunta al usuario sobre la creación de un fichero básico.
    if [ "$generate" = "s" ] || [ "$generate" = "S" ]; then
      clang-format -style=$STYLE -dump-config > .clang-format
    else
      echo "Obligatorio: crea un fichero de configuracion"
      exit 1
    fi
  fi
  
  # Aplica formato sobre los ficheros .h en la carpeta include.
  if clang-format -i -style=file ../include/*.h; then
    echo "Include: se ha formateado el codigo!!!"
  fi
  
  # Aplica formato sobre los ficheros .cc en la carpeta src.
  if clang-format -i -style=file ../src/*.cc; then
    echo "Src: se ha formateado el codigo!!!"
  fi

else
  echo "Obligatorio: sudo apt install clang-format"
  exit 1
fi
