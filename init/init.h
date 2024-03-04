//
// Created by Bennet Weingartz on 29.10.21.
//

#ifndef INDAGO_C_INIT_H
#define INDAGO_C_INIT_H

#include "../core/camera.h"

extern int DIMENSION_MODE;
extern mat4 projectionMatrix;
extern Camera camera;

void Init(const int argc, const char** argv);

#endif //INDAGO_C_INIT_H
