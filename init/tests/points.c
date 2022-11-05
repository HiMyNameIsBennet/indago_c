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
int hz, vt;

Object** InitPoints(void){
    DIMENSION_MODE = 2;

    printf("Horizontal: ");
    scanf("%i", &hz);
    printf("Vertical: ");
    scanf("%i", &vt);

    int max = hz >= vt ? hz : vt;

    Vertex verts[hz * vt + 2];

    points = InitObject(verts, (sizeof(verts) / sizeof(Vertex)));

    for(int i = 0; i < vt; i++){
      for(int j = 0; j < hz; j++){
        points->verts[i*hz + j] = (Vertex) {{(2.0 / max) * j - (1 - 1.0 / max) + (1 - (float) hz / max), //x coord
                                             (2.0 / max) * i - (1 - 1.0 / max) + (1 - (float) vt / max), //y coord
                                              .0f, 1.0f}, {1.0, 1.0, 1.0, 1.0}};
      }
    }

    points->verts[points->vertexCount - 2] = (Vertex) {{0.0, 0.0, .0f, 1.0}, {1.0, 1.0, 1.0, 1.0}};
    points->verts[points->vertexCount - 1] = (Vertex) {{0.0, 0.0, .0f, 1.0}, {1.0, 1.0, 1.0, 1.0}};

    mat4 modelMatrix;
    CalcModel(points, modelMatrix);
    glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) modelMatrix);

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
    int clamp = currentHeight <= currentWidth ? currentHeight : currentWidth;
    double time = glfwGetTime();
    if(time - deltaTime >= 0.03){
      double x, y;
      glfwGetCursorPos(window, &x, &y);
      
      vec2 vel = {x - xPrev, y - yPrev};

      float xRatio = 1;
      float yRatio = 1;
      if(currentWidth >= currentHeight){
        xRatio = (float) currentWidth / currentHeight;
      } else {
        yRatio = (float) currentHeight / currentWidth;
      }


      points->verts[points->vertexCount - 2].pos[0] = 2.0 / clamp * xPrev - xRatio;
      points->verts[points->vertexCount - 2].pos[1] = -2.0 / clamp * yPrev + yRatio;
      points->verts[points->vertexCount - 1].pos[0] = 2.0 / clamp * x - xRatio;
      points->verts[points->vertexCount - 1].pos[1] = -2.0 / clamp * y + yRatio;

      //Need height, width, hz, vt based formulae
      float cursorColliderRadius = 50.0f;
      float vertexColliderRadius = 10.0f;

      for(int i = 0; i < points->vertexCount - 2; i++){
        //Could use proper basis transformation
        vec2 scaledVtxPos = {(xRatio + points->verts[i].pos[0]) / 2.0f * clamp,
                             (-yRatio + points->verts[i].pos[1]) / -2.0f * clamp};
        float dist = glm_vec2_distance(scaledVtxPos, (vec2) {x, y});
        if(dist < cursorColliderRadius + vertexColliderRadius){
          points->verts[i].col[1] = 0.0f; //Set to red
          points->verts[i].col[2] = 0.0f;
        }
        else{
          points->verts[i].col[1] = 1.0f; //Set to white
          points->verts[i].col[2] = 1.0f;
        }
      }

      RefreshVBO(points, "position");
      RefreshVBO(points, "color");

      deltaTime = time;
      xPrev = x;
      yPrev = y;
    }

    glDrawArrays(GL_POINTS, 0, points->vertexCount - 2);
    glDrawArrays(GL_LINES, points->vertexCount - 2, 2);
}