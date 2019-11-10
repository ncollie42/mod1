#define POS(x, y, width) ((x) + (y) * (width)) 

// typedef struct Vector3 {
//     float x;
//     float y;
//     float z;
// } Vector3;

// typedef struct ParcedPoints {
//     Vector3 points[50]; 
//     int     maxX;
//     int     maxY;
// } ParcedPoints;

// unsigned char   *genMap(ParcedPoints givenpoints) {
//     unsigned char   *map;
//     int             x;
//     int             y;
//     int             min = 50;
//     int             i = 0;
//     int             j = 0;

//     x = givenpoints.maxX >= min ? givenpoints.maxX: min;
//     y = givenpoints.maxY >= min ? givenpoints.maxY: min;
//     map = (unsigned char *)malloc(sizeof(unsigned char) * x * y);
//     while (i < x * y)
//     {
//         map[i] = 0;
//         i++;
//     }
//     int i = 0;
//     while (i < 50)
//     {
//         printf("%d\n", POS(givenpoints.points[i].x, givenpoints.points[i].y, x);
//         map[POS(givenpoints.points[i].x, givenpoints.points[i].y, x)] = givenpoints.points[i].z;
//         i++;
//     }
//     return (map);
// }

int main()
{
    char arr[8];
    int aarr[] = {1, 2, 3};
    arr[POS(aarr[0], aarr[1], aarr[2])] = 65;
    printf("%d\n", arr[POS(1, 2, 3)]);
}