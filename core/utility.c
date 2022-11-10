//
// Created by Bennet Weingartz on 08.02.22.
//

#define _USE_MATH_DEFINES


#include <math.h>

#include "utility.h"

float Cot(float rad){
    return (float)(1.0 / tan(rad));
}

float DegToRad(float deg){
    return deg * (float)(M_PI / 180);
}

float RadToDeg(float rad){
    return rad * (float)(180 / M_PI);
}