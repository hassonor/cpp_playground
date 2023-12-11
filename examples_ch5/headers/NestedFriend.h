// Created by Or on 12/11/2023.
//

#ifndef CPP_PLAYGROUND_NESTEDFRIEND_H
#define CPP_PLAYGROUND_NESTEDFRIEND_H

// Define a constant for the size of the array
const int sz = 20;

// Declare the Holder class
struct Holder {
private:
    int a[sz]; // An array of integers with size 'sz'

public:
    void initialize(); // Method to initialize the array

    // Forward declaration of the nested Pointer class
    struct Pointer;
    // Declare Pointer as a friend of Holder, allowing it to access Holder's private members
    friend Pointer;

    // Define the nested Pointer class
    struct Pointer {
    private:
        Holder* h; // Pointer to a Holder object
        int* p;    // Pointer to an integer (used to navigate the array in Holder)

    public:
        void initialize(Holder* h); // Initialize the Pointer with a Holder object

        // Methods to navigate the array:
        void next();      // Move to the next element
        void previous();  // Move to the previous element
        void top();       // Move to the first element
        void end();       // Move to the last element

        // Methods to access and modify array elements:
        int read();       // Read the current element
        void set(int i);  // Set the current element to a new value
    };
};

// Declare a function to test the nested friend class
void testNestedFriend();

#endif //CPP_PLAYGROUND_NESTEDFRIEND_H
