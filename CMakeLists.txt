cmake_minimum_required(VERSION 3.17)
project(StateSandbox)

set(CMAKE_CXX_STANDARD 17)

# Everything will need to access this
include_directories(src)

# Create a DLL with an API
add_library(statelibrary SHARED src/worker.cpp src/worker.h src/state.cpp src/state.h src/api/api.cpp src/api/api.h src/manager.cpp src/manager.h)

# Create a main Sandbox binary that depends on the DLL
add_executable(statesandbox src/main.cpp)
target_link_libraries(statesandbox statelibrary)

# Turn on testing
enable_testing()

# Test the sandbox binary itself
add_test(NAME RunStateSandbox COMMAND "${CMAKE_BINARY_DIR}/statesandbox")

# Test the sandbox C API
add_executable(sandbox_api_tester tst/test_api.c)
add_test(NAME CallSandboxCPython COMMAND "${CMAKE_BINARY_DIR}/sandbox_api_tester")
target_link_libraries(sandbox_api_tester statelibrary)

# Test the sandbox Python API
find_package(Python COMPONENTS Interpreter)
add_test(NAME CallSandboxAPIPython COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/tst/test_api.py")
