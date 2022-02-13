cmake_minimum_required(VERSION 3.20)
project(indago_c C)

set(CMAKE_C_STANDARD 11)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(indago_c main.c init/window.c core/render.c core/render.h init/window.h init/init.c init/init.h core/timer.c core/timer.h init/shaders.c init/shaders.h core/cleanup.c core/cleanup.h init/buffers.c init/buffers.h core/vertex.h core/resize.c core/resize.h core/input.c core/input.h core/utility.c core/utility.h core/object.h init/tests/cube.c init/tests/cube.h init/test.c init/test.h)

find_package(GLEW REQUIRED)
find_package(cglm REQUIRED)
find_package(glfw3 REQUIRED)


target_link_libraries(indago_c GLEW::GLEW cglm::cglm glfw)
