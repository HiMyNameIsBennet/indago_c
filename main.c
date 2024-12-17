#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "init/init.h"
#include "init/window.h"
#include "init/buffers.h"
#include "core/render.h"
#include "core/timer.h"
#include "core/object.h"
#include "core/camera.h"
#include "core/scenegraph.h"

#include "main.h"

int StartEngine(const int argc, const char** argv, Scenegraph* graph) {
    Init(argc, argv, false);
    GLenum err = glGetError();

    // Init VBOs manually
    NodeListItem* curr_renderable = graph->renderable_nodes.root;
    while(curr_renderable != NULL){
        InitVBO(curr_renderable->node->obj);
        curr_renderable = curr_renderable->next;
    }

    while(!glfwWindowShouldClose(window)){
        Timer();
        MoveCamera(&camera);
        Render(graph);
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
