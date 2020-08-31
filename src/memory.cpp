#include "measure.hpp"

runtime::measurement::SharedMemory *runtime::measurement::SharedMemory::Instance=0;

runtime::measurement::SharedMemory::SharedMemory()
{
      //Create a shared memory object.
      boost::interprocess::shared_memory_object shm(boost::interprocess::create_only, "MySharedMemory", boost::interprocess::read_write);

      //Set size
      shm.truncate(1000);

      //Map the whole shared memory in this process
      boost::interprocess::mapped_region region(shm, boost::interprocess::read_write);
      
      ptr = region.get_address();
}
// void* runtime::measurement::SharedMemory::GetMemoryPtr()
// {return ptr;}
// runtime::measurement::SharedMemory* runtime::measurement::SharedMemory::getInstance() 
// {
//       if (!Instance)
//       Instance = new runtime::measurement::SharedMemory;
//       return Instance;
// }