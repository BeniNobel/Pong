cmake_minimum_required(VERSION 3.10)
project(Pong)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set CMake policies
cmake_policy(SET CMP0135 NEW)

# Add Homebrew paths for Apple Silicon Mac
set(HOMEBREW_PATH /opt/homebrew)

# Set SFML paths
set(SFML_DIR "${HOMEBREW_PATH}/Cellar/sfml@2/2.6.2_1/lib/cmake/SFML")
set(SFML_INCLUDE_DIR "${HOMEBREW_PATH}/Cellar/sfml@2/2.6.2_1/include")

# Set compiler flags for macOS
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -DSFML_NO_DEPRECATED_WARNINGS")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
endif()

# Find SFML
find_package(SFML 2.6.2 COMPONENTS system audio graphics window REQUIRED)

# Add raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(raylib)

# Set build type if not set
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SFML_INCLUDE_DIR}
)

# Add compile definitions to avoid conflicts
add_compile_definitions(
    SFML_NO_DEPRECATED_WARNINGS
    SFML_STATIC
)

# Get all source files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    raylib 
    sfml-system 
    sfml-audio 
    sfml-graphics 
    sfml-window
)

# Copy assets to build directory
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}) 