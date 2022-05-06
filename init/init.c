//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <GL/glew.h>
#include <cglm/cglm.h>

#include "window.h"
#include "shaders.h"
#include "buffers.h"
#include "uniforms.h"
#include "test.h"
#include "../core/camera.h"
#include "../core/object.h"

mat4 projectionMatrix;
Camera camera;

void Init(int argc, char** argv){
    InitWindow(argc, argv);

    if(glewInit() == GLEW_OK){
        printf("GLEW OK\n");
    }

    glm_perspective(20,
                    (float) currentWidth / currentHeight,
                    1.0f,
                    100.0f,
                    projectionMatrix);

    InitShaders();
    InitUniforms();
    camera = InitCamera();
    Object* testObject = InitTest()[0];
    InitVBO(testObject);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
}
