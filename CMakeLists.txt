cmake_minimum_required(VERSION 3.10)

project(
    Alchemy
    VERSION 0.1.0
    DESCRIPTION "Simple ECS on-top of Vulkan"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

# googletest
message(STATUS "Fetching googletest")
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(googletest)

# glfw
message(STATUS "Fetching GLFW")
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# glm
message(STATUS "Fetching glm")
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(glm)

# vulkan
message(STATUS "Setting up Vulkan")
if(NOT DEFINED ENV{VULKAN_SDK})
    message(FATAL_ERROR "VULKAN_SDK not set")
endif()
find_package(Vulkan REQUIRED)

# file formats - png, jpeg, etc.
find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE TESTS "${CMAKE_SOURCE_DIR}/tests/*.cpp")

list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/alchemy/alchemy.cpp")

add_library(engine ${SOURCES} ${HEADERS})
target_include_directories(engine PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(engine PUBLIC "${glm_SOURCE_DIR}")
target_include_directories(engine PUBLIC "${glfw_SOURCE_DIR}/include")
target_include_directories(engine PUBLIC "${Vulkan_INCLUDE_DIRS}")
target_include_directories(engine PUBLIC "${PNG_INCLUDE_DIRS}")
target_include_directories(engine PUBLIC "${JPEG_INCLUDE_DIRS}")

add_executable(alchemy "${CMAKE_SOURCE_DIR}/src/alchemy/alchemy.cpp")
target_link_libraries(alchemy PRIVATE engine Vulkan::Vulkan glfw glm)

enable_testing()
include(GoogleTest)

if(TESTS)
    add_executable(tests ${TESTS})
    target_link_libraries(tests PRIVATE engine GTest::gtest_main)
    target_include_directories(tests PUBLIC "${CMAKE_SOURCE_DIR}/include")
    gtest_discover_tests(tests)
endif()
