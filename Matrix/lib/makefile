HPP_PATH = "../hpp_file/"
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o , $(SRC))
DEPS:=$(patsubst %.cpp,%.dep, $(SRC))
DEPS_PATH="./dep_file/"

all:libmatrix.so

libmatrix.so:$(OBJ)
	@echo Linking
	@g++ $^ -I./$(HPP_PATH)  -shared -o $@ 
%.o:%.cpp
	@echo CPP TO OBJ
	@g++ $< -fPIC -I./$(HPP_PATH) -c -o $@

%.dep:%.cpp
	@echo CPP TO DEP
	@gcc -MM $< -MT "$@ $(basename $@).o" -I./$(HPP_PATH) -o $(DEPS_PATH)$@
clean:
	@echo remuving
	@rm -f *.o run.exe *.dep 

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPS_PATH)$(DEPS)
endif
                       
