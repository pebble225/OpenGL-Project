cmake_minimum_required(VERSION 3.0.0)
project(OpenGL VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(OpenGL ./src/main.cpp
	./src/GameInstance.cpp
	./src/ShaderProgram.cpp
	./src/Mesh.cpp
)

add_subdirectory(./dep/glfw)
add_subdirectory(./dep/glew)
add_subdirectory(./dep/glm)

add_definitions(-DGLEW_STATIC)

target_include_directories(${PROJECT_NAME}
	PUBLIC dep/glfw/include
	PUBLIC dep/glew/include
	PUBLIC include/
	PUBLIC dep/glm/glm
)

target_link_directories(${PROJECT_NAME}
	PUBLIC dep/glfw/src
	PUBLIC dep/glew/src
)

target_link_libraries(${PROJECT_NAME}
	glfw
	libglew_static
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
