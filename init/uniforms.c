//
// Created by Bennet Weingartz on 13.02.22.
//

#include <GL/glew.h>
#include <cglm/cglm.h>

#include "uniforms.h"
#include "shaders.h"
#include "init.h"

GLuint projectionMatrixUniformLocation,
        viewMatrixUniformLocation,
        modelMatrixUniformLocation;

void InitUniforms(void){
    modelMatrixUniformLocation = glGetUniformLocation(programID, "modelMatrix");
    viewMatrixUniformLocation = glGetUniformLocation(programID, "viewMatrix");
    projectionMatrixUniformLocation = glGetUniformLocation(programID, "projectionMatrix");

    glUniformMatrix4fv(projectionMatrixUniformLocation, 1, GL_FALSE, (float*) projectionMatrix);
}

void UpdateUniforms(void){
    glUniformMatrix4fv(projectionMatrixUniformLocation, 1, GL_FALSE, (float*) projectionMatrix);
}