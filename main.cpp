#include "examples_ch2/headers/Stack.h"
#include "examples_ch2/headers/Point.h"
#include "examples_ch2/headers/StreamExamples.h"
#include "examples_ch2/headers/ConcatExample.h"
#include "examples_ch2/headers/HelloStrings.h"
#include "examples_ch2/headers/Vector.h"
#include "examples_ch2/headers/Ch2Solutions.h"
#include "examples_ch3/headers/ch3Examples.h"
#include "examples_ch3/headers/PointersAndReferences.h"
#include "examples_ch3/headers/BitwiseOperators.h"
#include "examples_ch3/headers/CastingDemos.h"
#include "examples_ch3/headers/StructExamples.h"
#include "examples_ch3/headers/Arrays.h"
#include "examples_ch3/headers/Pointer.h"
#include "examples_ch4/headers/CLib.h"
#include "examples_ch4/headers/CppLib.h"
#include "examples_ch5/headers/NestedFriend.h"
#include "examples_ch5/headers/Ex1.h"
#include "examples_ch5/headers/Ex3.h"
#include "examples_ch5/headers/StackOfInt.h"
#include "examples_ch6/headers/Tree.h"
#include "examples_ch6/headers/Stash2.h"
#include "examples_ch6/headers/Stack3.h"
#include "examples_ch6/headers/MultiArg.h"
#include "examples_ch11/headers/FreeStandingReferences.h"
#include "examples_ch11/headers/ReferenceToPointer.h"
#include "examples_ch11/headers/HowMany2.h"
#include "examples_ch11/headers/DefaultCopyConstructor.h"
#include "examples_ch11/headers/PointerToMemberData.h"
#include "examples_ch11/headers/PointerToMemberFunction.h"
#include "examples_ch14/headers/NameHiding.h"
#include "examples_ch14/headers/SynthesizeFunctions.h"
#include "examples_ch14/headers/FName.h"
#include "examples_ch14/headers/OperatorInheritance.h"
#include "examples_ch14/headers/CopyConstructorUpCastingDemo.h"
#include "exhamples_ch15/headers/Instrument.h"

using namespace std;

int globe = 11;


int main(int argc, char* argv[]) {
    Instrument* A[] = {
            new Wind,
            new Percussion,
            new Stringed,
            new Brass
    };

    Wind flute;
    Percussion drum;
    Stringed violin;
    Brass flugelhorn;
    Woodwind recorder;
    tune(flute);
    tune(drum);
    tune(violin);
    tune(flugelhorn);
    tune(recorder);
    f(flugelhorn);
//    Stack s1; // Stack memory
//
//    SecureStack s3;
//    s3.print();
//
//    Stack* sptr;
//    sptr = &s3;
//
//    // Virtual function, binding at runtime
//    sptr->print();
//
//    // Non-virtual function, binding at compile time
//    sptr->show();
//
//    int index = 0;
//    while (index < 15) {
//        s1.Push(index);
//        index++;
//    }
//
//
//    Stack* s2 = new Stack(); // Heap memory
//    s2->Push(14);
//    delete s2;
//
//    Point p1(5, 7);
//    Point p2(1, 2);
//    Point p3;
//    p3 = p1 + p2;
//
//    showStreamExamples();
//    showConcatExample();
//    helloStrings();
//
//    std::string filename = "../examples_ch2/Vector.cpp";
//    std::string wordToCount = "i";
//    countWordOccurrences(filename, wordToCount);
//
//    int totalWords = countWhiteSeperatedWords(filename);
//    if (totalWords != -1) {
//        std::cout << "Total number of words in file: " << totalWords << std::endl;
//    }
//    fillVector();
//    floatVector(0.0, 100.0, 20);

//    removeHat('C');
//    specifiers();

    // Pointers and References
//    demonstratePassingMethods();
//    cout << "globe: " << globe << endl;
//    specifiers();
//    cout << "globe: " << globe << endl;
//
//    bitwiseOperatorsDemo();
//    bitRotationLeft(150);
//    bitRotationRight(150);
//    bitRotationLeft(151);
//    bitRotationRight(151);
//    constCastDemo();
//    reinterpretCastDemo();
//    explicitOperatorsDemo();
//    simpleStruct();
//
//    cout << "argc = " << argc << endl;
//    for (int i = 0; i < argc; i++)
//        cout << "argv[" << i << "] = "
//             << argv[i] << endl;
//
//    double d = atof("3.14159");
//    unsigned char* cp =
//            reinterpret_cast<unsigned char*>(&d);
//    for (int i = sizeof(double); i > 0; i -= 2) {
//        printBinary(cp[i - 1]);
//        printBinary(cp[i]);
//    }
//
//    int i[10];
//    double q[10];
//    int* ip = i;
//    double* dp = q;
//
//    ip[0] = 3;
//    ip[1] = 5;
//    dp[0] = 3.14;
//    dp[1] = 6.28;
//
//    std::cout << "ip = " << reinterpret_cast<uintptr_t>(ip) << std::endl;
//    std::cout << "*ip = " << *ip << std::endl;
//    ip++;
//    std::cout << "ip = " << reinterpret_cast<uintptr_t>(ip) << std::endl;
//    std::cout << "*ip = " << *ip << std::endl;
//
//    std::cout << "dp = " << reinterpret_cast<uintptr_t>(dp) << std::endl;
//    std::cout << "*dp = " << *dp << std::endl;
//    dp++;
//    std::cout << "dp = " << reinterpret_cast<uintptr_t>(dp) << std::endl;
//    std::cout << "*dp = " << *dp << std::endl;
//
//    pointerArithmeticDemo();
//    pointerToFunction();
//    functionTable();
//    functionTable2();
//    testCLib();
//    testStructSizes();
//    testNestedFriend();
//    Ex3 ex3{};
//    cout << showValue(&ex3) << endl;
//    changeValue(&ex3, 5);
//    cout << showValue(&ex3) << endl;
//    testTreeClass();
//    int i_test = 4;
//    int* i_pointer = &i_test;
//    cout << &i_test << endl;
//    cout << i_pointer << endl;
//    *i_pointer = 10;
//    cout << i_test << endl;
//    cout << *i_pointer << endl;
//    testStash3();
//    testMultiArg();
//    testStack3();
//    showFreeStandingReferenceDemo();
//    referenceToPointerDemo();
//    testHowMany2();
//    testComposite();
//    testDataClass();
//    testWidget1();
//    testTreeClass();
//    testNameHiding();
//    testSynthesizeFunctions();
//    testFNameClass();
//    testByte2();
//    testCCUpCastingDemo();
}





