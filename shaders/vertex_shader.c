//
// Created by Bennet Weingartz on 29.10.21.
//

#include <GL/glew.h>

#include "vertex_shader.h"

const GLchar* vertexShader = {
        "#version 410\n"\
       "layout(location=0) in vec4 vPosition;\n"\
       "layout(location=1) in vec4 vColor;\n"\
       "out vec4 eColor;\n"\

       "void main(void)\n"\
       "{\n"\
       "    gl_Position = vPosition;\n"\
       "    eColor = vColor;\n"\
       "}\n"
};