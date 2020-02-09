#ifndef PCALC_T_H
#define PCALC_T_H

#include "PCalc.h"
#include <thread>
#include <vector>

// Your implementation of PCalc_T class should go here. 
// Make sure your constructor takes in two parameters:

// PCalc_T::PCalc_T(unsigned int array_size, unsigned int num_threads);

// Call the parent constructor when initializing your constructor and pass in array_size. Then
// use num_threads to cap off how many threads you use to calculate all prime numbers

class PCalc_T : public PCalc {
    public:
    ~PCalc_T();
    PCalc_T(unsigned int count_to, unsigned int threads);
    unsigned int array_size() { return asize; };
    void markNonPrimes();
    void markT(int start);
    void printPrimes(const char *filename);

    int numThreads;

    std::vector<std::thread> threadList;

    protected:


    private:
    unsigned int asize;    

};

#endif
