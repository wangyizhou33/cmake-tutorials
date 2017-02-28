cmake_minimum_required (VERSION 3.5)
project (Hello)
set (CMAKE_BUILD_TYPE Release)

set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/cmake/Config.h.in"
    "${PROJECT_BINARY_DIR}/Config.h"
)

set (HELLO_SRCS src/hello_world.cc)

if (WIN32)
    set (HELLO_SRCS ${HELLO_SRCS} WinSupport.c)
endif ()

# cmake configured options
include_directories (
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_BINARY_DIR}"
)

# compile utils subdirectory
option (USE_UTILS ON)

if (USE_UTILS)
	include_directories ("${PROJECT_SOURCE_DIR}/utils")
	add_subdirectory (utils)
	set (EXTRA_LIBS ${EXTRA_LIBS} Utils)
endif (USE_UTILS)

add_executable (Hello ${HELLO_SRCS})
target_link_libraries(Hello ${EXTRA_LIBS})

find_library (TCL_LIBRARY
    NAMES tcl tcl84 tcl83 tcl82 tcl80
    PATHS /usr/lib /usr/local/lib
    )

if (TCL_LIBRARY)
    target_link_library (Hello ${TCL_LIBRARY})
endif ()