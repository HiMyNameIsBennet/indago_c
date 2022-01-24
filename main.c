#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "init/init.h"
#include "init/window.h"
#include "core/render.h"
#include "core/timer.h"


int main(int argc, char** argv) {
    Init(argc, argv);

    while(!glfwWindowShouldClose(window)){
        Timer();
        Render();
        glfwPollEvents();
    }

    return 0;
}
