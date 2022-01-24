//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

#include "buffers.h"

GLuint vaoID, vboID, cboID;

void InitVBO(void){
    GLenum errorValue = glGetError();
    GLfloat vtxArray[] = {
        0.3f, 0.7f, 0.0f, 1.0f,
        0.7f, 0.7f, 0.0f, 1.0f,
        0.5f, 0.3f, 0.0f, 1.0f,
        -0.8f, -0.8f, 0.0f, 1.0f,
        0.0f,  0.8f, 0.0f, 1.0f,
        0.8f, -0.8f, 0.0f, 1.0f,
    };

    GLfloat colArray[] = {
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f
    };

    glGenVertexArrays(1, &vaoID); //Vertex Array Object
    glBindVertexArray(vaoID);

    glGenBuffers(1, &vboID); //Vertex Buffer Object
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vtxArray), vtxArray, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &cboID); //Color Buffer Object
    glBindBuffer(GL_ARRAY_BUFFER, cboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colArray), colArray, GL_STATIC_DRAW);
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

void DestroyVBO(void) {
    GLenum errorValue = glGetError();

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &cboID);
    glDeleteBuffers(1, &vboID);

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vaoID);

    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("BUFFERS DESTROYED\n");
    }
    else {
        exit(-1);
    }

}