#!/bin/bash

# Aplica formato a todos los ficheros de código fuente C++,
# según lo establecido en un archivo de configuración.

# Guía de estilos predeterminada para archivos de configuración,
STYLE=google

# Revisa si clang-format está instalado en el sistema.
if [ "$(which clang-format)" != "" ]; then
  # Busca un fichero de configuración.
  if [ "$(find . -maxdepth 1 -type f -name ".clang-format")" = "" ]; then
    echo "No format style file was found"
    echo -n "Do you want to create one (style=${STYLE})? (y/n) > "
    read generate

    # Pregunta al usuario sobre la creación de un fichero básico.
    if [ "$generate" = "y" ] || [ "$generate" = "Y" ]; then
      clang-format -style=$STYLE -dump-config > .clang-format
    else
      echo "Mandatory: create a format style file to allow formatting"
      exit 1
    fi
  fi
  
  # Aplica formato sobre los ficheros .h en la carpeta include.
  if clang-format -i -style=file ../include/*.h; then
    echo "Include: source code is now formatted!!!"
  fi
  
  # Aplica formato sobre los ficheros .cc en la carpeta src.
  if clang-format -i -style=file ../src/*.cc; then
    echo "Src: source code is now formatted!!!"
  fi

else
  echo "Mandatory: sudo apt install clang-format"
  exit 1
fi
