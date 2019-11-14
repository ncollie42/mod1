#ifndef MOD_H
#define MOD_H
#include "raylib.h"
//Color
# define _RED     "\x1b[31m"
# define _GREEN   "\x1b[32m"
# define _YELLOW  "\x1b[33m"
# define _BLUE    "\x1b[34m"
# define _MAGENTA "\x1b[35m"
# define _CYAN    "\x1b[36m"
# define _BLACK "\033[0;90m"
# define _RESET   "\x1b[0m"
#define POS(x, y, width) ((x) + (y) * (width)) 
//structs
typedef struct ParcedPoints {
    Vector3 points[50]; 
    int     maxX;
    int     maxY;
} ParcedPoints;

//parce files
Model getTerrain(char *file);


//parse File
ParcedPoints parceFile(char *file);

//interpolation
void interpolateMap(Image map, ParcedPoints points);

//debug functions
void printMapDebug(unsigned char *map, int width, int height);

#endif