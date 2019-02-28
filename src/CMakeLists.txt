find_package (Threads)
add_library (${PROJECT_NAME} parallel_distance.c)

target_link_libraries(${PROJECT_NAME} m ${CMAKE_THREAD_LIBS_INIT})
