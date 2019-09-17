project(manduca)

set(CMAKE_CXX_STANDARD 17)


# file(GLOB_RECURSE my_c_list RELATIVE ${CMAKE_SOURCE_DIR} "src/*")
file(GLOB allFiles
    "include/*.h"
    "src/*.cpp"
)


# -lstdc++fs

# Create the executable
add_executable(${PROJECT_NAME}.out ${allFiles})
target_include_directories(${PROJECT_NAME}.out PRIVATE "include")
target_link_libraries(${PROJECT_NAME}.out stdc++fs)

# target_link_libraries(${PROJECT_NAME}
#     sub::lib1
#     sub::lib2
# )
