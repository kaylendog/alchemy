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
message(STATUS "Configuring googletest")
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(googletest)

# glfw
message(STATUS "Configuring GLFW")
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
message(STATUS "Configuring GLM")
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(glm)

# vulkan
message(STATUS "Configuring Vulkan")
if(NOT DEFINED ENV{VULKAN_SDK})
    message(FATAL_ERROR "VULKAN_SDK not set")
endif()
find_package(Vulkan REQUIRED)

# lua
message(STATUS "Configuring Lua")
FetchContent_Declare(
    LUA
    GIT_REPOSITORY https://github.com/lua/lua
    GIT_TAG v5.4.7
)
FetchContent_MakeAvailable(LUA)

add_library(Lua INTERFACE)

# file formats - png, jpeg, etc.
find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE TESTS "${CMAKE_SOURCE_DIR}/tests/*.cpp")

add_library(alchemy ${SOURCES} ${HEADERS})
target_include_directories(alchemy PUBLIC 
    "${CMAKE_SOURCE_DIR}/include"
    "${glm_SOURCE_DIR}"
    "${glfw_SOURCE_DIR}/include"
    "${Vulkan_INCLUDE_DIRS}"
    "${PNG_INCLUDE_DIRS}"
    "${JPEG_INCLUDE_DIRS}"
    "${LUA_SOURCE_DIR}"
)
target_link_libraries(alchemy PUBLIC 
    glm
    glfw
    Vulkan::Vulkan
    PNG::PNG
    JPEG::JPEG
    Lua
)

# compile examples
file(GLOB_RECURSE EXAMPLES "${CMAKE_SOURCE_DIR}/examples/*.cpp")
foreach(EXAMPLE ${EXAMPLES})
    message(STATUS "Configuring example '${EXAMPLE}'")
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE})
    target_link_libraries(${EXAMPLE_NAME} PRIVATE alchemy glfw Vulkan::Vulkan PNG::PNG JPEG::JPEG Lua)
    target_include_directories(${EXAMPLE_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")
endforeach()

# compile tests if they exist
file(GLOB_RECURSE TESTS "${CMAKE_SOURCE_DIR}/tests/*.cpp")
if(TESTS)
    enable_testing()
    include(GoogleTest)
    foreach(TEST ${TESTS})
        message(STATUS "Configuring test '${TEST}'")
        get_filename_component(TEST_NAME ${TEST} NAME_WE)
        add_executable(${TEST_NAME} ${TEST})
        target_link_libraries(${TEST_NAME} PRIVATE alchemy gtest_main)
        target_include_directories(${TEST_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")
        add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    endforeach()
    google_test_discover_tests(${TESTS})
endif()
