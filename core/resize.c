//
// Created by Bennet Weingartz on 28.01.22.
//

#include <GLFW/glfw3.h>

#include "../init/window.h"

void Resize(void){
    glfwGetWindowSize(window, &currentWidth, &currentHeight);
}