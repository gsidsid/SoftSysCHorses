# (Sreekanth S., Kawin N., Siddharth G.) C-Horses: Accelerated K-Means

## Goals

C is a language that is very performant.
When we think performance, we think of parallel processing.
The automatic parallelization via a compiler is still a pipe dream, so us programmers must be able to effectively use parallelization.
Therefore, we seek to implement the K-means clustering algorithm, but this time computing the euclidean distances in parallel.

We are confident that we can create a function which takes an array of points as well as a buffer for an array of arrays to populate with clusters.
A stretch goal, then, would be creating a visualizer using GTK.
Another stretch goal is to use GPU acceleration, such as CUDA or OpenCL.

## Learning Goals
In this project, we would like to learn:

- Implementing classic algorithms in C
- Parallelization in C
- CUDA (stretch)
- GTK (stretch)

## Resources to get started
- pthread tutorials, such as this: https://timmurphy.org/2010/05/04/pthreads-in-c-a-minimal-working-example/
- The Wikipedia page for k-means
- Parallel and Concurrent Programming in Haskell has a Haskell implementation which can be compared to performance-wise.

## First Steps

### Implementing a single-threaded K-means
This involves getting the algorithm down in code.
Since he comprehends by doing, he will learn about the algorithm in this way first

### Learning Multithreading in C
Since Sreekanth wants to learn about multithreading off the bat, he will implement a function which in parallel computes the distance of an array of points from the origin.

### Looking into GPU based implementation
Since Sid is the only one with a working C dev environment on Windows and NVIDIA drivers do not work on linux on school computers unless you want to sacrafice suspend to disk, he will work on taking an array of points and using GPU parallelization to compute vector lengths.
