//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include "buffers.h"
#include "../core/vertex.h"

GLuint vaoID, vboID, iboID[2], activeIBO = 0;

void InitVBO(void){
    Vertex vtxArray[] = {
    {{ 0.0f, 0.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f }},

    {{-0.2f, 0.8f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f, 1.0f}},
    {{ 0.2f, 0.8f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f, 1.0f}},
    {{ 0.0f, 0.8f, 0.0f, 1.0f}, {1.0f, 1.0f, 0.0f, 1.0f}},
    {{ 0.0f, 1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}},

    {{-0.2f, -0.8f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f, 1.0f}},
    {{ 0.2f, -0.8f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f, 1.0f}},
    {{ 0.0f, -0.8f, 0.0f, 1.0f}, {1.0f, 1.0f, 0.0f, 1.0f}},
    {{ 0.0f, -1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}},

    {{-0.8f, -0.2f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f, 1.0f}},
    {{-0.8f, 0.2f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f, 1.0f}},
    {{-0.8f, 0.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 0.0f, 1.0f}},
    {{-1.0f, 0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}},

    {{ 0.8f, -0.2f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f, 1.0f}},
    {{ 0.8f, 0.2f, 0.0f, 1.0f}, {0.0f, 1.0f, 1.0f, 1.0f}},
    {{ 0.8f, 0.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 0.0f, 1.0f}},
    {{ 1.0f, 0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}}
    };

    GLubyte idxArray[] = {
            0, 1, 3,
            0, 3, 2,
            3, 1, 4,
            3, 4, 2,

            0, 5, 7,
            0, 7, 6,
            7, 5, 8,
            7, 8, 6,

            0, 9, 11,
            0, 11, 10,
            11, 9, 12,
            11, 12, 10,

            0, 13, 15,
            0, 15, 14,
            15, 13, 16,
            15, 16, 14
    };

    GLubyte idxArrayAlt[] = {
            3, 4, 16,
            3, 15, 16,
            15, 16, 8,
            15, 7, 8,
            7, 8, 12,
            7, 11, 12,
            11, 12, 4,
            11, 3, 4,

            0, 11, 3,
            0, 3, 15,
            0, 15, 7,
            0, 7, 11
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

    glGenBuffers(2, iboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(idxArray), idxArray, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(idxArrayAlt), idxArrayAlt, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID[0]);

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
    glDeleteBuffers(2, iboID);

    glDeleteVertexArrays(1, &vaoID);

    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("BUFFERS DESTROYED\n");
    }
    else {
        exit(-1);
    }

}