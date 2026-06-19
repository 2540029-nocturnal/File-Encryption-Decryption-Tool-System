cmake_minimum_required(VERSION 3.10)
project(FileEncryptionTool)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/Cipher.cpp
    src/CaesarCipher.cpp
    src/XORCipher.cpp
    src/EncryptionManager.cpp
    src/DecryptionManager.cpp
    src/KeyManager.cpp
    src/FileHandler.cpp
    src/User.cpp
)

# Create library
add_library(encryption_lib SHARED ${SOURCES})

# Add executable for testing
add_executable(encryption_tool main.cpp)
target_link_libraries(encryption_tool encryption_lib)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# Optional: Create static library
add_library(encryption_lib_static STATIC ${SOURCES})

# Compiler specific settings
if(MSVC)
    target_compile_options(encryption_lib PRIVATE /W4)
    target_compile_options(encryption_tool PRIVATE /W4)
else()
    target_compile_options(encryption_lib PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(encryption_tool PRIVATE -Wall -Wextra -pedantic)
endif()

# Installation
install(TARGETS encryption_lib encryption_lib_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/encryption)
install(TARGETS encryption_tool DESTINATION bin)

# Enable testing
enable_testing()

# Build message
message(STATUS "Build Configuration:")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  Source Directory: ${PROJECT_SOURCE_DIR}")
message(STATUS "  Binary Directory: ${PROJECT_BINARY_DIR}")
