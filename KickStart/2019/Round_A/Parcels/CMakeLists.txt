cmake_minimum_required(VERSION 3.14)
add_executable(MyTarget main.cc)
set_property(TARGET MyTarget PROPERTY CXX_STANDARD 20)
target_compile_options(MyTarget PRIVATE -Werror -Wall -Wextra)
# set_target_properties( MyTarget
#   PROPERTIES
#   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
# )