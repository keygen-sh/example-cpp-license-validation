cmake_minimum_required(VERSION 3.9)
project(example-cpp-license-validation)

find_package(cpprestsdk REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE cpprestsdk::cpprest OpenSSL::SSL)
