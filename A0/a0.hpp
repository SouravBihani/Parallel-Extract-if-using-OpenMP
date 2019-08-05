// File: a0.hpp
// FirstName: Sourav
// LastName: Bihani
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A0_HPP
#define A0_HPP
#include <math.h>
#include <vector>
#include <omp.h>
#include <iostream>
using namespace std;

// IMPLEMENT ME!
template <typename T, typename Pred>
void omp_extract_if(const std::vector<T>& in, std::vector<T>& out, Pred pred) {
	
    int size = in.size();
    int mycount=0;
    //omp_set_num_threads(8);
    // Parallel Section
    #pragma omp parallel shared( mycount)
    {
    mycount = count_if (in.begin(), in.end(), pred);
    out.resize(mycount);
    }
    #pragma omp critical
	{	
	for(int i = 0; i < size; i++) {
	if(pred(in[i]))
            {
               out.push_back(in[i]);
            }

	}
      
}}
// omp_extract_if

#endif // A0_HPP
