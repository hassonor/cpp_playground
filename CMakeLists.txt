cmake_minimum_required(VERSION 3.26)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost
find_package(Boost 1.75.0 REQUIRED COMPONENTS system filesystem) # specify the required components


add_executable(cpp_playground main.cpp
        TICPP_vol1/examples_ch5/headers/StashV2.h
        TICPP_vol1/examples_ch5/StackV2.cpp
        TICPP_vol1/examples_ch5/headers/StackV2.h
        TICPP_vol1/examples_ch5/StackImpArray.cpp
        TICPP_vol1/examples_ch5/StackImpVector.cpp
        TICPP_vol1/examples_ch5/headers/StackOfInt.h
        TICPP_vol1/examples_ch6/Tree.cpp
        TICPP_vol1/examples_ch6/headers/Tree.h
        TICPP_vol1/examples_ch6/Stash2.cpp
        TICPP_vol1/examples_ch6/headers/Stash2.h
        TICPP_vol1/examples_ch6/Stack3.cpp
        TICPP_vol1/examples_ch6/headers/Stack3.h
        TICPP_vol1/examples_ch6/MultiArg.cpp
        TICPP_vol1/examples_ch6/headers/MultiArg.h
        TICPP_vol1/examples_ch6/AuthDefaultConstructor.cpp
        TICPP_vol1/examples_ch11/FreeStandingReferences.cpp
        TICPP_vol1/examples_ch11/headers/FreeStandingReferences.h
        TICPP_vol1/examples_ch11/Reference.cpp
        TICPP_vol1/examples_ch11/headers/Reference.h
        TICPP_vol1/examples_ch11/ReferenceToPointer.cpp
        TICPP_vol1/examples_ch11/headers/ReferenceToPointer.h
        TICPP_vol1/examples_ch11/HowMany2.cpp
        TICPP_vol1/examples_ch11/headers/HowMany2.h
        TICPP_vol1/examples_ch11/DefaultCopyConstructor.cpp
        TICPP_vol1/examples_ch11/headers/DefaultCopyConstructor.h
        TICPP_vol1/examples_ch11/PointerToMemberData.cpp
        TICPP_vol1/examples_ch11/headers/PointerToMemberData.h
        TICPP_vol1/examples_ch11/PointerToMemberFunction.cpp
        TICPP_vol1/examples_ch11/headers/PointerToMemberFunction.h
        TICPP_vol1/examples_ch11/PointerToMemberFunction2.cpp
        TICPP_vol1/examples_ch11/headers/PointerToMemberFunction2.h
        TICPP_vol1/examples_ch13/MallocClass.cpp
        TICPP_vol1/examples_ch13/headers/MallocClass.h
        TICPP_vol1/examples_ch13/PStash.cpp
        TICPP_vol1/examples_ch13/headers/PStash.h
        TICPP_vol1/examples_ch14/NameHiding.cpp
        TICPP_vol1/examples_ch14/headers/NameHiding.h
        TICPP_vol1/examples_ch14/SynthesizeFunctions.cpp
        TICPP_vol1/examples_ch14/headers/SynthesizeFunctions.h
        TICPP_vol1/examples_ch14/Car.cpp
        TICPP_vol1/examples_ch14/headers/Car.h
        TICPP_vol1/examples_ch14/FName.cpp
        TICPP_vol1/examples_ch14/headers/FName.h
        TICPP_vol1/examples_ch14/PrivateInheritance.cpp
        TICPP_vol1/examples_ch14/headers/PrivateInheritance.h
        TICPP_vol1/examples_ch14/ProtectedExample.cpp
        TICPP_vol1/examples_ch14/headers/ProtectedExample.h
        TICPP_vol1/examples_ch14/Byte.cpp
        TICPP_vol1/examples_ch14/headers/Byte.h
        TICPP_vol1/examples_ch14/OperatorInheritance.cpp
        TICPP_vol1/examples_ch14/headers/OperatorInheritance.h
        TICPP_vol1/examples_ch14/CopyConstructorUpCastingDemo.cpp
        TICPP_vol1/examples_ch14/headers/CopyConstructorUpCastingDemo.h
        TICPP_vol1/examples_ch15/Instrument.cpp
        TICPP_vol1/examples_ch15/headers/Instrument.h
        TICPP_vol1/examples_ch15/AddingVirtuals.cpp
        TICPP_vol1/examples_ch15/headers/AddingVirtuals.h
        TICPP_vol1/examples_ch15/NameHiding2.cpp
        TICPP_vol1/examples_ch15/headers/NameHiding2.h
        TICPP_vol1/examples_ch15/VariantReturn.cpp
        TICPP_vol1/examples_ch15/headers/VariantReturn.h
        TICPP_vol1/examples_ch15/VirtualDestructors.cpp
        TICPP_vol1/examples_ch15/headers/VirtualDestructors.h
        TICPP_vol1/examples_ch15/OStack.cpp
        TICPP_vol1/examples_ch15/headers/OStack.h
        TICPP_vol1/examples_ch15/OperatorPolymorphism.cpp
        TICPP_vol1/examples_ch15/headers/OperatorPolymorphism.h
        TICPP_vol1/examples_ch15/DynamicCast.cpp
        TICPP_vol1/examples_ch15/headers/DynamicCast.h
        TICPP_vol1/examples_ch15/StaticHierarchyNavigation.cpp
        TICPP_vol1/examples_ch15/headers/StaticHierarchyNavigation.h
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
)

# Link Boost libraries
target_link_libraries(cpp_playground Boost::system Boost::filesystem)