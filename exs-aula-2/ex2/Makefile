#OBJS specifies which files to compile as part of the project
OBJS =  main.c ../../fila/fila.c


#CC specifies which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
COMPILER_FLAGS = -Wall -Wextra -Wsign-conversion -pedantic -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wredundant-decls -Wshadow  -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option


#OBJ_NAME specifies the name of our executable
OBJ_NAME = ex2

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS)  $(COMPILER_FLAGS)  -o $(OBJ_NAME)
