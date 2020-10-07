# CMakeList.txt : CMake project for MazeGenerator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("MazeGenerator")

# Add source to this project's executable.
add_executable (MazeGenerator "Main.cpp" "MazeGenerator.cpp" "MazeGenerator.h" "RandomGenerator.h")

# TODO: Add tests and install targets if needed.
add_executable(MazeGeneratorTest "test/test.cpp" "MazeGenerator.h" "RandomGenerator.h" "MazeGenerator.cpp")
add_test(NAME MazeGeneratorTest COMMAND MazeGeneratorTest)
ENABLE_TESTING()
