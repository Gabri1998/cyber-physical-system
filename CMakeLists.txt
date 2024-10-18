cmake_minimum_required(VERSION 3.2)

project(template-opencv)

################################################################################
# Configuration

set(OPENDLV_STANDARD_MESSAGE_SET opendlv-standard-message-set-v0.9.6.odvd)
set(CLUON_COMPLETE cluon-complete-v0.0.127.hpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -D_XOPEN_SOURCE=700 \
    -D_FORTIFY_SOURCE=2 \
    -O2 \
    -fstack-protector \
    -fomit-frame-pointer \
    -pipe \
    -Weffc++ \
    -Wall -Wextra -Wshadow -Wdeprecated \
    -Wdiv-by-zero -Wfloat-equal -Wfloat-conversion -Wsign-compare -Wpointer-arith \
    -Wuninitialized -Wunreachable-code \
    -Wunused -Wunused-function -Wunused-label -Wunused-parameter -Wunused-but-set-parameter -unused-but-set-variable \
    -Wunused-value -Wunused-variable -Wunused-result \
    -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

################################################################################
# Custom Commands and Targets

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/cluon-msc
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_CURRENT_SOURCE_DIR}/src/${CLUON_COMPLETE} ${CMAKE_BINARY_DIR}/cluon-complete.hpp
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_BINARY_DIR}/cluon-complete.hpp ${CMAKE_BINARY_DIR}/cluon-complete.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -o ${CMAKE_BINARY_DIR}/cluon-msc ${CMAKE_BINARY_DIR}/cluon-complete.cpp -std=c++14 -pthread -D HAVE_CLUON_MSC
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/${CLUON_COMPLETE}
    COMMENT "Building cluon-msc"
)

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/opendlv-standard-message-set.hpp
    COMMAND ${CMAKE_BINARY_DIR}/cluon-msc --cpp --out=${CMAKE_BINARY_DIR}/opendlv-standard-message-set.hpp ${CMAKE_CURRENT_SOURCE_DIR}/src/${OPENDLV_STANDARD_MESSAGE_SET}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/${OPENDLV_STANDARD_MESSAGE_SET} ${CMAKE_BINARY_DIR}/cluon-msc
    COMMENT "Generating opendlv-standard-message-set.hpp"
)

add_custom_target(generate_opendlv_standard_message_set_hpp DEPENDS ${CMAKE_BINARY_DIR}/opendlv-standard-message-set.hpp)

################################################################################
# Include Directories

include_directories(SYSTEM ${CMAKE_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/utils)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/data)

################################################################################
# Libraries and Linker Flags

set(LIBRARIES Threads::Threads)

if(UNIX)
    if(NOT "${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
        find_package(LibRT REQUIRED)
        set(LIBRARIES ${LIBRARIES} ${LIBRT_LIBRARIES})
        include_directories(SYSTEM ${LIBRT_INCLUDE_DIR})
    endif()
endif()

# Ensure OpenCV package is found and required modules are included
find_package(OpenCV REQUIRED core highgui imgproc imgcodecs)
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found!")
endif()
include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS})
set(LIBRARIES ${LIBRARIES} ${OpenCV_LIBS})

################################################################################
# Source Files

set(SOURCE_FILES
    src/utils/ControlCommands.cpp
    src/utils/DataLogger.cpp
    src/data/VisionBasedNavigation.cpp
    src/data/IntegralSteering.cpp
    src/${PROJECT_NAME}.cpp  # Ensure this file contains the main function
    src/utils/fileio.cpp
)

set(HEADER_FILES
    src/utils/ControlCommands.hpp
    src/utils/DataLogger.hpp
    src/data/VisionBasedNavigation.hpp
    src/data/IntegralSteering.hpp
    src/utils/fileio.hpp
)

################################################################################
# Create Executable

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
add_dependencies(${PROJECT_NAME} generate_opendlv_standard_message_set_hpp)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

################################################################################
# Install Executable

install(TARGETS ${PROJECT_NAME} DESTINATION bin COMPONENT ${PROJECT_NAME})

################################################################################
# Testing and Analysis Tools

enable_testing()
add_custom_target(coverage)

add_custom_target(pmccabe
    COMMAND pmccabe -v ${CMAKE_CURRENT_SOURCE_DIR}/src/data/VisionBasedNavigation.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/template-opencv.cpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running pmccabe on source files"
)
add_dependencies(${PROJECT_NAME} pmccabe)
