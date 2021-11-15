cmake_minimum_required(VERSION 3.0.0)
project(OpenGL VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(OpenGL ./src/main.cpp)

add_subdirectory(./dep/glfw)

target_include_directories(${PROJECT_NAME}
	PUBLIC dep/glfw/include
)

target_link_directories(${PROJECT_NAME}
	PUBLIC dep/glfw/src
)

target_link_libraries(${PROJECT_DIR} glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
