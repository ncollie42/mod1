#include "raylib.h"
#include "mod1.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define POINT_LIMIT 50

// typedef struct Error {
//     bool    err;
//     char    *msg;
// } Error;

// bool checkError(Error err) {
//     if (err.err) {
//         printf("%s\n", err.msg);
//         free(err.msg);
//     }
//     return err.err;
// }

Image genBaseMap(ParcedPoints givenpoints) {
   Image baseMap;
    unsigned char   *map;
    int             x;
    int             y;
    int             min = 50;
    int             i = 0;

    // ToDo: Extra padding for x and y for max points
    // do we need the padding for min size too?
    x = givenpoints.maxX >= min ? givenpoints.maxX: min;
    y = givenpoints.maxY >= min ? givenpoints.maxY: min;
    map = (unsigned char *)malloc(sizeof(unsigned char) * x * y);
    memset(map, 0, x * y);
    while (i < 50)
    {
        int temp = POS(givenpoints.points[i].x, givenpoints.points[i].y, x);
        map[temp] = givenpoints.points[i].z;
        i++;
    }
    baseMap.height = y;
    baseMap.width = x;  //TODO: use height and width to begin with?
    baseMap.data = map;
    baseMap.mipmaps = 1;
    baseMap.format = UNCOMPRESSED_GRAYSCALE;
    return (baseMap);
}

Model getTerrain(char *file)
{
    ParcedPoints points = parceFile(file);
    Image map = genBaseMap(points);
    // interpolateMap(map);

    // printf("%p %d %d %d %d\n", map.data, map.height, map.width, map.mipmaps, map.format);
    Texture2D texture = LoadTextureFromImage(map);
    Mesh mesh = GenMeshHeightmap(map, (Vector3){16,8,16});
    Model model = LoadModelFromMesh(mesh);
    model.materials[0].maps[MAP_DIFFUSE].texture = texture;
    //TODO: get points (list? array?)
    //Read file: 
    //set points
    //run interpolation
    //return terrain 
    // printMapDebug(map.data, map.width, map.height);
    return model;
    // return (Model){};
}