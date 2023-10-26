#include "voronoi.h"

#include <time.h>
#include <GLFW/glfw3.h>

#include "../uniforms.h"
#include "../buffers.h"

Object* cells = NULL;
int cellCount;
float (*velocities)[2] = NULL;

Object** InitVoronoi(void){
    Vertex verts[] = {
        {{-1.f, -1.f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{-1.f, 1.f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{-1.f, 1.f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{1.f, 1.f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{1.f, 1.f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{1.f, -1.f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{1.f, -1.f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{-1.f, -1.f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}},
        {{.0f, .0f, 0.f, 1.f}, {1.f, 1.f, 1.f, 1.f}}
    };

    cellCount = (sizeof(verts) / sizeof(Vertex)) - 8;

    cells = InitObject(verts, cellCount + 8);

    mat4 modelMatrix;
    CalcModel(cells, modelMatrix);

    glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) modelMatrix);

    //srand(glfwGetTime());
    srand(time(NULL)); //for SOME REASON this SIGBUSes on my old mac???

    velocities = malloc(sizeof(float[cellCount][2])); //is there a better way for a global VLA?
    for(int i = 0; i < cellCount; i++){
        velocities[i][0] = (rand() % 201 - 100.f) / 100.f;
        velocities[i][1] = sqrtf(1 - powf(velocities[i][0], 2));

        if(rand() % 2 == 1){
            velocities[i][1] *= -1;
        }

        printf("x: %f, y: %f\n", velocities[i][0], velocities[i][1]);
    }

    glPointSize(10);

    printf("VORONOI OK\n");

    return &cells;
}


void DestroyVoronoi(void){
    free(cells);
    free(velocities);
    printf("VORONOI DESTROYED\n");
}


void DrawVoronoi(void){
    for(int i = 8; i < cellCount + 8; i++){
        cells->verts[i].pos[0] += velocities[i-8][0] / 7500.f;
        cells->verts[i].pos[1] += velocities[i-8][1] / 7500.f;

        //this deserves more efficiency. offset modulo in velocity addition?
        if(cells->verts[i].pos[0] <= -1 || cells->verts[i].pos[0] >= 1){
            cells->verts[i].pos[0] *= -1;
        }

        if(cells->verts[i].pos[1] <= -1 || cells->verts[i].pos[1] >= 1){
            cells->verts[i].pos[1] *= -1;
        }
    }

    RefreshVBO(cells, "position");

    glDrawArrays(GL_LINES, 0, 8);
    glDrawArrays(GL_POINTS, 8, cells->vertexCount - 8);
}
