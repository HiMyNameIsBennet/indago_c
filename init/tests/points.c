#include <GL/glew.h>
#include <cglm/cglm.h>

#include "cube.h"
#include "../uniforms.h"
#include "../window.h"
#include "../buffers.h"
#include "../init.h"
#include "../../core/object.h"

Object* points = NULL;

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

    return &points;
}

void DestroyPoints(void){
    free(points);
    printf("POINTS DESTROYED\n");
}

void DrawPoints(void){
    //glm_rotate_x(points->modelMatrix, .001f, points->modelMatrix);
    //glm_rotate_y(points->modelMatrix, .001f, points->modelMatrix);
    //glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) points->modelMatrix);
    glDrawArrays(GL_POINTS, 0, points->vertexCount);
}