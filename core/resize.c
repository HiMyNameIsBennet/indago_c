//
// Created by Bennet Weingartz on 28.01.22.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "../init/window.h"
#include "../init/init.h"
#include "../init/uniforms.h"

void Resize(GLFWwindow* window, int width, int height){
    currentWidth = width;
    currentHeight = height;

    glViewport(0, 0, currentWidth, currentHeight);

    if(DIMENSION_MODE == 3){
      glm_perspective(20,
                      (float) currentWidth / currentHeight,
                      1.0f,
                      100.0f,
                      projectionMatrix);
    } else if(DIMENSION_MODE == 2){
      glm_ortho_default((float) currentWidth / currentHeight,
                        projectionMatrix);
    }

  UpdateUniforms();
}