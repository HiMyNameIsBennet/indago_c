//
// Created by Bennet Weingartz on 13.02.22.
//

#include <GL/glew.h>

#include "camera.h"
#include "timer.h"
#include "../init/uniforms.h"

mat4 viewMatrix;

void MoveCamera(Camera* camera){
    vec3 cameraDelta;
    glm_vec3_scale(camera->velocity, frameTime, cameraDelta);
    glm_translate(camera->position, cameraDelta);
    glm_mat4_copy(camera->position, viewMatrix);
    glUniformMatrix4fv(viewMatrixUniformLocation, 1, GL_FALSE, (float*) camera->position);
}

Camera InitCamera(void){
    Camera camera;

    glm_mat4_identity(camera.position);
    glm_vec3_zero(camera.velocity);

    float initVec[] = {.0f, .0f, -2.0f};
    glm_translate(camera.position, initVec);
    glm_mat4_copy(camera.position, viewMatrix);

    return camera;
}