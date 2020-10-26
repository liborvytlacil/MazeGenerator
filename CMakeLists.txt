# CMakeList.txt : CMake project for MazeGenerator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("MazeGenerator")

# c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Report all warnings
if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall)
endif()

# Add source to this project's executable.
add_executable (MazeGenerator "Main.cpp" "MazeGenerator.cpp" "MazeGenerator.h" "RandomGenerator.h")

# TODO: Add tests and install targets if needed.
add_executable(MazeGeneratorTest "test/test.cpp" "MazeGenerator.h" "RandomGenerator.h" "MazeGenerator.cpp")
add_test(NAME MazeGeneratorTest COMMAND MazeGeneratorTest)
ENABLE_TESTING()
