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

CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -O0

OBJECTS = test_login test_user_file test_data_base

INCLUDE	:= ../include

LIBRARIES	:=
EXECUTABLE	:=



# all: $(OBJECTS)

# test_login: test_login.cc ../include/login.h
# 	$(CXX) $(CXX_FLAGS) -I$(INCLUDE)/ $^ -o $@ $(LIBRARIES)


# # all: $(OBJECTS)
# all:test_login test_user_file test_data_base

# test_login: test_login.cc
# 	$(CXX) $(CXX_FLAGS) -I$(INCLUDE)/ $^ -o $@

# test_user_file:test_user_file.o
# 	$(CXX) $(CXX_FLAGS) -I$(INCLUDE)/ $^ -o $@


# test_data_base:test_data_base.o
# 	$(CXX) $(CXX_FLAGS) -I$(INCLUDE)/ $^ -o $@


# # $(objects): %.o: %.cc:
# # 	$(CXX) $(CXX_FLAGS) -I$(INCLUDE)/ $^ -o $@ $(LIBRARIES)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

clean:
	-rm $(OBJECTS)

	
clear: clean
