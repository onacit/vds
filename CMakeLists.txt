cmake_minimum_required (VERSION 2.6)

project(VerboseDataStructuresInC)

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#set (PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/main/c)

#include_directories(src/main/h)
#add_subdirectory(src/main/c)



if(MSVC)
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ansi -pedantic -std=c99")
endif()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ansi -pedantic -std=c99")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -ansi -pedantic -std=c99")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#add_library(vdsic src/main/c/vds_utils.c src/main/c/vds_array.c)

file(GLOB_RECURSE MAIN_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/main/c/*.c")
add_library(vdsic ${MAIN_SOURCES})
target_include_directories(vdsic PRIVATE src/main/h)

#find_package(PkgConfig)
#pkg_check_modules(GTEST REQUIRED gtest>=1.7.0)
#pkg_check_modules(GMOCK REQUIRED gmock>=1.7.0)

#enable_testing()

#add_test(NAME vdsic_test vdsic_test)

