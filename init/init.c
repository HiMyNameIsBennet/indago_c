//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <GL/glew.h>

#include "window.h"
#include "shaders.h"
#include "buffers.h"
#include "test.h"

#include "tests/cube.h"

void Init(int argc, char** argv){
    InitWindow(argc, argv);

    if(glewInit() == GLEW_OK){
        printf("GLEW OK\n");
    }

    InitShaders();
    InitVBO();
    InitTest();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
}