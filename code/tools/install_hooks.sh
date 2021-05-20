#!/bin/bash

# Instala y activa el servicio de Git Hooks de forma local.

GIT_DIR=$(git rev-parse --git-dir)
CUR_DIR="$(pwd)"

echo "Instalando Git Hooks..."
# Crea un link simbólico en la carpeta local (normalmente ./git/hooks).
ln -sf ${CUR_DIR}/hooks/pre-commit $GIT_DIR/hooks/pre-commit
echo "Listo!!!"
