//
// Created by Bennet Weingartz on 30.01.22.
//

#include <stdio.h>

#include <GLFW/glfw3.h>

#include "input.h"
#include "../init/buffers.h"

void KeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_H: {
                activeIBO = (activeIBO == 1 ? 0 : 1);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID[activeIBO]);
                break;
            }
            default:
                break;
        }
    }
}
