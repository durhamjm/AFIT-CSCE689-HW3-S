#include <cstring>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <PCalc_T.h>
#include <PCalc.h>
// #include <pthread.h>
#include <math.h>
#include <cmath>
#include <thread>

PCalc_T::PCalc_T(unsigned int count_to, unsigned int threads) : PCalc(count_to) {
    numThreads = threads;
    
    //Attempted to use p_threads; couldn't figure out the struct to hold the data
    // int t = 0;
    // struct thread_data *threaddata;
    // pthread_t threads2[threads];
    // for (t = 0; t < threads; t++) {
    //     //std::cout << "Making thread #" << t << std::endl;
    //     int create = pthread_create(&threads2[t], NULL, t_markNonPrimes, (void *) &threaddata);
    // }
}

PCalc_T::~PCalc_T() {
}

void PCalc_T::markNonPrimes() {
    int n = 0;
    int m = 0;

    //Make the threads, track them in a vector, and send them to markT
    //I tried making a spawnThread() function, but since the main file calls markNonPrimes, this function has to happen first
    //so it was easier to spawn them here and make another marking function
    for (n = 0; n < numThreads; n++) {
        std::thread spawnThread(&PCalc_T::markT, this, n);
        this->threadList.push_back(std::move(spawnThread));
        std::cout << "Making thread # " << n << std::endl;
    }

    for (m = 0; m < threadList.size(); m++) {
        threadList.at(m).join();
    }
}

void PCalc_T::markT(int start) {
    //variables
    unsigned int i = 2;
    unsigned int j = 0;
    int threadpos = 0;

    //Same check as _SP, but with a threadposition so they don't repeat work
     while (i < sqrt(PCalc::array_size())) {
        
        if (PCalc::at(i) && i <= threadpos) {
    //         // std::cout << "Trying: ";
    //         // std::cout << i;
    //         // std::cout << std::endl;
            threadpos = i;
            for (j = i * i;j < PCalc::array_size();j = j + i) {
                if (PCalc::at(j)) {
                    PCalc::at(j) = false;
                }
    //             // std::cout << "Setting ";
    //             // std::cout << j;
    //             // std::cout << std::endl;
            }
        }
        i++;
    }


}

// void *t_markNonPrimes(void *data) {   
// }



void PCalc_T::printPrimes(const char *filename) {
    PCalc::printPrimes(filename);
}