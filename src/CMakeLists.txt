# === SMFL
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# === EXE
add_executable(snake main.cpp
  Snake.cpp
)

# === COMP, LINK...

target_include_directories(snake PUBLIC ${CMAKE_SOURCE_DIR}/headers)
target_compile_options(snake PUBLIC -std=c++11 -Wall -Wno-pedantic)
target_link_libraries(snake sfml-graphics sfml-audio)

# === INSTALL

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/snake
  DESTINATION bin
  RENAME ${CMAKE_PROJECT_NAME}-snake)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# === INFO

get_target_property(info_include snake INCLUDE_DIRECTORIES)
MESSAGE("SNAKE INFO ${info_include}")
get_target_property(info_libraries snake LINK_LIBRARIES)
MESSAGE("SNAKE INFO ${info_libraries}")

include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
# )

#FetchContent_MakeAvailable(googletest)

# FetchContent_Declare(
#   sfml
#   URL https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz
# )
# FetchContent_MakeAvailable(sfml)