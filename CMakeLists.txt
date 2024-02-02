cmake_minimum_required(VERSION 3.16)
project(StateOutputPortAnalizer)
# set up our program
add_executable(${PROJECT_NAME} ./src/StateOutputPortAnalizer.h ./src/StateOutputPortAnalizer.cpp  ./src/main.cpp )

install(TARGETS ${PROJECT} DESTINATION bin)