//
// Created by Bennet Weingartz on 29.10.21.
//

#include <GL/glew.h>

#include "fragment_shader.h"

const GLchar* fragmentShader = {
        "#version 410\n"\
    "in vec4 eColor;\n"\
    "out vec4 oColor;\n"\

    "void main(void)\n"\
    "{\n"\
    "oColor = eColor;\n"\
    "}\n"
};