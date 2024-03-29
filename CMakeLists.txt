cmake_minimum_required(VERSION 3.18)
project(indago_c C)

set(CMAKE_C_STANDARD 11)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_library(indago_c main.c main.h init/window.c core/render.c core/render.h init/window.h init/init.c init/init.h core/timer.c core/timer.h init/shaders.c init/shaders.h core/cleanup.c core/cleanup.h init/buffers.c init/buffers.h core/vertex.h core/resize.c core/resize.h core/input.c core/input.h core/utility.c core/utility.h core/object.h init/tests/cube.c init/tests/cube.h init/test.c init/test.h init/uniforms.c init/uniforms.h core/camera.c core/camera.h init/tests/points.c init/tests/points.h init/tests/waves.c init/tests/waves.h core/object.c physics/rays.c physics/rays.h init/tests/mouse-ray.h init/tests/mouse-ray.c)


find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)


include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

fetchcontent_declare(
  cglm
  GIT_REPOSITORY https://github.com/recp/cglm
  GIT_TAG v0.8.5
  GIT_PROGRESS TRUE
)

fetchcontent_declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw
  GIT_TAG 3.3.7
  GIT_PROGRESS TRUE
)


if(NOT cglm_POPULATED)
  fetchcontent_populate(cglm)
  add_subdirectory(${CMAKE_SOURCE_DIR}/build/_deps/cglm-src ${CMAKE_SOURCE_DIR}/build/_deps/cglm-build)
endif()

if(NOT glfw_POPULATED)
  fetchcontent_populate(glfw)
  add_subdirectory(${CMAKE_SOURCE_DIR}/build/_deps/glfw-src ${CMAKE_SOURCE_DIR}/build/_deps/glfw-build)
endif()


target_link_libraries(indago_c GLEW::GLEW cglm glfw ${OPENGL_LIBRARY})
