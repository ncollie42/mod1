#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846f

void testAlgo(void) {
    int d = 20;
    double unit = (PI/2.0)/10;
    printf("%f\n", unit);
    double tmp = cos(unit);
    printf("%f\n", tmp);
    tmp = (cos(unit * 10));
    printf("%f\n", tmp);
    tmp = (cos(unit * 5));
    printf("%f\n", tmp);
}

int main (int argc, char **argv) {
    testAlgo();
}