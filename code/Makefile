#
# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Fundamentos de Ingeniería del Software 2020/21
#
# Autor: Equipo M5 FIS
# Fecha: Abril de 2021
# 
# Makefile para la el proyecto de FIS en grupo.
#

CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include

LIBRARIES	:=
EXECUTABLE	:= el_platano_de_oro


all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

clean:
	-rm $(BIN)/$(EXECUTABLE)
	-rm $(SRC)/main
	

clear: clean
