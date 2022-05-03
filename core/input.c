//
// Created by Bennet Weingartz on 30.01.22.
//

#include <stdio.h>

#include <GLFW/glfw3.h>

#include "input.h"
#include "camera.h"
#include "../init/init.h"
#include "../init/buffers.h"

double xpos, ypos;

void KeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods){ //this script might get too big. consider func pointers for keys and outsourced functions
    float camMoveVector[] = {.0f, .0f, .0f};
    switch (key) {
        case GLFW_KEY_W: {
            camMoveVector[2] = .05f;
            break;
        }
        case GLFW_KEY_A: {
            camMoveVector[0] = .05f;
            break;
        }
        case GLFW_KEY_S: {
            camMoveVector[2] = -.05f;
            break;
        }
        case GLFW_KEY_D: {
            camMoveVector[0] = -.05f;
            break;
        }
        default:
            break;
    }
    MoveCamera(&camera, camMoveVector);
}

void MouseButtonInput(GLFWwindow* window, int button, int action, int mods){
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        glfwGetCursorPos(window, &xpos, &ypos);
        printf("Mouse button clicked at (%.0f, %.0f)\n", xpos, ypos);
    }
}