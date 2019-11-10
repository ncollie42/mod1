FRAMEWORK = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
FILES = main.c \
terrain.c
LIB = ../raylib/libraylib.a -I ../raylib/
CC = gcc
EXTRA = -Wall -Werror -Wextra
all: 
	$(CC) $(FRAMEWORK) $(FILES) $(LIB)