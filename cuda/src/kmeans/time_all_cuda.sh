#!/bin/bash
make
echo "KMEANS - DEVICE"
./kmeans_device
echo "KMEANS - HOST- NVCC"
./kmeans_host_nvcc
make clean
