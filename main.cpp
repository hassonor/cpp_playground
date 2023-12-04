#include <cstdlib>
#include "headers/Stack.h"
#include "headers/Point.h"
#include "headers/StreamExamples.h"
#include "headers/ConcatExample.h"
#include "headers/NumConv.h"


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
    convertNumber();
    system("dir");

    return 0;
}





