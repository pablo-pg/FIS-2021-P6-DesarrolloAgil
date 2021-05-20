#!/bin/bash

# Instala y activa el servicio de Git Hooks de forma local.

<<<<<<< HEAD
GIT_DIR="$(git rev-parse --git-dir)"
=======
GIT_DIR=$(git rev-parse --git-dir)
>>>>>>> 2d757bdbfff1641a5ae778106d088bc8f7519b06
CUR_DIR="$(pwd)"

echo "Instalando Git Hooks..."
# Crea un link simbólico en la carpeta local (normalmente ./git/hooks).
ln -sf ${CUR_DIR}/hooks/pre-commit $GIT_DIR/hooks/pre-commit
echo "Listo!!!"
