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

unsigned int runtime::measurement::GrossRtval_t::MeasureEnd()
{



}

unsigned int runtime::measurement::GrossRtval_t::Measure(timecapsules tc)
{
     mRuntime_t *MeasurementCapsule= (static_cast<mRuntime_t*>(this->GetMemoryPtr())) + static_cast<unsigned int >(tc);

     if (MeasurementCapsule->StartMeasure == START)
     { 
         MeasurementCapsule->StartMeasure == STARTED;
     }
     else if ( MeasurementCapsule->StartMeasure == STARTED)
     {
        MeasurementCapsule->StartMeasure == START;
     }
     
}