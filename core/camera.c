//
// Created by Bennet Weingartz on 13.02.22.
//

#include <GL/glew.h>

#include "camera.h"
#include "../init/uniforms.h"

mat4 viewMatrix;

void MoveCamera(Camera* camera, vec3 vector){
    glm_translate(camera->position, vector);
    glm_mat4_copy(camera->position, viewMatrix);
    glUniformMatrix4fv(viewMatrixUniformLocation, 1, GL_FALSE, (float*) camera->position);
}

Camera InitCamera(void){
    Camera camera;

    glm_mat4_identity(camera.position);
    float initVec[] = {.0f, .0f, -2.0f};
    MoveCamera(&camera, initVec);

    return camera;
}