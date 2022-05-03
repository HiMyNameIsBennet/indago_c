//
// Created by Bennet Weingartz on 29.10.21.
//

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../core/render.h"
#include "../core/timer.h"
#include "../core/cleanup.h"
#include "../core/resize.h"
#include "../core/input.h"

#include "window.h"

int currentWidth = 800;
int currentHeight = 600;
GLFWwindow* window = NULL;

static void WindowClosingCallback(GLFWwindow* window);


void InitWindow(int argc, char** argv){
    if(!glfwInit()){
        printf("GLFW COULD NOT BE INITIALIZED");
        exit(-1);
    }
    else
        printf("GLFW OK\n");

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    window = glfwCreateWindow(currentWidth, currentHeight, WINDOW_TITLE_PREFIX, NULL, NULL);
    if(!window){
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);
    glfwSetWindowCloseCallback(window, WindowClosingCallback);
    glfwSetWindowSizeCallback(window, Resize);
    glfwSetKeyCallback(window, KeyboardInput);
    glfwSetMouseButtonCallback(window, MouseButtonInput);

    glClearColor(.0f, .0f, .0f, .0f);
}

static void WindowClosingCallback(GLFWwindow* window){
    printf("CLOSING\n");
    glfwDestroyWindow(window);
    printf("WINDOW TERMINATED\n");
    glfwTerminate();
    printf("GLFW TERMINATED\n");
    Cleanup();
    printf("CLEANUP DONE\nEXITING...");
    exit(EXIT_SUCCESS);
}
