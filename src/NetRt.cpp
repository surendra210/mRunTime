#include "measure.hpp"

runtime::measurement::NetRtval_t::NetRtval_t()
{


}
unsigned int runtime::measurement::NetRtval_t::MeasureStart()
{


}
unsigned int runtime::measurement::NetRtval_t::MeasureEnd()
{



}

unsigned int runtime::measurement::NetRtval_t::MeasureNet(timecapsules tc)
{
    mRuntimeNet_t *MeasurementCapsule = (static_cast<mRuntimeNet_t *>(this->GetMemoryPtrNet())) + static_cast<unsigned int>(tc);

    if (MeasurementCapsule->StartMeasure == START)
    {
        MeasurementCapsule->StartMeasure == STARTED;
//        MeasurementCapsule->start = 
    }
    else if (MeasurementCapsule->StartMeasure == STARTED)
    {
//        MeasurementCapsule->start = std::chrono::steady_clock::now();
//        MeasurementCapsule->end 

        MeasurementCapsule->GrossRuntime = MeasurementCapsule->start - MeasurementCapsule->start;
    }


}