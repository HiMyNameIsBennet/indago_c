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

    points = malloc(sizeof(Object) + hz * vt * sizeof(Vertex));
    glm_mat4_identity(points->modelMatrix);
    points->vertexCount = hz * vt;

    for(int i = 0; i < vt; i++){
      for(int j = 0; j < hz; j++){
        points->verts[i*hz + j] = (Vertex) {{(2.0 / hz) * j - (1 - 1.0 / hz) , //x coord
                                             (2.0 / vt) * i - (1 - 1.0 / vt), //y coord
                                              0.5, 1.0}, {1.0, 1.0, 1.0, 1.0}};
      }
    }

    glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) points->modelMatrix);
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
    if(time - deltaTime >= 0.05){
      double x, y;
      glfwGetCursorPos(window, &x, &y);
      
      vec2 vel = {x - xPrev, y - yPrev};
      printf("Cursor velocity: (%0.f, %0.f) px/s\n", *vel * 20, *(vel + 1) * 20);

      deltaTime = time;
      xPrev = x;
      yPrev = y;
    }

    glDrawArrays(GL_POINTS, 0, points->vertexCount);
}