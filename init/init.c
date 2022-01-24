//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <GL/glew.h>

#include "window.h"
#include "shaders.h"
#include "buffers.h"

void Init(int argc, char** argv){
    InitWindow(argc, argv);

    if(glewInit() == GLEW_OK){
        printf("GLEW OK\n");
    }

    InitShaders();
    InitVBO();
}