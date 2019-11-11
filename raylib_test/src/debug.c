#include <stdio.h>
void printMapDebug(unsigned char *map, int width, int height) {
    int ii = 0;
    while(height-- >= 0) {
        int tmp = 0;
        while(tmp++ < width) {
            printf("%d\t", map[ii++]);
        }
        printf("\n");
    }
}