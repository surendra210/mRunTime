#include "measure.hpp"
#include "iostream"
#include <chrono>

runtime::measurement::GrossRtval_t::GrossRtval_t()
{
}
unsigned int runtime::measurement::GrossRtval_t::MeasureStart(timecapsules tc)
{
    uint64_t usec_u64 = 0;
    static auto start = 0, finish = 0;

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

std::chrono::duration<uint64_t, nano> runtime::measurement::GrossRtval_t::MeasureGross(timecapsules tc)
{
    mRuntimeGross_t *MeasurementCapsule = (static_cast<mRuntimeGross_t *>(this->GetMemoryPtrGross())) + static_cast<unsigned int>(tc);

    if (MeasurementCapsule->StartMeasure == START)
    {
        MeasurementCapsule->StartMeasure == STARTED;
        MeasurementCapsule->start = std::chrono::steady_clock::now();
    }
    else if (MeasurementCapsule->StartMeasure == STARTED)
    {
        MeasurementCapsule->start = std::chrono::steady_clock::now();
        MeasurementCapsule->end = std::chrono::steady_clock::now();

        MeasurementCapsule->GrossRuntime = MeasurementCapsule->start - MeasurementCapsule->start;
    }
}