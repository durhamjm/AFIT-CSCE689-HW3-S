#include <cstring>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <PCalc_SP.h>
#include <PCalc.h>
#include <math.h>

PCalc_SP::PCalc_SP(unsigned int count_to) : PCalc(count_to) {
}

PCalc_SP::~PCalc_SP() {
}

void PCalc_SP::markNonPrimes() {
    //variables
    unsigned int i = 2;
    unsigned int j = 0;

    //Just count through the numbers
    //Use sqrt of array size since smaller numbers were already checked, so if the number doesn't have any factors equal to or less
    //than it's square root, it's prime
    while (i < sqrt(array_size())) {
        if (PCalc::at(i)) {
            // std::cout << "Trying: ";
            // std::cout << i;
            // std::cout << std::endl;
            for (j = i * i;j < array_size();j = j + i) {
                //Added a check for false before setting the value; testing doesn't seem to show if it's faster or slower
                if (PCalc::at(j)) {
                    PCalc::at(j) = false;
                }
                // std::cout << "Setting ";
                // std::cout << j;
                // std::cout << std::endl;
            }
        }
        i++;
    }
}

void PCalc_SP::printPrimes(const char *filename) {
    PCalc::printPrimes(filename);
}
