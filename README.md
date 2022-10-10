# OpenGL Project

## Windows Build

~~I will eventually update this with more instructions to build on Windows.~~ For now, my suggestion is to use the WinBuilds compiler and select the x86_643 architecture. I can't garuntee there won't be problems.

Clone the submodules by running `git submodule init` and then `git submodule update`.

## Linux Build

Firstly clone the submodules by running `git submodule init` and then `git submodule update`.

Trouble may arise from `#include <GL/glew.h>` due to a missing plugin. In order to fix this, install mesa by executing `sudo apt-get install libglu1-mesa libglu1-mesa-dev`.

There are a few more dependencies required for cmake configuration as follows: `libxrandr-dev`, `libxinerama-dev`, `libxcursor-dev`, `libxi-dev`, and `libopengl-dev`.

Visual Studio code is currently used to manage cmake configuration and the building process. I would recommend vs code because it's already set up with it. Otherwise you can run the following command from the project's root directory: `cmake -S "./" -B "./build/" -G "Unix Makefiles"`

You can then build inside of vscode or execute `cmake --build "./build/"`.

Hopefully the project will then build successfully.
