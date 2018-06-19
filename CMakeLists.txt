cmake_minimum_required (VERSION 3.5)

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
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lm -Wall -Wextra -ansi -pedantic -std=c99")
endif()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ansi -pedantic -std=c99")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -ansi -pedantic -std=c99 --pedantic-errors")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -ansi -pedantic -std=c11 --pedantic-errors")
#set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra  -Wstrict-aliasing -pedantic -fmax-errors=5 -Werror -Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option ${CMAKE_CXX_FLAGS}")
#set(CMAKE_CXX_FLAGS "-std=c99 -Wall -Wextra  -Wstrict-aliasing -pedantic -fmax-errors=5 -Werror -Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option ${CMAKE_CXX_FLAGS}")

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


#add_executable(vds_array_sort_merge_td, src/main/cvds_array_sort_merge_td.c)

add_executable(vdsic_array_get_int src/main/c/vdsic_array_get_int.c)
target_include_directories(vdsic_array_get_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_get_int vdsic)
target_link_libraries(vdsic_array_get_int m)

add_executable(vdsic_array_get_set_int src/main/c/vdsic_array_get_set_int.c)
target_include_directories(vdsic_array_get_set_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_get_set_int vdsic)
target_link_libraries(vdsic_array_get_set_int m)

add_executable(vdsic_array_set_int src/main/c/vdsic_array_set_int.c)
target_include_directories(vdsic_array_set_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_set_int vdsic)
target_link_libraries(vdsic_array_set_int m)

add_executable(vdsic_array_iterate_int src/main/c/vdsic_array_iterate_int.c)
target_include_directories(vdsic_array_iterate_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_iterate_int vdsic)
target_link_libraries(vdsic_array_iterate_int m)

add_executable(vdsic_array_delete_l_int src/main/c/vdsic_array_delete_l_int.c)
target_include_directories(vdsic_array_delete_l_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_delete_l_int vdsic)
target_link_libraries(vdsic_array_delete_l_int m)

add_executable(vdsic_array_delete_r_int src/main/c/vdsic_array_delete_r_int.c)
target_include_directories(vdsic_array_delete_r_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_delete_r_int vdsic)
target_link_libraries(vdsic_array_delete_r_int m)

add_executable(vdsic_array_sort_insertion_int src/main/c/vdsic_array_sort_insertion_int.c)
target_include_directories(vdsic_array_sort_insertion_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_sort_insertion_int vdsic)
target_link_libraries(vdsic_array_sort_insertion_int m)

add_executable(vdsic_array_sort_insertion_t_int src/main/c/vdsic_array_sort_insertion_t_int.c)
target_include_directories(vdsic_array_sort_insertion_t_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_sort_insertion_t_int vdsic)
target_link_libraries(vdsic_array_sort_insertion_t_int m)

add_executable(vdsic_array_sort_selection_int src/main/c/vdsic_array_sort_selection_int.c)
target_include_directories(vdsic_array_sort_selection_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_sort_selection_int vdsic)
target_link_libraries(vdsic_array_sort_selection_int m)

add_executable(vdsic_array_sort_merge_td_int src/main/c/vdsic_array_sort_merge_td_int.c)
target_include_directories(vdsic_array_sort_merge_td_int PRIVATE src/main/h)
target_link_libraries(vdsic_array_sort_merge_td_int vdsic)
target_link_libraries(vdsic_array_sort_merge_td_int m)
