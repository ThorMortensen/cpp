project(helloworld)

# file(GLOB_RECURSE my_c_list RELATIVE ${CMAKE_SOURCE_DIR} "src/*")
file(GLOB allFiles
    "include/*.h"
    "src/*.cpp"
)


# Create the executable
add_executable(${PROJECT_NAME}.run ${allFiles})
target_include_directories(${PROJECT_NAME}.run PRIVATE "include")


# target_link_libraries(${PROJECT_NAME}
#     sub::lib1
#     sub::lib2
# )
