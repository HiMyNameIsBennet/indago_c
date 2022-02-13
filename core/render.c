//
// Created by Bennet Weingartz on 29.10.21.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "render.h"
#include "../init/window.h"

void (*RenderTest)(void);

void Render(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    (*RenderTest)();

    glfwSwapBuffers(window);
}