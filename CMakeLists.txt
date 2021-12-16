cmake_minimum_required(VERSION 3.0.0)
project(Snake VERSION 0.1.0)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Snake main.cpp)
target_link_libraries(Snake sfml-graphics sfml-audio)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
