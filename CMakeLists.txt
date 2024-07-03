cmake_minimum_required(VERSION 3.0.0)
project(C++_design_test VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

add_executable(factory_method src/创建/factory_method.cpp)

add_executable(abstract_factory src/创建/abstract_factory.cpp)

add_executable(builder src/创建/builder.cpp)

add_executable(singleton src/创建/singleton.cpp)

add_executable(singleton_safe_thread src/创建/singleton_safe_thread.cpp)

add_executable(adaptor src/结构/adaptor.cpp)

add_executable(visitor src/行为/visitor.cpp)

add_executable(strategy src/行为/strategy.cpp)

add_executable(chain_of_command src/行为/chain_of_command.cpp)

add_executable(command_mode src/行为/command_mode.cpp)

add_executable(local_singleton src/创建/local_singleton.cpp)

add_executable(decorator src/行为/Decorator.cpp)

add_executable(iterator src/行为/Iterator.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
