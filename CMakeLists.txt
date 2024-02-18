cmake_minimum_required(VERSION 3.26)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost
find_package(Boost 1.75.0 REQUIRED COMPONENTS system filesystem) # specify the required components


add_executable(cpp_playground main.cpp
        notes/TICPP_vol1/examples_ch5/headers/StashV2.h
        notes/TICPP_vol1/examples_ch5/StackV2.cpp
        notes/TICPP_vol1/examples_ch5/headers/StackV2.h
        notes/TICPP_vol1/examples_ch5/StackImpArray.cpp
        notes/TICPP_vol1/examples_ch5/StackImpVector.cpp
        notes/TICPP_vol1/examples_ch5/headers/StackOfInt.h
        unit_2_sum_example/Point2.cpp
        unit_2_sum_example/headers/Point2.h
        unit_2_sum_example/Line2.cpp
        unit_2_sum_example/headers/Line2.h
        unit_2_sum_example/Circle2.cpp
        unit_2_sum_example/headers/Circle2.h
        unit_2_sum_example/headers/Shape2.h
        unit_2_sum_example/Polygon2.cpp
        unit_2_sum_example/headers/Polygon2.h
        unit_2_sum_example/headers/Filter.h
        unit_2_sum_example/FilterPerimeter.cpp
        unit_2_sum_example/headers/FilterPerimeter.h
        unit_2_sum_example/ShapesContainer.cpp
        unit_2_sum_example/headers/ShapesContainer.h
        examples_vuls/BaseUser.cpp
        examples_vuls/Number.cpp
        examples_vuls/Number.h
        unit_5_examples/socketDemo.cpp
        unit_5_examples/headers/socketDemo.h
        unit_5_examples/boostDemo.cpp
        unit_5_examples/SocketBoostClientDemo.cpp
        unit_5_examples/headers/SocketBoostClientDemo.h
        unit_5_examples/SocketBoostServerDemo.cpp
        unit_5_examples/headers/SocketBoostServerDemo.h
        boost_asio_demos/asio_example.cpp
        boost_asio_demos/headers/asio_example.h
        notes/server_winsock.cpp
        notes/server_winsock.h
)

# Link Boost libraries
target_link_libraries(cpp_playground Boost::system Boost::filesystem)

# Conditionally link against ws2_32 on Windows
if (WIN32)
    target_link_libraries(cpp_playground PRIVATE ws2_32)
endif ()