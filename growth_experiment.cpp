// ============================================================================
// CS32 P01 Part 2: the growth-factor experiment
//
// Implement measure_growth below. Then run   make experiment && ./experiment
// to see your results as a table.
// ============================================================================

#include "growth_experiment.h"
#include "Vector.h"

// Sets Vector<int>::growth_factor to factor, then push_backs n ints into an
// empty Vector<int>, watching what happens, and returns the GrowthStats (see
// growth_experiment.h for what each field means). Before returning, puts
// growth_factor back to the value it had when measure_growth was called.
//
// Measure by watching a real Vector<int>: push_back the elements one at a time
// and use size() and capacity() to see when the buffer grows and how many
// elements it had to copy. Do not compute the answers from the growth formula
// alone.
GrowthStats measure_growth(double factor, std::size_t n) {
    double saved_factor = Vector<int>::growth_factor;
    Vector<int>::growth_factor = factor;

    GrowthStats stats;
    Vector<int> v;

    for (std::size_t i = 0; i < n; ++i) {
        std::size_t cap_before = v.capacity();
        std::size_t size_before = v.size();
        v.push_back(0);
        if (v.capacity() > cap_before) {
            stats.reallocations++;
            stats.elements_copied += size_before;
        }
    }

    stats.final_capacity = v.capacity();
    Vector<int>::growth_factor = saved_factor;

    return stats;
}