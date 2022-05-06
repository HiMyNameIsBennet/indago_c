#include <GL/glew.h>
#include <cglm/cglm.h>
#include <GLFW/glfw3.h>

#include "cube.h"
#include "../uniforms.h"
#include "../window.h"
#include "../buffers.h"
#include "../init.h"
#include "../../core/object.h"

Object* points = NULL;
double deltaTime = 0;
double xPrev, yPrev;

Object** InitPoints(void){
    int hz, vt;
    printf("Horizontal: ");
    scanf("%i", &hz);
    printf("Vertical: ");
    scanf("%i", &vt);

    points = malloc(sizeof(Object) + (hz * vt + 2) * sizeof(Vertex));
    points->vertexCount = hz * vt + 2;

    for(int i = 0; i < vt; i++){
      for(int j = 0; j < hz; j++){
        points->verts[i*hz + j] = (Vertex) {{(2.0 / hz) * j - (1 - 1.0 / hz) , //x coord
                                             (2.0 / vt) * i - (1 - 1.0 / vt), //y coord
                                              0.5, 1.0}, {1.0, 1.0, 1.0, 1.0}};
      }
    }

    points->verts[points->vertexCount - 2] = (Vertex) {{0.0, 0.0, 0.5, 1.0}, {1.0, 1.0, 1.0, 1.0}};
    points->verts[points->vertexCount - 1] = (Vertex) {{0.0, 0.0, 0.5, 1.0}, {1.0, 1.0, 1.0, 1.0}};

    glm_mat4_inv(projectionMatrix, points->modelMatrix);
    glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) points->modelMatrix);

    MoveCamera(&camera, (vec3) {.0, .0, 2.0});

    glPointSize(3);
    printf("POINTS OK\n");

    glfwGetCursorPos(window, &xPrev, &yPrev);

    return &points;
}

void DestroyPoints(void){
    free(points);
    printf("POINTS DESTROYED\n");
}

void DrawPoints(void){
    double time = glfwGetTime();
    if(time - deltaTime >= 0.03){
      double x, y;
      glfwGetCursorPos(window, &x, &y);
      
      vec2 vel = {x - xPrev, y - yPrev};

      points->verts[points->vertexCount - 2].pos[0] = 2.0 / currentWidth * xPrev - 1;
      points->verts[points->vertexCount - 2].pos[1] = -2.0 / currentHeight * yPrev + 1;
      points->verts[points->vertexCount - 1].pos[0] = 2.0 / currentWidth * x - 1;
      points->verts[points->vertexCount - 1].pos[1] = -2.0 / currentHeight * y + 1;

      RefreshVBO(points);

      deltaTime = time;
      xPrev = x;
      yPrev = y;
    }

    glm_mat4_inv(projectionMatrix, points->modelMatrix);
    glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) points->modelMatrix);

    glDrawArrays(GL_POINTS, 0, points->vertexCount - 2);
    glDrawArrays(GL_LINES, points->vertexCount - 2, 2);
}