HPP_PATH = "../hpp_file/"
LIB_PATH = "../lib/"
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o , $(SRC))
DEPS:=$(patsubst %.cpp,%.dep, $(SRC))
Lib = -lmatrix
all:Gauss_Seidel.out Jakobi.out

Gauss_Seidel.out:main_gauss_seidel.o 
	@echo Linking
	@g++ main_gauss_seidel.o $(Lib)  -L./$(LIB_PATH) -I./$(HPP_PATH) -o Gauss_Seidel.out 

Jakobi.out:main_jakobi.o $(lib)
	@echo Linking
	@g++ main_jakobi.o $(Lib) -L./$(LIB_PATH) -I./$(HPP_PATH) -o Jakobi.out

%.o:%.cpp
	@echo CPP TO OBJ
	@g++ $<  -I./$(HPP_PATH) -c -o $@

%.dep:%.cpp
	@echo CPP TO DEP
	@gcc -MM $< -MT "$@ $(basename $@).o" -I./$(HPP_PATH) -o $@
clean:
	@echo remuving
	@rm -f *.o *.out *.dep 

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPS)
endif
                       
