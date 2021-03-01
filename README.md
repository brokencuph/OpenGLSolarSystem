# OpenGLSolarSystem
This program renders a solar system model, with limited interaction features, using *OpenGL* and some additional libraries.

## Development Tool
Visual Studio 2019

## Libraries Used
- OpenGL
- GLEW
- GLFW
- GLM
- SOIL2

## How to compile
Open the solution file in Visual Studio 2019, and build the solution.

You need to prepare some library binaries and headers by yourself, and put it under `OpenGLSolarSystem/shared` folder. Typically, you'll need the following files:
- lib/glew32.lib
- lib/glfw3.lib
- lib/soil2-debug.lib
- include/GL (from GLEW)
- include/GLFW
- include/SOIL2
- include/GLM
- glew32.dll (runtime library)

Further details can be found in the project configuration.

## Usage
Once the application starts, you should see a scene consisting of a (modeled, unreal) sun and some planets (and the moon). Scroll to zoom in and out, with the sun being the center. Dragging using your mouse (touch devices may also work) will result in different view angles.

## Notes
This project does not intentionally use any platform-dependent features, and the libraries are all cross-platform, so it should be easy to use it on platforms other than Windows. Just prepare corresponding library files for that platform, and it will work.

The source code is written in C++, and GLSL (for shaders). The C++ part uses some features from C++14, such as `std::string` literals.

Some of the texture pictures are from textbook [1] and other sources. If something violates your copyright, please contact me and I'll delete them.

[1]: V. S. Gordon and J. Clevenger, Computer Graphics Programming in OpenGL with C++, Mercury Learning and Information, 2019.
