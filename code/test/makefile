#
# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Fundamentos de Ingeniería del Software 2020/21
#
# Autor: Equipo M5 FIS
# Fecha: Abril de 2021
# 
# Makefile para los tests el proyecto de FIS en grupo.
#

CXX := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -O0

DEPS = ../include/
SRC = $(find ../src/ -maxdepth 1 -type f -name *.cc -name *.inl -not -name main*)
LIBS =

all: tests

tests:
	for test in $(ls *.cc); do \
	$(CXX) -o $$test $(SRC); \
	done

clean:
	rm -f *.o $(OBJ) ../src/*.o

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)
	
clear: clean
