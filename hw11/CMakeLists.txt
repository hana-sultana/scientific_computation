cmake_minimum_required( VERSION 3.12 )
project( mosquito LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_BUILD_TYPE Release )

add_executable( mosquito_vector mosquito_vector.cpp )
add_executable( mosquito_array mosquito_array.cpp )

target_include_directories( mosquito_vector PUBLIC $ENV{TACC_CXXOPTS_INC} )
target_include_directories( mosquito_array PUBLIC $ENV{TACC_CXXOPTS_INC} )
