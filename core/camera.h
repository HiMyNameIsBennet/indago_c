//
// Created by Bennet Weingartz on 13.02.22.
//

#ifndef INDAGO_C_CAMERA_H
#define INDAGO_C_CAMERA_H

#include <cglm/cglm.h>

typedef struct{
    mat4 position;
} Camera;

void MoveCamera(Camera* camera, vec3 vector);
Camera InitCamera(void);

#endif //INDAGO_C_CAMERA_H
