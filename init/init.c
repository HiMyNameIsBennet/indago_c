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

int DIMENSION_MODE = 3;
mat4 projectionMatrix;
Camera camera;

void Init(int argc, char** argv){
    InitWindow(argc, argv);

    if(glewInit() == GLEW_OK){
        printf("GLEW OK\n");
    }

    InitShaders();
    InitUniforms();
    camera = InitCamera();
    Object* testObject = InitTest()[0];

    if(DIMENSION_MODE == 3){
      glm_perspective(20,
                      (float) currentWidth / currentHeight,
                      1.0f,
                      100.0f,
                      projectionMatrix);
    } else if(DIMENSION_MODE == 2){
      glm_ortho_default((float) currentWidth / currentHeight,
                        projectionMatrix);
    }
    glUniformMatrix4fv(projectionMatrixUniformLocation, 1, GL_FALSE, (float*) projectionMatrix);

    InitVBO(testObject);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
}
