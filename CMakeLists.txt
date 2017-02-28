cmake_minimum_required (VERSION 3.5)
project (Hello)

set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/cmake/Config.h.in"
    "${PROJECT_SOURCE_DIR}/include/Config.h"
)

set (HELLO_SRCS src/hello_world.cc)

if (WIN32)
    set (HELLO_SRCS ${HELLO_SRCS} WinSupport.c)
endif ()

include_directories (
	"${PROJECT_SOURCE_DIR}/include"
)

add_executable (Hello ${HELLO_SRCS})

find_library (TCL_LIBRARY
    NAMES tcl tcl84 tcl83 tcl82 tcl80
    PATHS /usr/lib /usr/local/lib
    )

if (TCL_LIBRARY)
    target_link_library (Hello ${TCL_LIBRARY})
endif ()
