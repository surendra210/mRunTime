/*
Author      : K V V Surendra
Description : Runtime measurement utility
*/

#include "iostream"
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/creation_tags.hpp>

using namespace std;

typedef enum timecapsules
{
  timecapsules1,
  timecapsules2,
  timecapsules3,
  timecapsules4,
  timecapsules5,
  timecapsules6,
  timecapsules7,
  timecapsules8,
  timecapsules9,
  timecapsules10,
  timecapsules11,
  timecapsules12,
  timecapsules13,
  timecapsules14,
  timecapsules15,
  timecapsules16,
  timecapsules17,
  timecapsules18,
  timecapsules19,
  timecapsules20,
  MAX_NUM_TIME_CAPSULES
} timecapsules;

typedef struct mRuntime_t
{
  unsigned int start;
  unsigned int end;
  unsigned int StartMeasure;
  timecapsules tcval;
};
unsigned int START   = 0;
unsigned int STARTED = 1;
namespace runtime
{
  namespace measurement
  {
    template <typename MeasureType>
    class measure : public MeasureType
    {
    public:
      //Constructor
      measure();

    public:
      //User Interfaces

      int shmcfg();
      int MeasureStart(unsigned int typeofMeasurement, std::string MeasurementName);
      int MeasureEnd(unsigned int typeofMeasurement, std::string MeasurementName);

      int MonitorForValStart(unsigned int typeofMonMeasurement, std::string MonMeasurementName);
      int MonitorForValEnd(unsigned int typeofMonMeasurement, std::string MonMeasurementName);

    private:
      MeasureType rtval;

    protected:
    };
    class SharedMemory
    {
      static SharedMemory *Instance;

    public:
      //User Interfaces
      void *GetMemoryPtr();
      void *getInstance()
      {
        if (!Instance)
          Instance = new SharedMemory();
        return Instance;
      }

    private:
      void *ptr;

    protected:
      //Constructor
      SharedMemory();
    };

    class RtvalGeneric_t
    {

    public:
      //User Interfaces
      RtvalGeneric_t();
      virtual unsigned int MeasureStart();
      virtual unsigned int MeasureEnd();
      virtual unsigned int Measure(timecapsules);
      int MonitorForValStart();
      int MonitorForValEnd();

    private:
      unsigned long start;
      unsigned long end;
      unsigned long CRt;
      unsigned long MaxRt;
      unsigned long MinRt;
      unsigned long AvgRt;
    };

    class GrossRtval_t : public RtvalGeneric_t, public SharedMemory
    {
    public:
      //User Interfaces
      GrossRtval_t();
      unsigned int MeasureStart(timecapsules tc);
      unsigned int Measure(timecapsules tc);
      unsigned int MeasureEnd();

    private:
    };
    class NetRtval_t : public RtvalGeneric_t
    {

    public:
      //User Interfaces
      NetRtval_t();
      unsigned int MeasureStart();
      unsigned int MeasureEnd();

    private:
    };
    class rtval_t : public RtvalGeneric_t
    {
    public:
      //User Interfaces
      rtval_t();
      GrossRtval_t Gross;
      NetRtval_t Net;
    };
  } // namespace measurement

  namespace configuration
  {
    class cfg
    {
    public:
    private:
    protected:
    };

  } // namespace configuration

} // namespace runtime
