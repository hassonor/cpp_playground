cmake_minimum_required(VERSION 3.26)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_playground main.cpp
        examples_ch2/Stack.cpp
        examples_ch2/headers/Stack.h
        examples_ch2/Point.cpp
        examples_ch2/headers/Point.h
        examples_ch2/headers/FormatWithCommas.h
        examples_ch2/headers/StreamExamples.h
        examples_ch2/SteamExamples.cpp
        examples_ch2/headers/ConcatExample.h
        examples_ch2/ConcatExample.cpp
        examples_ch2/NumConv.cpp
        examples_ch2/headers/NumConv.h
        examples_ch2/HelloStrings.cpp
        examples_ch2/headers/HelloStrings.h
        examples_ch2/Scopy.cpp
        examples_ch2/headers/Scopy.h
        examples_ch2/FillingString.cpp
        examples_ch2/headers/FillingString.h
        examples_ch2/Vector.cpp
        examples_ch2/headers/Vector.h
        examples_ch2/Ch2Solutions.cpp
        examples_ch2/headers/Ch2Solutions.h
        examples_ch3/ch3Examples.cpp
        examples_ch3/headers/ch3Examples.h
        examples_ch3/PointersAndReferences.cpp
        examples_ch3/headers/PointersAndReferences.h
        examples_ch3/BitwiseOperators.cpp
        examples_ch3/headers/BitwiseOperators.h
        examples_ch3/CastingDemos.cpp
        examples_ch3/headers/CastingDemos.h
)

