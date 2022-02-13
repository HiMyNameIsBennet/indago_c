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

    const size_t bufSize = sizeof(Vertex) * obj->vertexCount;
    const size_t vtxSize = sizeof(obj->verts[0]);
    const size_t rgbOffset = sizeof(obj->verts[0].pos);

    glGenVertexArrays(1, &vaoID); //Vertex Array Object
    glBindVertexArray(vaoID);

    glGenBuffers(1, &vboID); //Vertex Buffer Object
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, (GLsizei) bufSize, obj->verts, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, (GLsizei) vtxSize, 0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, (GLsizei) vtxSize, (GLvoid*) rgbOffset);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("BUFFERS OK\n");
    }
    else {
        exit(-1);
    }
}

void DestroyVBO(void) {
    GLenum errorValue = glGetError();

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glDeleteBuffers(1, &vboID);

    glDeleteVertexArrays(1, &vaoID);

    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("BUFFERS DESTROYED\n");
    }
    else {
        exit(-1);
    }
}