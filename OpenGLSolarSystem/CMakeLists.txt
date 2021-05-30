cmake_minimum_required(VERSION 3.10)

project(OpenGLSolarSystem)

add_executable(solar-system main.cpp Planet.cpp RingSurface.cpp Sphere.cpp Utils.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_LIBRARY_PATH "${CMAKE_LIBRARY_PATH};~/computer_graphics/SOIL2/lib/linux;/lib")

target_include_directories(solar-system PRIVATE 
                           "~/computer_graphics/SOIL2/src")

target_link_libraries(solar-system PRIVATE
                      "/home/hyj/computer_graphics/SOIL2/lib/linux/libsoil2-debug.a"
                      GLEW
                      glfw
                      GL
)
