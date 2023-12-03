#include <iostream>
#include <random>
#include <cmath> // For sqrt()

using namespace std;

void conditions() {
    int nFirstEdge;
    int nSecondEdge;
    int nThirdEdge;

    bool bPositive;
    bool bTriangleInequality;

    // C++11 random number generator
    random_device rd;
    mt19937 gen(rd());                           // Seed the generator
    uniform_int_distribution<> edgeDistrib(1, 100); // Define the range for edges
    uniform_real_distribution<> numberDistrib(0, 100); // Define the range for dMyNumber

    // Generate three random numbers for edges
    nFirstEdge = edgeDistrib(gen);
    nSecondEdge = edgeDistrib(gen);
    nThirdEdge = edgeDistrib(gen);

    cout << "Randomly generated edges: " << nFirstEdge << ", " << nSecondEdge
         << ", " << nThirdEdge << endl;

    bPositive = ((nFirstEdge > 0) && (nSecondEdge > 0) && (nThirdEdge > 0));

    bTriangleInequality = (nFirstEdge + nSecondEdge > nThirdEdge) &&
                          (nFirstEdge + nThirdEdge > nSecondEdge) &&
                          (nSecondEdge + nThirdEdge > nFirstEdge);

    cout << "Can the 3 edges form a triangle? "
         << ((bPositive && bTriangleInequality) ? "Yes" : "No") << endl;

    bool bBool = (30 > 20) && (20 > 10);
    cout << bBool << endl;

    double dMyNumber;

    // Generate a random number for dMyNumber
    dMyNumber = numberDistrib(gen);

    cout << "Randomly generated number: " << dMyNumber << endl;

    if (dMyNumber < 0) {
        cout << "The number is negative, it is treated as zero" << endl;
        dMyNumber = 0;
    }

    cout << "sqrt(" << dMyNumber << ") = " << sqrt(dMyNumber) << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << '*';
        }
        cout << endl;
    }
}
