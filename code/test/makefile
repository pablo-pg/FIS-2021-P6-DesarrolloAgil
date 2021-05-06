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

DEPS = ../data_base.h ../hash.h ../login.h ../menu.h ../product.h
LIBS =
OBJ = test_login test_user_file test_data_base

all: test_login test_data_base

%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXX_FLAGS)


test_login: test_login.o
	$(CXX) $(CXX_FLAGS) -o $@ $^ $(LIBS)

test_data_base: test_data_base.o
	$(CXX) $(CXX_FLAGS) -o $@ $^ $(LIBS)

# test_user_file: test_user_file.o
# 	$(CXX) $(CXX_FLAGS) -o $@ $^ $(LIBS)





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

clean:
	rm -f *.o $(OBJ)


run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)


	
clear: clean
