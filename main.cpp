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

using namespace std;

int globe = 11;


int main() {
    Stack s1; // Stack memory

    SecureStack s3;
    s3.print();

    Stack *sptr;
    sptr = &s3;

    // Virtual function, binding at runtime
    sptr->print();

    // Non-virtual function, binding at compile time
    sptr->show();

    int index = 0;
    while (index < 15) {
        s1.Push(index);
        index++;
    }


    Stack *s2 = new Stack(); // Heap memory
    s2->Push(14);
    delete s2;

    Point p1(5, 7);
    Point p2(1, 2);
    Point p3;
    p3 = p1 + p2;

    showStreamExamples();
    showConcatExample();
    helloStrings();

    std::string filename = "../examples_ch2/Vector.cpp";
    std::string wordToCount = "i";
    countWordOccurrences(filename, wordToCount);

    int totalWords = countWhiteSeperatedWords(filename);
    if (totalWords != -1) {
        std::cout << "Total number of words in file: " << totalWords << std::endl;
    }
    fillVector();
    floatVector(0.0, 100.0, 20);

//    removeHat('C');
//    specifiers();

    // Pointers and References
    demonstratePassingMethods();
    cout << "globe: " << globe << endl;
    specifiers();
    cout << "globe: " << globe << endl;

    bitwiseOperatorsDemo();
    bitRotationLeft(150);
    bitRotationRight(150);
    bitRotationLeft(151);
    bitRotationRight(151);
    constCastDemo();
    reinterpretCastDemo();
    explicitOperatorsDemo();
    simpleStruct();
    return 0;
}





