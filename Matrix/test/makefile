HPP_PATH = "../hpp_file/"
LIB_PATH = "../lib/"
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o , $(SRC))
DEPS:=$(patsubst %.cpp,%.dep, $(SRC))
Lib = -lmatrix
all:Gauss_Seidel_Test.out Jakobi_Test.out

Gauss_Seidel_Test.out:gauss_seidel_test.o 
	@echo Linking
	@g++ gauss_seidel_test.o $(Lib)  -L./$(LIB_PATH) -I./$(HPP_PATH) -o Gauss_Seidel_Test.out 

Jakobi_Test.out:jakobi_test.o $(lib)
	@echo Linking
	@g++ jakobi_test.o $(Lib) -L./$(LIB_PATH) -I./$(HPP_PATH) -o Jakobi_Test.out

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
                       
