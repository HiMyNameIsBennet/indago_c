//
// Created by Bennet Weingartz on 04.08.22.
//

#include <string.h>

#include "object.h"
#include "vertex.h"

Object* InitObject(const Vertex* verts, int vertexCount){
    Object* object = malloc(sizeof(Object) + sizeof(Vertex) * vertexCount);

    glm_mat4_identity(object->positionMatrix);
    glm_mat4_identity(object->rotationMatrix);
    glm_mat4_identity(object->scaleMatrix);

    object->vertexCount = vertexCount;

    memcpy(object->verts, verts, sizeof(Vertex) * vertexCount);

    return object;
}

void CalcModel(Object* object, mat4 dest){
    mat4 modelMatrix;
    glm_mat4_mulN((mat4*[]) {&object->positionMatrix,
                                    &object->rotationMatrix,
                                    &object->scaleMatrix}, 3, dest);
}