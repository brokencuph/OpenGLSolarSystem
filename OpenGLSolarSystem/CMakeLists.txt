cmake_minimum_required(VERSION 3.10)

project(OpenGLSolarSystem)


set(CMAKE_CXX_STANDARD 17)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(soil2 CONFIG REQUIRED)

add_executable(solar-system main.cpp Planet.cpp RingSurface.cpp Sphere.cpp Utils.cpp)
target_link_libraries(solar-system PRIVATE GLEW::GLEW glfw glm::glm soil2)

add_custom_command(TARGET solar-system POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/OpenGLSolarSystem/textures $<TARGET_FILE_DIR:solar-system>/textures)

configure_file("vertShader.glsl" "vertShader.glsl" COPYONLY)
configure_file("fragShader.glsl" "fragShader.glsl" COPYONLY)
configure_file("star_vertShader.glsl" "star_vertShader.glsl" COPYONLY)
configure_file("star_fragShader.glsl" "star_fragShader.glsl" COPYONLY)