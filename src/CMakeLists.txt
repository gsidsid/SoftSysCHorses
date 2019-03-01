find_package (Threads)

if (NOT DEFINED NTHREADS)
  set (NTHREADS 8)
endif(NOT DEFINED NTHREADS)

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/parallel_distance.h.in"
  "${CMAKE_CURRENT_SOURCE_DIR}/parallel_distance.h"
  )

add_library (${PROJECT_NAME} parallel_distance.c)

target_link_libraries(${PROJECT_NAME} m ${CMAKE_THREAD_LIBS_INIT})
