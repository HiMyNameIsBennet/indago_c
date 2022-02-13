//
// Created by Bennet Weingartz on 29.10.21.
//

#ifndef INDAGO_C_SHADERS_H
#define INDAGO_C_SHADERS_H

#include <GL/glew.h>

extern GLuint programID;

GLuint LoadShader(const char* filename, GLenum type);
void InitShaders(void);
void DestroyShaders(void);

#endif //INDAGO_C_SHADERS_H
