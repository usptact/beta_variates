cmake_minimum_required(VERSION 2.8.12)

project(libbeta C)

find_library(MATH_LIBRARY m)

add_executable(sample_hist sample_hist.c libbeta.h)
target_link_libraries(sample_hist PUBLIC ${MATH_LIBRARY})

add_executable(sample_stream sample_stream.c libbeta.h)
target_link_libraries(sample_stream PUBLIC ${MATH_LIBRARY})
