//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <string.h>

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

void Init(const int argc, const char** argv){
    InitWindow(argc, argv);

    if(glewInit() == GLEW_OK){
        printf("GLEW OK\n");
    }
	
    if(DIMENSION_MODE == 2){
    	glm_ortho_default((float) currentWidth / currentHeight,
        	            projectionMatrix);
	} else {
    glm_perspective(20,
                    (float) currentWidth / currentHeight,
                    1.0f,
                    100.0f,
                    projectionMatrix);
    }


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    

    if(argc > 1 && strcmp(argv[1], "testing") != 0){
        return;
    }

    // only proceed if testing

    InitTestShaders();

    InitUniforms();
    camera = InitCamera();

    UpdateUniforms();

    Object* testObject = InitTest()[0];

    InitVBO(testObject);
}

