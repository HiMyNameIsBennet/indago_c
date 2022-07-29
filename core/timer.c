//
// Created by Bennet Weingartz on 29.10.21.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <GLFW/glfw3.h>

#include "timer.h"
#include "../init/window.h"

unsigned frameCount = 0;
double time, secTimer, prevTime, frameTime = 0;
char* title;

void Timer(){
    prevTime = time;
    time = glfwGetTime();
    frameCount++;

    if(time - secTimer >= 1)
    {
        title = (char*) malloc(sizeof(char) * (strlen(WINDOW_TITLE_PREFIX) + 50));

        sprintf(title, "%s: %dFPS @ %dx%d",
                WINDOW_TITLE_PREFIX,
                frameCount,
                currentWidth,
                currentHeight);

        glfwSetWindowTitle(window, title);
        free(title);

        frameCount = 0;
        secTimer = time;
    }

    frameTime = time - prevTime;
}