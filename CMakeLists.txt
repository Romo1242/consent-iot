cmake_minimum_required(VERSION 3.10)
project(seal_audit_demo)

find_package(SEAL 4.1 REQUIRED)

add_executable(seal_audit_demo seal_audit_demo.cpp)
target_link_libraries(seal_audit_demo SEAL::seal)
