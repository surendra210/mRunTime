#include "measure.hpp"
#include "iostream"
#include <chrono>

runtime::measurement::GrossRtval_t::GrossRtval_t()
{                                                                                                                                                     

}
unsigned int runtime::measurement::GrossRtval_t::MeasureStart(timecapsules tc)
{                                                                                                                                                     
    uint64_t usec_u64 = 0;                                                      
    static auto start=0,finish=0;
    
    #if QNX
        /* Gross-runtime */
        cycle_u64 = ClockCycles();
        usec_u64 = (uint64_t)(cycle_u64 * (double)CP_MS);
    #endif
    
    


     return usec_u64;
}

// std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long int, std::ratio<1, 1000000000> > > runtime::measurement::GrossRtval_t::MeasureStart()
// {                                                                                                                                                     

//     auto usec = std::chrono::steady_clock::now();

    
//     return usec;
// }
unsigned int runtime::measurement::GrossRtval_t::MeasureEnd()
{



}