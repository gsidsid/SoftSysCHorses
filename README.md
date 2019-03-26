# SoftSysCHorses
[![Build Status](https://travis-ci.org/gsidsid/SoftSysCHorses.svg?branch=master)](https://travis-ci.org/gsidsid/SoftSysCHorses)

We are ~~sea~~ C horses.

# Instructions (CPU)

1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`
5. To run, `./main`
6. To run unit tests, `ctest`
7. To visualize the output of our dataset, `cd src`
8. and then `./time_rand.c` to time and generate the clusters.
9. Run `./plot_results.py` to visualize the results
10. To use single threaded mode, set the `SINGLE_THREADED` as a makeopt.

# Instructions (GPU)

1. Ensure you have docker-ce installed
2. Have a GPU with NVIDIA drivers
3. Setup the nvidia-docker2 runtime
4. Register the nvidia runtime with docker
5. `cd cuda`
6. `sudo sh time_cuda_kmeans.sh`
