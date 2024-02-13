cmake_minimum_required(VERSION 3.16)
project(kokkos-cpu-usage LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

find_package(Kokkos REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE Kokkos::kokkos)
target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)
