cmake_minimum_required(VERSION 2.8.12)

project(libbeta C)

add_executable(sample_hist sample_hist.c libbeta.h)
add_executable(sample_stream sample_stream.c libbeta.h)