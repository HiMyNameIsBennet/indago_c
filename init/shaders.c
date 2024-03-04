//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include "shaders.h"

GLuint vShaderID, fShaderID, programID;

void InitTestShaders(void){
    GLenum errorValue = glGetError();

    vShaderID = LoadShader("../shaders/shader.vertex.glsl", GL_VERTEX_SHADER);
    fShaderID = LoadShader("../shaders/shader.fragment.glsl", GL_FRAGMENT_SHADER);
    programID = glCreateProgram();

    glAttachShader(programID, vShaderID);
    glAttachShader(programID, fShaderID);
    glLinkProgram(programID);
    glUseProgram(programID);

    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("TEST SHADERS OK\n");
    }
    else{
        exit(-1);
    }
}

void DestroyTestShaders(void){
    GLenum errorValue = glGetError();

    glUseProgram(0);

    glDetachShader(programID, vShaderID);
    glDetachShader(programID, fShaderID);

    glDeleteProgram(programID);

    glDeleteShader(vShaderID);
    glDeleteShader(fShaderID);


    errorValue = glGetError();

    if(errorValue == GL_NO_ERROR){
        printf("TEST SHADERS DESTROYED\n");
    }
    else {
        exit(-1);
    }
}

GLuint LoadShader(const char* filename, GLenum type){
    GLuint errorValue = glGetError();
    FILE* file;
    long fileSize = -1;
    char* glSource;
    GLuint id = 0;


    file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);

    rewind(file);

    glSource = (char*) malloc(fileSize + 1);
    fread(glSource, sizeof(char), fileSize, file);
    glSource[fileSize] = '\0';

    id = glCreateShader(type);
    glShaderSource(id, 1, (const GLchar**) &glSource, NULL);
    glCompileShader(id);

    errorValue = glGetError();

    free(glSource);
    fclose(file);

    if(errorValue == GL_NO_ERROR){
        printf("%s SHADER LOADED\n", type == 35633 ? "VERTEX" : "FRAGMENT");
    }
    else {
        exit(-1);
    }

    return id;
}
