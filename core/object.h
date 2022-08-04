//
// Created by Bennet Weingartz on 10.02.22.
//

#ifndef INDAGO_C_OBJECT_H
#define INDAGO_C_OBJECT_H

#include <GL/glew.h>
#include <cglm/cglm.h>

#include "../core/vertex.h"

typedef struct {
    mat4 positionMatrix, rotationMatrix, scaleMatrix;
    int vertexCount;
    GLuint vao;
    GLuint vbo[2]; // idx0: pos, idx1: col
    Vertex verts[];
} Object;

Object* InitObject(const Vertex*, int);

void CalcModel(Object*, mat4);

#endif //INDAGO_C_OBJECT_H