cmake_minimum_required(VERSION 3.24)
project(Chillar_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chillar_Management_System main.cpp admin.cpp Convicted.cpp Functions.cpp hierarchy.cpp Person.cpp Prisoners.cpp test.cpp Visitor.cpp PrisonersUi.cpp PrisonersUi.h)
