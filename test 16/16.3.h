#ifndef DEG_TO_RED
#define DEG_TO_RED ((4*atan(1))/180)
#include <stdio.h>
#include <math.h>
typedef struct polar_v {
    double magnitude;
    double angle;
}polar;

typedef struct rect_v {
    double x;
    double y;
}rect;

rect polar_to_rect(polar pv);//极坐标转换为直角坐标
#endif //
