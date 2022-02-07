//
// Created by Bennet Weingartz on 29.10.21.
//

#ifndef INDAGO_C_WINDOW_H
#define INDAGO_C_WINDOW_H

#include <GLFW/glfw3.h>

#define WINDOW_TITLE_PREFIX "main"

extern int currentWidth,
        currentHeight;

extern GLFWwindow* window;

void InitWindow(int argc, char** argv);

#endif //INDAGO_C_WINDOW_H
