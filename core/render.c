//
// Created by Bennet Weingartz on 29.10.21.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "render.h"
#include "timer.h"
#include "../init/window.h"
#include "../init/buffers.h"

void Render(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(activeIBO == 0) {
        glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_BYTE, NULL);
    } else {
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, NULL);
    }

    glfwSwapBuffers(window);
}