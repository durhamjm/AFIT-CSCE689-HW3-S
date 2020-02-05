#include <cstring>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <PCalc_T.h>
#include <PCalc.h>
#include <pthread.h>
#include <math.h>

PCalc_T::PCalc_T(unsigned int count_to, unsigned int threads) : PCalc(count_to) {
    int t = 0;
    int arg;
    pthread_t threads2[threads];
    for (t = 0; t < threads; t++) {
        //std::cout << "Make thread #" << t << std::endl;
        int create = pthread_create(&threads2[t], NULL, markNonPrimes2, (void *) arg);
    }
}

PCalc_T::~PCalc_T() {
}

void PCalc_T::markNonPrimes() {
    //variables
    int i = 2;
    int j = 0;

    while (i < sqrt(array_size())) {
        if (PCalc::at(i)) {
            // std::cout << "Trying: ";
            // std::cout << i;
            // std::cout << std::endl;
            for (j = i * i;j < array_size();j = j + i) {
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

void *markNonPrimes2(void *arg) {

}

void PCalc_T::spawnThread() {
    int t = 0;
    
}


void PCalc_T::printPrimes(const char *filename) {
    PCalc::printPrimes(filename);
}