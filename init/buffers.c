//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include "buffers.h"
#include "../core/vertex.h"

GLuint vaoID, vboID;

void InitVBO(void){
    Vertex vtxArray[] = {
    {{-0.8f, -0.8f,0.0f,1.0f }, {1.0f, 0.0f, 1.0f, 1.0f }},
    {{ 0.0f,  0.8f,0.0f,1.0f }, {1.0f, 1.0f, 0.0f, 1.0f }},
    {{ 0.8f, -0.8f,0.0f,1.0f }, {0.0f, 1.0f, 1.0f, 1.0f }},
    {{ 0.3f,  0.7f,0.0f,1.0f }, {0.204f, 0.933f, 0.855f, 1.0f }},
    {{ 0.5f,  0.3f,0.0f,1.0f }, {0.922f, 0.835f, 0.357f, 1.0f }},
    {{ 0.7f,  0.7f,0.0f,1.0f }, {0.745f, 0.247f, 0.882f, 1.0f }}
    };

    GLenum errorValue = glGetError();
    const size_t bufSize = sizeof(vtxArray);
    const size_t vtxSize = sizeof(vtxArray[0]);
    const size_t rgbOffset = sizeof(vtxArray[0].pos);

    glGenVertexArrays(1, &vaoID); //Vertex Array Object
    glBindVertexArray(vaoID);

    glGenBuffers(1, &vboID); //Vertex Buffer Object
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, bufSize, vtxArray, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, vtxSize, 0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, vtxSize, (GLvoid*) rgbOffset);

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