HPP_PATH = "../hpp_file/"
LIB_PATH = "../lib/"
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o , $(SRC))
DEPS:=$(patsubst %.cpp,%.dep, $(SRC))
OUT = $(patsubst %.cpp,%.out, $(SRC))
Lib = -lmatrix
all:$(OUT)

%.out:%.o 
	@echo Linking
	@g++ $< $(Lib) -L./$(LIB_PATH) -I./$(HPP_PATH) -o $@
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
                       
