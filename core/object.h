//
// Created by Bennet Weingartz on 10.02.22.
//

#ifndef INDAGO_C_OBJECT_H
#define INDAGO_C_OBJECT_H

#include <cglm/cglm.h>

#include "../core/vertex.h"

typedef struct {
    mat4 modelMatrix;
    int vertexCount;
    Vertex verts[];
} Object;

#endif //INDAGO_C_INPUT_H