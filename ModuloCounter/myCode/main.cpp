/**
 * @file main.cpp
 * @brief A program to test the ModuloNCounter class.
 *
 * This program asks the user for the number of digits and base of a counter,
 * then creates a ModuloNCounter and prints out some sequences of its values.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "ModuloNCounter.h"

/**
 * @brief The main function of the program.
 *
 * It asks the user for:
 * - Number of digits
 * - Base type (2, 8, 10, 16)
 *
 * Then it makes a ModuloNCounter object and prints values in several cycles.
 *
 * @return int Returns 0 when the program ends.
 */
int main()
{
    cout << "ModuloCounter started." << endl << endl;

    int m; ///< Number of digits
    int n; ///< Base type (2, 8, 10, 16)

    // Ask the user for the counter settings
    cout << "Please enter the parameter of your counter:" << endl;
    cout << "Number of Digits:-" << endl;
    cin >> m;

    cout << "Type(2/8/10/16):-" << endl;
    cin >> n;

    // Make the counter with user input
    ModuloNCounter counter(m, n);

    // Print the counter's name
    counter.printName();

    // Print 5 cycles of counter values
    for (int k = 0; k < 5; k++)
    {
        do {
            counter.printValue(); // Print current value
        } while (!counter.increment()); // Stop when counter wraps

        cout << "\n";
    }

    return 0;
}
