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
    int diameter = 70;
    double hypot;
    int radious = diameter /2;
    int index;
    unsigned char *pixel = map.data;
    double unit = (PI/2)/radious;
    int val;
    //square around point
    for (int hh = diameter; hh >= 0; hh--) {
        for(int ww = diameter; ww >= 0; ww--) {
            hypot = getHypotenuse(ww, hh, radious);
            //if point is within radious - set color on pixel
            if (hypot < radious) {
                index = POS((centerPoint.x + ww), (centerPoint.y + hh), map.width);
                // Cos returns a % value to mult based on distance from hypot // div unit by some val? 
                val = centerPoint.z * cos(unit * hypot);
                if (pixel[index] < val) = val;
                
                    pixel[index] = val;
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