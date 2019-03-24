find_package(Threads)

if(NOT DEFINED NTHREADS)
  if(WIN32)
    set(NTHREADS 8)
  endif()
  if(UNIX)
    execute_process(COMMAND nproc OUTPUT_VARIABLE NTHREADS)
  endif()
endif(NOT DEFINED NTHREADS)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/random_clusters.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/parallel_distance.h.in"
  "${CMAKE_CURRENT_SOURCE_DIR}/parallel_distance.h"
  )

add_library(${PROJECT_NAME} point.c parallel_distance.c kmeans.c)
add_executable(time_random_c time_kmeans.c)

target_link_libraries(${PROJECT_NAME} m ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(time_random_c ${PROJECT_NAME})
