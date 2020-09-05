#include "measure.hpp"

runtime::measurement::SharedMemory *runtime::measurement::SharedMemory::Instance=0;

runtime::measurement::SharedMemory::SharedMemory()
{
      //Create a shared memory object for Gross Measurements.
      boost::interprocess::shared_memory_object shmGross(boost::interprocess::create_only, "GroosRTMShM", boost::interprocess::read_write);

      //Set size
      shmGross.truncate(100*sizeof(mRuntimeGross_t));

      //Map the whole shared memory in this process
      boost::interprocess::mapped_region regionGross(shmGross, boost::interprocess::read_write);
      
      ptrGross = regionGross.get_address();

      //Create a shared memory object for Net Measurements.
      boost::interprocess::shared_memory_object shmNet(boost::interprocess::create_only, "NetRTMShM", boost::interprocess::read_write);

      //Set size
      shmNet.truncate(100*sizeof(mRuntimeNet_t));

      //Map the whole shared memory in this process
      boost::interprocess::mapped_region regionNet(shmNet, boost::interprocess::read_write);
      
      ptrNet = regionNet.get_address();
}
void* runtime::measurement::SharedMemory::GetMemoryPtrGross()
{return ptrGross;}
void* runtime::measurement::SharedMemory::GetMemoryPtrNet()
{return ptrNet;}
