cmake_minimum_required(VERSION 3.16)
project(kokkos-cpu-usage LANGUAGES CXX)

find_package(Kokkos REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE Kokkos::kokkos)
target_compile_features(main PRIVATE cxx_std_17)
