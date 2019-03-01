find_package (Threads)

if (NOT DEFINED NTHREADS)
  if (WIN32)
    set(NTHREADS 8)
  endif()
  if(UNIX)
    execute_process(COMMAND nproc OUTPUT_VARIABLE NTHREADS)
  endif()
endif(NOT DEFINED NTHREADS)

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/parallel_distance.h.in"
  "${CMAKE_CURRENT_SOURCE_DIR}/parallel_distance.h"
  )

add_library (${PROJECT_NAME} parallel_distance.c kmeans.c)

target_link_libraries(${PROJECT_NAME} m ${CMAKE_THREAD_LIBS_INIT})
