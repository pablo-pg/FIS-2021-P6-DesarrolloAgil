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

DEPS = ../include/data_base.h ../include/hash.h ../include/login.h ../include/menu.h ../include/product.h
SRC= ../src
LIBS =
OBJ = test_login test_user_file test_data_base

all: tests test_login test_data_base

%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXX_FLAGS)


# fonts:
#   cd ../src 
# %.o: %.cc $(DEPS)
# 	$(CXX) -c -o $@ $< $(CXX_FLAGS)
# 	cd ../tests

%../src/.o: %../src/.cc
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
	rm -f *.o $(OBJ) ../src/*.o


run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)


	
clear: clean
