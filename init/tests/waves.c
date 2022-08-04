//
// Created by Bennet Weingartz on 17.06.22.
//

#include <GL/glew.h>
#include <cglm/cglm.h>

#include <GLFW/glfw3.h>

#include "waves.h"
#include "../uniforms.h"
#include "../buffers.h"
#include "../../core/utility.h"

Object* point = NULL;
int wavesDeltaTime = 0; //because conflict with points.c, replace later with global timing system

Object** InitWaves(void){
  const Vertex verts[51] = {
      {{0.0, 0.7, 0.0, 1.0}, {1.0, 1.0, 1.0, 1.0}}
  };

  point = InitObject(verts, (sizeof(verts) / sizeof(Vertex)));

  mat4 modelMatrix;
  CalcModel(point, modelMatrix);

  for(int i = 0; i < point->vertexCount; i++){
    point->verts[i] = i == 0 ? verts[i] : (Vertex) {{0.7, 0.0, 0.0, 1.0}, {1.0, 1.0, 1.0, 1.0}};
  }

  glUniformMatrix4fv(modelMatrixUniformLocation, 1, GL_FALSE, (float*) modelMatrix);
  glPointSize(10);

  printf("WAVES OK\n");

  return &point;
}

void DestroyWaves(void){
  free(point);
  printf("WAVES DESTROYED\n");
}

void DrawWaves(void){
  double time = glfwGetTime();
  if(time - wavesDeltaTime >= 0.03){


      wavesDeltaTime = time;
  }

  point->verts[0].pos[0] = sin(time * 2) * 0.7;
  point->verts[0].pos[1] = cos(time * 2) * 0.7;

  RefreshVBO(point, "position");

  glDrawArrays(GL_POINTS, 0, point->vertexCount);
}