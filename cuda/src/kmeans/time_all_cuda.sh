#!/bin/bash
make
./kmeans_device
./kmeans_host
./kmeans_host_nvcc
make clean
