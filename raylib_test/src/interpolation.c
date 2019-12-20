#include "raylib.h"
#include "mod1.h"
#include <math.h>
#include <stdio.h>
#define BIGGER(x, y) ((x) > (y) ? x : y)
#define SMALLER(x, y) ((x) > (y) ? y : x)

double getHypotenuse(int x, int y, int radious) {
    int a = BIGGER(x, radious) - SMALLER(x, radious); 
    int b = BIGGER(y, radious) - SMALLER(y, radious);
    return (sqrt((a * a) + (b * b)));
}


//Diameter should be calculated in here based on height?
void DrawMountain(Vector3 centerPoint, Image map) {
    if (centerPoint.z == 0)
        return;
    unsigned char *pixel = map.data;
    int index;

    index = POS(centerPoint.x, centerPoint.y, map.width);
   

    int diameter = 70;
    double hypot;
    int radious = diameter /2;
    double unit = (PI/2)/radious;
    int val;
    //square around point
    // printf("hgiht: %f %f\n",deltaHight, cos(unit * hypot));
    for (int hh = diameter; hh >= 0; hh--) {
        for(int ww = diameter; ww >= 0; ww--) {
            hypot = getHypotenuse(ww, hh, radious);
            //if point is within radious - set color on pixel
            if (hypot < radious) {
                index = POS((centerPoint.x + ww), (centerPoint.y + hh), map.width);
                // Cos returns a % value to mult based on distance from hypot // div unit by some val? 
                 float deltaHight = centerPoint.z - pixel[index];
                //Color based on equation with fall off
                // val = centerPoint.z * cos(unit * hypot);
                // pixel[index] = val;
                // if (pixel[index] < val) = val;
                //closer to 0 hypot, the higher to 1 is result, (hypot = radious) == 0, 
                float tmp = deltaHight * cos(unit * hypot);
                if ((pixel[index] + tmp) >= 255) {
                    printf("Overflowing!! %f\n",pixel[index] + tmp);
                    tmp = 255;
                }
                pixel[index] += tmp;
                
                //TODO ^ fix +=? to smooth or cap out close mountains?
            }
        }
    }
}
                // if (pixel[index]){
                //     if ((pixel[index] + ((pixel[index] + val)/2) > 255))
                //         pixel[index] = 255;
                //     else
                //         pixel[index] += (pixel[index] + val)/2;
                // }
                // else
                //     pixel[index] = val;

void testAlgo(Image map) {
    int d = 20;
    double unit = (PI/2.0)/10;
    printf("%f\n", unit);
    double tmp = cos(unit);
    printf("%f\n", tmp);
}

void interpolateMap(Image map, ParcedPoints points) {
    // myDrawCircle(5, 5, 2, 200, map);
    for (int ii = 0; ii < 50; ii++) {
        DrawMountain(points.points[ii], map);
    }
    // myRect(5, 5, 30, map);
    ExportImage(map, "test.png");
}