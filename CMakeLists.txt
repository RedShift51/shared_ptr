cmake_minimum_required(VERSION 3.5)

project(shared_ptr)

set(SOURCES
    src/shared_ptr.cpp
    src/main.cpp
)

add_executable(shared_ptr ${SOURCES})

target_include_directories(shared_ptr
    PRIVATE 
	${PROJECT_SOURCE_DIR}/include
)

