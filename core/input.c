//
// Created by Bennet Weingartz on 30.01.22.
//

#include <stdio.h>

#include <GLFW/glfw3.h>

#include "input.h"
#include "camera.h"
#include "../init/init.h"

double xpos, ypos;

void KeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods){ //this script might get too big. consider func pointers for keys and outsourced functions
    float velocity[3];
    glm_vec3_copy(camera.velocity, velocity);

    switch (key) {
        case GLFW_KEY_W: {
            if(action == GLFW_PRESS) velocity[2] = 5;
            else if(action == GLFW_RELEASE) velocity[2] = 0;
            break;
        }
        case GLFW_KEY_A: {
            if(action == GLFW_PRESS) velocity[0] = 5;
            else if(action == GLFW_RELEASE) velocity[0] = 0;
            break;
        }
        case GLFW_KEY_S: {
            if(action == GLFW_PRESS) velocity[2] = -5;
            else if(action == GLFW_RELEASE) velocity[2] = 0;
            break;
        }
        case GLFW_KEY_D: {
            if(action == GLFW_PRESS) velocity[0] = -5;
            else if(action == GLFW_RELEASE) velocity[0] = 0;
            break;
        }
        default:
            break;
    }

    glm_vec3_copy(velocity, camera.velocity);
}

void MouseButtonInput(GLFWwindow* window, int button, int action, int mods){
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        glfwGetCursorPos(window, &xpos, &ypos);
        printf("Mouse button clicked at (%.0f, %.0f)\n", xpos, ypos);
    }
}