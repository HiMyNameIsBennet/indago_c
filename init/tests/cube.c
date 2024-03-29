//
// Created by Bennet Weingartz on 13.02.22.
//

#include <GL/glew.h>
#include <cglm/cglm.h>

#include "cube.h"
#include "../uniforms.h"
#include "../window.h"
#include "../buffers.h"
#include "../init.h"
#include "../../core/object.h"

Object* cube = NULL;

Object** InitCube(void){
    const Vertex verts[36] = {
        {{-0.5, -0.5, 0.5, 1.0}, {0.0, 0.0, 1.0, 1.0}},
        {{0.5, 0.5, 0.5, 1.0}, {0.0, 1.0, 0.0, 1.0}},
        {{-0.5, 0.5, 0.5, 1.0}, {1.0, 0.0, 0.0, 1.0}},
        {{-0.5, -0.5, 0.5, 1.0}, {0.0, 0.0, 1.0, 1.0}},
        {{0.5, -0.5, 0.5, 1.0}, {1.0, 1.0, 0.0, 1.0}},
        {{0.5, 0.5, 0.5, 1.0}, {0.0, 1.0, 0.0, 1.0}},
        {{-0.5, -0.5, -0.5, 1.0}, {1.0, 1.0, 1.0, 1.0}},
        {{0.5, -0.5, 0.5, 1.0}, {1.0, 1.0, 0.0, 1.0}},
        {{-0.5, -0.5, 0.5, 1.0}, {0.0, 0.0, 1.0, 1.0}},
        {{-0.5, -0.5, -0.5, 1.0}, {1.0, 1.0, 1.0, 1.0}},
        {{0.5, -0.5, -0.5, 1.0}, {0.0, 0.0, 1.0, 1.0}},
        {{0.5, -0.5, 0.5, 1.0}, {1.0, 1.0, 0.0, 1.0}},
        {{-0.5, -0.5, -0.5, 1.0}, {1.0, 1.0, 1.0, 1.0}},
        {{-0.5, 0.5, 0.5, 1.0}, {1.0, 0.0, 0.0, 1.0}},
        {{-0.5, 0.5, -0.5, 1.0}, {1.0, 0.0, 0.0, 1.0}},
        {{-0.5, -0.5, -0.5, 1.0}, {1.0, 1.0, 1.0, 1.0}},
        {{-0.5, -0.5, 0.5, 1.0}, {0.0, 0.0, 1.0, 1.0}},
        {{-0.5, 0.5, 0.5, 1.0}, {1.0, 0.0, 0.0, 1.0}},
        {{0.5, -0.5, 0.5, 1.0}, {1.0, 1.0, 0.0, 1.0}},
        {{0.5, 0.5, -0.5, 1.0}, {1.0, 0.0, 1.0, 1.0}},
        {{0.5, 0.5, 0.5, 1.0}, {0.0, 1.0, 0.0, 1.0}},
        {{0.5, -0.5, 0.5, 1.0}, {1.0, 1.0, 0.0, 1.0}},
        {{0.5, -0.5, -0.5, 1.0}, {0.0, 0.0, 1.0, 1.0}},
        {{0.5, 0.5, -0.5, 1.0}, {1.0, 0.0, 1.0, 1.0}},
        {{-0.5, 0.5, 0.5, 1.0}, {1.0, 0.0, 0.0, 1.0}},
        {{0.5, 0.5, -0.5, 1.0}, {1.0, 0.0, 1.0, 1.0}},
        {{-0.5, 0.5, -0.5, 1.0}, {1.0, 0.0, 0.0, 1.0}},
        {{-0.5, 0.5, 0.5, 1.0}, {1.0, 0.0, 0.0, 1.0}},
        {{0.5, 0.5, 0.5, 1.0}, {0.0, 1.0, 0.0, 1.0}},
        {{0.5, 0.5, -0.5, 1.0}, {1.0, 0.0, 1.0, 1.0}},
        {{0.5, -0.5, -0.5, 1.0}, {0.0, 0.0, 1.0, 1.0}},
        {{-0.5, 0.5, -0.5, 1.0}, {1.0, 0.0, 0.0, 1.0}},
        {{0.5, 0.5, -0.5, 1.0}, {1.0, 0.0, 1.0, 1.0}},
        {{0.5, -0.5, -0.5, 1.0}, {0.0, 0.0, 1.0, 1.0}},
        {{-0.5, -0.5, -0.5, 1.0}, {1.0, 1.0, 1.0, 1.0}},
        {{-0.5, 0.5, -0.5, 1.0}, {1.0, 0.0, 0.0, 1.0}}
    };

    cube = InitObject(verts, (sizeof(verts) / sizeof(Vertex)));

    mat4 modelMatrix;
    CalcModel(cube, modelMatrix);

    glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) modelMatrix);

    printf("CUBE OK\n");

    return &cube;
}

void DestroyCube(void){
    free(cube);
    printf("CUBE DESTROYED\n");
}

void DrawCube(void){
    mat4 modelMatrix;
    glm_rotate_x(cube->rotationMatrix, .001f, cube->rotationMatrix);
    glm_rotate_y(cube->rotationMatrix, .001f, cube->rotationMatrix);
    CalcModel(cube, modelMatrix);
    glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) modelMatrix);
    glDrawArrays(GL_TRIANGLES, 0, cube->vertexCount);
}