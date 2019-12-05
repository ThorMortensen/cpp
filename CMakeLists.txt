cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# set(CMAKE_REQUIRED_FLAGS -std=c++17)
set(CMAKE_CXX_STANDARD 17)


project(cppDojo VERSION 1.0
        DESCRIPTION "Cpp-Dojo"
        LANGUAGES CXX)

add_compile_options(-Wall
                    -Wextra # reasonable and standard
#                    -Wshadow # warn the user if a variable declaration shadows one from a
                             # parent context
#                    -Wno-c++98-compat
                                #    -Wnon-virtual-dtor # warn the user if a class with virtual functions has a
                    #                       # non-virtual destructor. This helps catch hard to
                    #                       # track down memory errors
                    #    -Wold-style-cast # warn for c-style casts
                    #    -Wcast-align # warn for potential performance problem casts
                    #    -Wunused # warn on anything being unused
                    #    -Woverloaded-virtual # warn if you overload (not override) a virtual
                    #                         # function
                    #    -Wpedantic # warn if non-standard C++ is used
                    #    -Wconversion # warn on type conversions that may lose data
                    #    -Wsign-conversion # warn on sign conversions
                    #    -Wmisleading-indentation # warn if identation implies blocks where blocks
                    #                             # do not exist
                    #    -Wduplicated-cond # warn if if / else chain has duplicated conditions
                    #    -Wduplicated-branches # warn if if / else branches have duplicated code
                    #    -Wlogical-op # warn about logical operations being used where bitwise were
                    #                 # probably wanted
                    #    -Wnull-dereference # warn if a null dereference is detected
                    #    -Wuseless-cast # warn if you perform a cast to the same type
                    #    -Wdouble-promotion # warn if float is implicit promoted to double
                    #    -Wformat=2 # warn on security issues around functions that format output
                    #               # (ie printf)
                     
                    )

# Add sub directories
# add_subdirectory(helloworld)
 add_subdirectory(loxo)
#add_subdirectory(workout)


