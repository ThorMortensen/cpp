cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()


project(cppDojo VERSION 1.0
        DESCRIPTION "Train cpp"
        LANGUAGES CXX)



add_executable(helloWorld src/helloWorld/main.cpp)


# target_compile_options(project_warnings
#                        INTERFACE
#                        -Wall
#                        -Wextra # reasonable and standard
#                        -Wshadow # warn the user if a variable declaration shadows one from a
#                                 # parent context
#                        -Wnon-virtual-dtor # warn the user if a class with virtual functions has a
#                                           # non-virtual destructor. This helps catch hard to
#                                           # track down memory errors
#                        -Wold-style-cast # warn for c-style casts
#                        -Wcast-align # warn for potential performance problem casts
#                        -Wunused # warn on anything being unused
#                        -Woverloaded-virtual # warn if you overload (not override) a virtual
#                                             # function
#                        -Wpedantic # warn if non-standard C++ is used
#                        -Wconversion # warn on type conversions that may lose data
#                        -Wsign-conversion # warn on sign conversions
#                        -Wmisleading-indentation # warn if identation implies blocks where blocks
#                                                 # do not exist
#                        -Wduplicated-cond # warn if if / else chain has duplicated conditions
#                        -Wduplicated-branches # warn if if / else branches have duplicated code
#                        -Wlogical-op # warn about logical operations being used where bitwise were
#                                     # probably wanted
#                        -Wnull-dereference # warn if a null dereference is detected
#                        -Wuseless-cast # warn if you perform a cast to the same type
#                        -Wdouble-promotion # warn if float is implicit promoted to double
#                        -Wformat=2 # warn on security issues around functions that format output
#                                   # (ie printf)
#                        )
# add_library(helloWorld_lib STATIC src/helloWorld/main.cpp include/helloWorld/lib.hpp)
# target_include_directories(helloWorld_lib PUBLIC include)