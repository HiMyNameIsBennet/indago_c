//
// Created by Bennet Weingartz on 29.10.21.
//

#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "render.h"
#include "../init/uniforms.h"
#include "../init/window.h"


void Render(Scenegraph* graph){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(graph == NULL){
        (*RenderTest)();
        glfwSwapBuffers(window);

        return;
    }

    // With renderable list in place, this is still the wrong draw order...
    // ...with depth buffer, this shouldn't matter?
    NodeListItem* curr_renderable = graph->renderable_nodes.root;
    while(curr_renderable != NULL){
        DrawRenderable(graph, curr_renderable->node);

        curr_renderable = curr_renderable->next;
    }

    glfwSwapBuffers(window);
}


void DrawRenderable(Scenegraph* graph, Node* node){
    mat4 modelMatrix;
    CalcModel(node->obj, modelMatrix);

    // Accumulate model matrix through scene graph
    Node* curr = node;
    while(curr->parent != graph->root){
        mat4 tmp;
        CalcModel(curr->parent->obj, tmp);
        glm_mat4_mul(tmp, modelMatrix, modelMatrix);

        curr = curr->parent;
    }

    glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) modelMatrix);
    glDrawArrays(GL_TRIANGLES, 0, node->obj->vertexCount);
}
