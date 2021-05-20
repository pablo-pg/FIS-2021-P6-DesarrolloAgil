#!/bin/bash

# Instala y activa el servicio de Git Hooks de forma local.

GIT_DIR=$(git rev-parse --git-dir)

echo "Instalando Git Hooks..."
# Crea un link simbólico en la carpeta local (normalmente ./git/hooks).
ln -s ./hooks/pre-commit $GIT_DIR/hooks/pre-commit
echo "Listo!!!"
