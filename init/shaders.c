//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include "../shaders/vertex_shader.h"
#include "../shaders/fragment_shader.h"
#include "shaders.h"

GLuint vShaderID, fShaderID, programID;

void InitShaders(void){
    GLenum errorValue = glGetError();

    vShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShaderID, 1, &vertexShader, NULL);
    glCompileShader(vShaderID);


    fShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShaderID, 1, &fragmentShader, NULL);
    glCompileShader(fShaderID);


    programID = glCreateProgram();
    glAttachShader(programID, vShaderID);
    glAttachShader(programID, fShaderID);
    glLinkProgram(programID);
    glUseProgram(programID);


    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("SHADERS OK\n");
    }
    else{
        exit(-1);
    }
}

void DestroyShaders(void){
    GLenum errorValue = glGetError();

    glUseProgram(0);

    glDetachShader(programID, vShaderID);
    glDetachShader(programID, fShaderID);

    glDeleteShader(vShaderID);
    glDeleteShader(fShaderID);

    glDeleteProgram(programID);

    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("SHADERS DESTROYED\n");
    }
    else {
        exit(-1);
    }
}

