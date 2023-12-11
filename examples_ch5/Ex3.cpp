#include "headers/Ex3.h"

// Changes the value of the private member 'i' in an Ex3 object
void changeValue(Ex3* ex3, int newValue) {
    ex3->i = newValue;
}

// Returns the value of the private member 'i' in an Ex3 object
int showValue(Ex3* ex3) {
    return ex3->i;
}
