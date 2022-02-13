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


int main(int argc, char** argv) {
    Init(argc, argv);
    /*
    Object* cube = malloc(sizeof(Object) + sizeof(test));
    glm_mat4_identity(cube->modelMatrix);
    cube->vertexCount = sizeof(test)/sizeof(Vertex);

    for(int i = 0; i < cube->vertexCount; i++){
        cube->verts[i] = test[i];
    }
    */
    while(!glfwWindowShouldClose(window)){
        Timer();
        Render();
        glfwPollEvents();
    }

    return 0;
}
