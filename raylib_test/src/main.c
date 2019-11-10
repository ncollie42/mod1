#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define POS(x, y, width) ((x) + (y) * (width)) 

unsigned char data[] = {
 0,0,0,0,0,0,0,0,0,0
,0,65,65,65,65,65,65,65,65,0
,0,65,70,70,70,70,70,70,65,0
,0,65,70,80,80,80,80,70,65,0
,0,65,70,180,200,180,80,70,65,0
,0,65,70,80,80,80,80,70,65,0
,0,65,70,80,80,80,80,70,65,0
,0,65,70,70,70,70,70,70,65,0
,0,65,65,65,65,65,65,65,65,0
,0,0,0,0,0,0,0,0,0,0
};


Camera init()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Mod1 - Terrain & water");

    Camera camera = {
        .position = {18.0f, 16.0f, 18.0f},
        .target = {0.0f, 0.0f, 0.0f},
        .up = {0.0f, 1.0f, 0.0f},
        .fovy = 45.0f,
        .type = 0};
    SetCameraMode(camera, CAMERA_ORBITAL);
    // SetCameraMoveControls(119, 115, 
    //                            100, 97, 
    //                            32, 118);  
    SetTargetFPS(60);
    return camera;
}

Image makeCustomImage() {
    Image image = {0};
    image.width = 10;
    image.height = 10;
    image.mipmaps = 1;
    image.format = UNCOMPRESSED_GRAYSCALE;
    image.data = calloc(100, sizeof(char));
    memmove(image.data, data, sizeof(char) * 100); // 100 - hard codded width * height 
    return image;
}

Model genMymodel() {
    Image image = makeCustomImage();
    Texture2D texture = LoadTextureFromImage(image);
    Mesh mesh = GenMeshHeightmap(image, (Vector3){16,8,16});
    Model model = LoadModelFromMesh(mesh);
    model.materials[0].maps[MAP_DIFFUSE].texture = texture;
    // TODO: unload stuLff
    return model;
}

int main(void)
{
    Camera camera = init();
    //TODO: read input, get file
    //Model tmp = getTerrain();
    Model tmp = genMymodel();
    int v;
    while (!WindowShouldClose())
    {
        if ((v = GetKeyPressed()) != -1)
            printf("%d\n", v); 
        UpdateCamera(&camera);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            // TODO: update water
            BeginMode3D(camera);
            DrawModel(tmp, (Vector3){0}, 1.0f, RED);
            DrawGrid(20, 1.0f);
            // TODO: Draw water
            // TODO: Gui??
            EndMode3D();
            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();
}
