cmake_minimum_required(VERSION 3.18)
project(indago_c C)

set(CMAKE_C_STANDARD 11)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(indago_c main.c init/window.c core/render.c core/render.h init/window.h init/init.c init/init.h core/timer.c core/timer.h init/shaders.c init/shaders.h core/cleanup.c core/cleanup.h init/buffers.c init/buffers.h core/vertex.h core/resize.c core/resize.h core/input.c core/input.h core/utility.c core/utility.h core/object.h init/tests/cube.c init/tests/cube.h init/test.c init/test.h init/uniforms.c init/uniforms.h core/camera.c core/camera.h)


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
  add_subdirectory(${cglm_SOURCE_DIR} ${cglm_BUILD_DIR})
endif()

if(NOT glfw_POPULATED)
  fetchcontent_populate(glfw)
  add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BUILD_DIR})
endif()


target_link_libraries(indago_c GLEW::GLEW cglm glfw ${OPENGL_LIBRARY})
