# ┌──────────────────────────────────────────────────────────────────┐
# │  Projects Settings                                               │
# └──────────────────────────────────────────────────────────────────┘
cmake_minimum_required (VERSION 2.8)
project (OpenGLRenderingProjects)

# ┌──────────────────────────────────────────────────────────────────┐
# │  Compilation flags                                               │
# └──────────────────────────────────────────────────────────────────┘

# zuvor:
#list(APPEND CMAKE_CXX_FLAGS "-std=c++11")
# brauche aber folgende Zeile:
list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -pthread")
# opencv braucht pthread lib

add_definitions(-Wall)

# ---> version A from https://github.com/ArthurSonzogni/OpenGL_CMake_Skeleton/blob/master/CMakeLists.txt
# ┌──────────────────────────────────────────────────────────────────┐
# │  Load libraries                                                  │
# └──────────────────────────────────────────────────────────────────┘
# glfw
#set(GLFW_BUILD_EXAMPLES OFF CACHE STRING "" FORCE)
#set(GLFW_BUILD_TESTS    OFF CACHE STRING "" FORCE)
#set(GLFW_INSTALL        OFF CACHE STRING "" FORCE)
#add_subdirectory(lib/glfw)
#include_directories(lib/glfw/include)

# glew
#add_definitions(-DGLEW_STATIC)
#option(glew-cmake_BUILD_SHARED "" OFF)
#add_subdirectory(lib/glew)
#include_directories(lib/glew/include lib/glew/src)

# glm
# include_directories(lib/glm)

# ---> version A end

# ---> version B from https://github.com/morizotter/imgui-opengl-glfw-glew-cmake-demo/blob/master/CMakeLists.txt
#

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
# ---> version B end

# opencv
#FIND_PACKAGE( OpenCV REQUIRED )
#INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )

# ┌──────────────────────────────────────────────────────────────────┐
# │  Build executable                                                │
# └──────────────────────────────────────────────────────────────────┘
# add_subdirectory(imgui)
file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*)
include_directories(${PROJECT_SOURCE_DIR}/src/)

add_executable(main ${source_files})
target_link_libraries(main glfw ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT}) # SOIL)
