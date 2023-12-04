cmake_minimum_required(VERSION 3.26)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_playground main.cpp
        examples/Stack.cpp
        headers/Stack.h
        examples/Point.cpp
        headers/Point.h
        headers/method_hiding.h
        headers/FormatWithCommas.h
        headers/StreamExamples.h
        examples/SteamExamples.cpp
        headers/ConcatExample.h
        examples/ConcatExample.cpp
        examples/NumConv.cpp
        headers/NumConv.h
)

