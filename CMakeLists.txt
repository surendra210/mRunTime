set(Boost_INCLUDE_DIR /usr/include/)
set(Boost_LIBRARY_DIR /usr/lib/x86_64-linux-gnu)

find_package(Boost 1.56 REQUIRED COMPONENTS
                date_time filesystem iostreams)


include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

set(RTMEASURE_SRC src/measure.cpp)
add_library(rtmeasure src/measure.cpp 
                      src/NetRt.cpp
                      src/memory.cpp
                      src/RtValGeneric.cpp
                      src/GrossRt.cpp
                      )
target_link_libraries(rtmeasure ${Boost_LIBRARIES})

install(TARGETS rtmeasure DESTINATION src/)