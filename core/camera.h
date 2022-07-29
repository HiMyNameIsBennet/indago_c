//
// Created by Bennet Weingartz on 13.02.22.
//

#ifndef INDAGO_C_CAMERA_H
#define INDAGO_C_CAMERA_H

#include <cglm/cglm.h>

typedef struct{
    mat4 position;
    vec3 velocity;
} Camera;

extern mat4 viewMatrix;
void MoveCamera(Camera* camera);
Camera InitCamera(void);

#endif //INDAGO_C_CAMERA_H
