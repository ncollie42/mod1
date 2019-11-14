FRAMEWORK = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
FILES = main.c \
terrain.c \
parseInput.c \
interpolation.c \
debug.c 
LIB = ../raylib/libraylib.a -I ../raylib/
CC = gcc
EXTRA = -Wall -Werror -Wextra
DEBUG = -g 
DEBUG2 = -fsanitize=address 

all: 
	$(CC) $(FRAMEWORK) $(FILES) $(LIB) $(DEBUG)