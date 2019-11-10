#include "raylib.h"
#include "mod1.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define POINT_LIMIT 50
typedef struct Error {
    bool    err;
    char    *msg;
} Error;

bool checkError(Error err) {
    if (err.err) {
        printf("%s\n", err.msg);
        free(err.msg);
    }
    return err.err;
}

typedef struct ParcedPoints {
    Vector3 points[50]; 
    int     maxX;
    int     maxY;
} ParcedPoints;

//Validate points -> X:23 Y:89 Z:4242
bool checkValid(char *section, char Axis) {
    if (section[0] != Axis)
        return false;
    if (section[1] != ':')
        return false;
    if (isdigit(section[2]) == 0)
        return false;
    return true;
}

void exitParceFailure(int lineNum, char axis) {
    printf("%sERROR%s: Parcing .mod1 file. Line: %d Trying to get: %c\n", _RED, _RESET, lineNum, axis);
    exit(EXIT_FAILURE);
}
//line -> Vector3
Vector3 lineToPoint(char *line) {
    static int lineCount;
    Vector3 ret = {.x = 0, .y = 0, .z = 0};
    char *current;

    current = strtok(line, " ");
    lineCount++;    
    if (!checkValid(current, 'X'))
        exitParceFailure(lineCount, 'X');
    ret.x = atoi(&current[2]);
    current = strtok(NULL, " ");
    if (!checkValid(current, 'Y'))
        exitParceFailure(lineCount, 'Y'); 
    ret.y = atoi(&current[2]);
    current = strtok(NULL, " ");
    if (!checkValid(current, 'Z'))
        exitParceFailure(lineCount, 'Z'); 
    ret.z = atoi(&current[2]);
    return ret;
}

//File -> points[50]
ParcedPoints parceFile(char *file) {
    FILE *f = fopen(file, "r");
    char *line = NULL;
    size_t linecap = 0;
    ssize_t read;
    ParcedPoints ret = {{}, 0, 0};
    int ii = 0;
    while ((read = getline(&line, &linecap, f)) > 0 ) {
        ret.points[ii++] = lineToPoint(line);
        if (ii == POINT_LIMIT) {
            printf("%sERROR%s: Point limit is %d\n", _RED, _RESET, POINT_LIMIT);
            exit(EXIT_FAILURE);
        }
        //TODO CHECK MAX Y and X
        //TODO RETURN
    }
    fclose(f);
    
    return ret;
}

Model getTerrain(char *file)
{
    ParcedPoints points = parceFile(file);
    //Image map = genBaseMap(points)
    //TODO: get points (list? array?)
    //Read file: 
    //set points
    //run interpolation
    //return terrain
    return (Model){};
}