#include <iostream>
#include <random>

using namespace std;

void input_demo() {
  int nWorkingDays;
  int nWorkingHours;
  int nTotalHours;

  // C++11 random number generator
  random_device rd;  // Obtain a random number from hardware
  mt19937 gen(rd()); // Seed the generator
  uniform_int_distribution<> daysDistrib(1, 7); // Define range for days (1-7)
  uniform_int_distribution<> hoursDistrib(1,
                                          12); // Define range for hours (1-12)

  // Generating random number of working days and hours
  nWorkingDays = daysDistrib(gen);
  nWorkingHours = hoursDistrib(gen);

  // Calculating the total amount of hours
  nTotalHours = nWorkingDays * nWorkingHours;

  // Printing the randomly generated values and the result
  cout << "Randomly generated number of working days: " << nWorkingDays << endl;
  cout << "Randomly generated number of working hours in a day: "
       << nWorkingHours << endl;
  cout << "The total number of hours is: " << nTotalHours << endl;
}
