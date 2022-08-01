//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include "buffers.h"
#include "../core/vertex.h"
#include "../core/object.h"

GLuint vaoID, vboID;

void InitVBO(Object* obj){
    GLenum errorValue = glGetError();

    glGenVertexArrays(1, &obj->vao); //Vertex Array Object
    glBindVertexArray(obj->vao);

    glGenBuffers(2, obj->vbo); //Vertex Buffer Object

    const size_t vtxSize = sizeof(obj->verts[0].pos);

    RefreshVBO(obj);

    glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[0]); // pos
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[1]); // col
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);

    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("BUFFERS OK\n");
    }
    else {
        exit(-1);
    }
}

void RefreshVBO(Object* obj){
    const size_t bufSize = sizeof(float[4]) * obj->vertexCount;

    float pos[obj->vertexCount][4], col[obj->vertexCount][4];

    for(int i = 0; i < obj->vertexCount; i++)
        for(int j = 0; j < 4; j++) {
            pos[i][j] = obj->verts[i].pos[j];
            col[i][j] = obj->verts[i].col[j];
        }

    glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, (GLsizei) bufSize, pos, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, obj->vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, (GLsizei) bufSize, col, GL_STATIC_DRAW);
}

void DestroyVBO(Object* obj) {
    GLenum errorValue = glGetError();

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glDeleteBuffers(2, obj->vbo);

    glDeleteVertexArrays(1, &obj->vao);

    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("BUFFERS DESTROYED\n");
    }
    else {
        exit(-1);
    }
}