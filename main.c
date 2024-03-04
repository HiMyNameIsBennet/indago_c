#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "init/init.h"
#include "init/window.h"
#include "core/render.h"
#include "core/timer.h"
#include "core/object.h"
#include "core/camera.h"

#include "main.h"

int c_main(const int argc, const char** argv) {
    Init(argc, argv);
    GLenum err = glGetError();

    while(!glfwWindowShouldClose(window)){
        Timer();
        glfwPollEvents();
    }

    return 0;
}

// int main(const int argc, const char** argv) {
//     Init(argc, argv);
//     GLenum err = glGetError();

//     while(!glfwWindowShouldClose(window)){
//         Timer();
//         MoveCamera(&camera);
//         Render();
//         glfwPollEvents();
//     }

//     return 0;
// }
