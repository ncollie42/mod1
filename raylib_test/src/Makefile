FRAMEWORK = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
FILES = main.c \
terrain.c \
parseInput.c \
debug.c 
LIB = ../raylib/libraylib.a -I ../raylib/
CC = gcc
EXTRA = -Wall -Werror -Wextra
DEBUG = -g -fsanitize=address
all: 
	$(CC) $(FRAMEWORK) $(FILES) $(LIB) $(DEBUG)